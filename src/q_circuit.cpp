#include "q_circuit.h"
#include <algorithm>
#include <sstream>
#include <chrono>
#include <thread>
#include <algorithm>

std::vector<std::shared_ptr<q_circuit>> q_circuit::saved_circuits;

std::string q_circuit::debug_circuit()
{
    std::string debug_message;
    std::string maxgates{std::to_string(this->get_maxgates())};
    std::string nbits{std::to_string(this->get_nbits())};
    debug_message = "maxgates:" + maxgates + "    nbits:" + nbits ;
    for(int i{0}; i<this->get_nbits(); i++){
        for(int j{0}; j<this->get_maxgates(); j++){
            auto compt = this->get_components_vector()[i][j];
            try{
                if(!compt){
                        std::string error;
                        error = "Empty circuit component encountered at ["+std::to_string(i)+"]["+std::to_string(j)+"]"; 
                        throw std::runtime_error(error);
                    }
                else{    
                    std::string type{compt->get_type()};
                    debug_message += "  Circuit element at [" + std::to_string(i) + "]" +   "[" + std::to_string(j) + "]: " + type +"|";
                }
            }
            catch(std::exception& e){
                debug_message+= e.what();
            }
        }
    }
    return debug_message;
}

q_circuit& q_circuit::operator=(const q_circuit &other) {
    if (this == &other) {
        return *this;
    }

    this->total_bits = other.total_bits;
    this->components_vector = other.components_vector;
    this->num_qubits = other.num_qubits;
    return *this;
}

int q_circuit::get_maxgates()
{
    size_t max_gates = toolbox::longest_element(components_vector);
    return static_cast<int>(max_gates);
}

component_matrix q_circuit::get_components_vector()
{   
    if(components_vector.empty()){
        throw std::runtime_error("Empty Component Matrix");
    }
    return components_vector;
}

void q_circuit::add_gate(std::string gate_type, std::vector<int> bits, int time)
{   
    try{
        std::shared_ptr<component> gate = library::string_to_ptr(gate_type);
        if (gate == nullptr) {
            std::string error_msg;
            error_msg = "Error: Search for '" + gate_type + "' resulted in nullptr.";
            throw std::runtime_error(error_msg);
        }
        if (bits.empty()){
            throw std::runtime_error("Error: Empty bit selection");
        }
        int gate_range {gate->get_range()};
        if (static_cast<int>(bits.size()>gate_range)){
            throw std::out_of_range("Error: Wrong number of qbits.");
        }
        if (gate_range > num_qubits) {
            throw std::out_of_range("Error: Gate too big for circuit.");
        }
        if (std::any_of(bits.begin(), bits.end(), [&](int bit) {
            return bit < 0 || bit >= static_cast<int>(components_vector.size());
        })) {
            throw std::out_of_range("Error: Bit index is out of valid range.");
        }
        if (std::any_of(bits.begin(),bits.end(), [&](int bit){
            return components_vector[bit].empty();
        })){
            throw std::runtime_error("Error: Attempted to access an empty component vector");
        }
        if (std::any_of(bits.begin(),bits.end(), [&](int bit){
            return components_vector[bit].back()->get_type() != "Identity";
        })){
            for (int i = 0; i < num_qubits; ++i) {
                if (std::find(bits.begin(), bits.end(), i) != bits.end()) {
                    components_vector[i].emplace_back(std::make_shared<circuit_element>(gate,bits));  
                    continue;
                }
                try {
                    components_vector[i].emplace_back(std::make_shared<circuit_element>(std::make_shared<identity>(),std::vector<int>{i}));
                } catch (const std::bad_alloc& e) {
                    throw std::runtime_error("Memory allocation failed for identity component: " + std::string(e.what()));
                }
            }
        }
        else {
            size_t pos{0};
            for (const auto& bit : bits) {
                pos = std::max(pos, toolbox::last_gate(components_vector[bit]));
            }
            for (int i = 0; i < num_qubits; ++i) {
                if (std::find(bits.begin(), bits.end(), i) != bits.end()) {
                    components_vector[i][pos] = std::make_shared<circuit_element>(gate,bits);  
                }
                try {
                    components_vector[i][pos] = (std::make_shared<circuit_element>(std::make_shared<identity>(),std::vector<int>{i}));
                } catch (const std::bad_alloc& e) {
                    throw std::runtime_error("Memory allocation failed for identity component: " + std::string(e.what()));
                }
            }
        }
    }    
    catch (const std::exception& e) {
        std::cerr << "Exception in add_gate: " << e.what() << std::endl;
    }
}

