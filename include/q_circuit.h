#ifndef Q_CIRCUIT_H
#define Q_CIRCUIT_H

#include "matrix.h"
#include "toolbox.h"
#include "library.h"

class q_circuit{ 
private:
    int num_qubits;
    int num_cbits;
    int total_bits;

    int alignment;
    int state;

    component_matrix components_vector;
    matrix circuit_matrix;
    std::vector<matrix> tensor_vector;
    static std::vector<std::shared_ptr<q_circuit>> saved_circuits;

public:
    q_circuit() : num_qubits{2}, num_cbits{1}, total_bits{num_cbits+num_qubits}, state{0}, alignment{0}{
        components_vector.resize(total_bits);
        for(int i{0}; i < num_qubits; i++){
            components_vector[i].emplace_back(std::make_shared<circuit_element>(std::make_shared<qubit>(state),std::vector<int>{i}));
        }
        components_vector[num_qubits].emplace_back(std::make_shared<circuit_element>(std::make_shared<cbit>(), std::vector<int>{num_qubits}));
        matrix A(1<<num_qubits,1<<num_qubits);
        circuit_matrix = A;
        library::library_creator();
    }
    // q_circuit(int q, int s) : num_qubits{q}, total_bits{q+1}, state{s}{
    //     components_vector.resize(total_bits);
    //     for(int i{0}; i < num_qubits; i++){
    //         components_vector[i].push_back(toolbox::pair(std::make_shared<qubit>(state)));
    //     }
    //     components_vector[num_qubits].push_back(toolbox::pair(std::make_shared<cbit>()));
    //     matrix A(1<<num_qubits,1<<num_qubits);
    //     circuit_matrix = A;
    //     library::library_creator();
    // }
    ~q_circuit()= default;
    q_circuit& operator=(const q_circuit &other);

    int get_nbits(){return total_bits-1;}
    std::string debug_circuit();
    int get_maxgates();
    component_matrix get_components_vector();
    static std::vector<std::shared_ptr<q_circuit>> get_saved_circuits();
    // matrix get_qbit_state();

    void add_gate(std::string gate, std::vector<int> bits, int time);
    void add_bit_row();
    void remove_bit_row();
    // void series_add(std::string gate_type, std::shared_ptr<component> gate, int range,std::vector<int> bits, int time);
    // void parallel_add(std::shared_ptr<component> gate);
    void gate_info();
    // void create_circuit();
    // void draw_circuit();
    void remove_gate(int bit, int time);
    void calculate_circuit_matrix(int gate_pos);
    void get_circuit_matrix();
    void save();
    void load(int idx, std::string add, int sel);
};

#endif