void q_circuit::add_bit_row()
{
    try {
        if (components_vector.empty()) {
            throw std::runtime_error("Error: Adding bit to empty circuit.");
        }
        int last = static_cast<int>(components_vector.size() - 1);
        int bit_index = std::max(last - 1, 0);

        bit_row added_row;
        added_row.resize(static_cast<size_t>(this->get_maxgates()));
        for (auto& element : added_row) {
            element = std::make_shared<circuit_element>(std::make_shared<identity>(), std::vector<int>{bit_index});
        }

        try {
            added_row.front() = std::make_shared<circuit_element>(std::make_shared<qubit>(state), std::vector<int>{bit_index});
        } catch (const std::exception &e) {
            throw std::runtime_error("Memory: " + std::string(e.what()));
        }
        try {
            components_vector.insert(components_vector.begin() + last, added_row);
            this->num_qubits += 1;
            this->total_bits += 1;
        } catch (const std::exception& e) {
            throw std::runtime_error("Error: " + std::string(e.what()));
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Exception in add_bit_row: " << e.what() << std::endl;
    }
}

void q_circuit::remove_bit_row()
{
    try {
        if (components_vector.empty()) {
            throw std::runtime_error("Error: Adding bit to empty circuit.");
        }
        try {
            components_vector.pop_back();
            this->num_qubits -= 1;
            this->total_bits -= 1;
        } catch (const std::exception& e) {
            throw std::runtime_error("Error: " + std::string(e.what()));
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Exception in add_bit_row: " << e.what() << std::endl;
    }
}

void q_circuit::remove_gate(int bit, int time)
{
    size_t longest_row {toolbox::longest_element(components_vector)};

    if (longest_row == 1) {
        throw std::runtime_error("No gates in circuit yet.");
    }
    if (!std::isdigit(bit) || bit < 0 || bit >= static_cast<int>(components_vector.size())) {
        throw std::runtime_error("Invalid qubit index.");
    }
    if (!std::isdigit(time) || time <= 0 || time >= static_cast<int>(components_vector[bit].size())) {
        throw std::runtime_error("Invalid index for removing gate.");
    }
    std::shared_ptr<circuit_element> element = components_vector[bit][time];
    std::string type = element->get_type();

    if (type == "Identity") {
        throw std::runtime_error("No gate to remove at the specified location.");
    }            
    for (int affected_bit : element->get_bits()) {
        if (affected_bit >= 0 && affected_bit < static_cast<int>(components_vector.size())) {
            // Overwrite the same column in all qubits the gate touches
            components_vector[affected_bit][time] = (std::make_shared<circuit_element>(std::make_shared<identity>(),std::vector<int>{affected_bit}));
        }
    }
}

void q_circuit::calculate_circuit_matrix(int gate_pos)
{
    int longest_row {static_cast<int>(toolbox::longest_element(components_vector) - 1)};
    if (longest_row == 0) {
        throw std::out_of_range("Error: No gates in circuit.");
    }
    if (gate_pos <= longest_row) {
        matrix gate_tensor = components_vector[0][gate_pos]->get_operator();
        toolbox::recursive_tensor_product(components_vector, num_qubits, 1, gate_pos, gate_tensor);
        tensor_vector.push_back(gate_tensor);
        gate_pos++;
        calculate_circuit_matrix(gate_pos);
    }
    else if (gate_pos > longest_row) {
        circuit_matrix = tensor_vector[0];
        //Mutliplies the tensor matrices of every gate produce together
        toolbox::recursive_matrix_multiplication(tensor_vector, 1, circuit_matrix);
        //Tensor product of qbit states
        matrix qbit_tensor = components_vector[0][0]->get_operator();
        toolbox::recursive_tensor_product(components_vector, num_qubits, 1, 0, qbit_tensor);
        //qbit tensor matrix mutiplied by circuit matrix
        matrix applied_matrix = circuit_matrix * qbit_tensor;
    }
}

void q_circuit::get_circuit_matrix()
{
    tensor_vector.clear();
    int gate_pos {1};
    try{
        calculate_circuit_matrix(gate_pos); 
    }
    catch(const std::exception& e){
        std::cerr << "Exception in circuit matrix calculation: " << e.what() << std::endl;
    }
    
}

void q_circuit::save()
{
    int longest_row {static_cast<int>(toolbox::longest_element(components_vector) - 1)};
    if (longest_row == 0) {
        throw std::out_of_range("Error: No gates in circuit.");
    }
    else {
        saved_circuits.emplace_back(std::shared_ptr<q_circuit>(this, [](q_circuit*) {}));
    }
}

void q_circuit::load(int idx, std::string choice, int sel)
{
    bool add (choice == "new");
    if (saved_circuits.size() == 0) {
        throw std::out_of_range("Error: No circuits have been saved yet.");
    }
    if (idx < 0 || idx > static_cast<int>(saved_circuits.size())){
        throw std::out_of_range("Error: Circuit selection empty");
    }
    if (add){
        *this = *saved_circuits[idx - 1];
    }
    else {
        std::shared_ptr<q_circuit> circuit = saved_circuits[idx - 1];
        if (this->num_qubits >= circuit->num_qubits) { 
            throw std::out_of_range("Error: Saved circuit incompatible");
            size_t longest_row = toolbox::longest_element(circuit->components_vector);
            std::vector<int> modified;

            if ((this->num_qubits - sel) <= circuit->num_qubits){
                throw std::out_of_range("Error: Not enough space in current circuit to add on that bit");
            }
            for (int l {sel}; l < (sel + circuit->num_qubits); l++) {
                modified.push_back(l);
            }
            for (size_t time {1}; time < longest_row; time++) {
                for (int bit {0}; bit < this->num_qubits; bit++) {
                    auto it = std::find(modified.begin(), modified.end(), bit);
                    if (it == modified.end()) {
                        this->components_vector[bit].emplace_back(std::make_shared<circuit_element>(std::make_shared<identity>(),std::vector<int>{bit}));
                    }
                    else {
                        this->components_vector[bit].emplace_back(circuit->components_vector[bit - sel][time]);
                    }
                }
            }
        } 
    }           
}
