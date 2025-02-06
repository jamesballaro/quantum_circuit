#include "multi_bit_gates.h"

void cnot::set_qu_operator()
{
    std::vector<std::complex<double>> cnot_data = {
        {1, 0},{0, 0},{0, 0},{0, 0},
        {0, 0},{1, 0},{0, 0},{0, 0},
        {0, 0},{0, 0},{0, 0},{1, 0},
        {0, 0},{0, 0},{1, 0},{0, 0}};
    try{
        qu_operator.set_data(cnot_data);
    }
    catch (const std::exception& e) {
        std::cerr << "["<<this->get_type()<<"] " << "Exception occurred: " << e.what() << std::endl;
    }
}
std::string cnot::get_symbol()
{
   return "[CX]";
}
std::string cnot::get_type()
{
	return "CNOT";
}
std::string cnot::get_info()
{
	return "CNOT: The controlled NOT gate (also CX or CNOT), controlled-X gate is a quantum logic gate that is an essential component in the construction of a gate-based quantum computer. It can be used to entangle and disentangle Bell states. "
          "Any quantum circuit can be simulated to an arbitrary degree of accuracy using a combination of CNOT"
          "gates and single qubit rotations. The gate is sometimes named after Richard Feynman who developed "
          "an early notation for quantum gate diagrams in 1986.";
}
// void target_cnot::set_qu_operator()
// {
//     std::vector<std::complex<double>> target_data = {
//         {1, 0},{0, 0},{0, 0},{0, 0},
//         {0, 0},{0, 0},{0, 0},{1, 0},
//         {0, 0},{0, 0},{1, 0},{0, 0},
//         {0, 0},{1, 0},{0, 0},{0, 0}};
//     try{
//         qu_operator.set_data(target_data);
//     }
//     catch (const std::exception& e) {
//         std::cerr << "["<<this->get_type()<<"] " << "Exception occurred: " << e.what() << std::endl;
//     }
// }
// std::string target_cnot::get_symbol()
// {
//   return "⊕";
// }
// void target_flip_cnot::set_qu_operator()
// {
//     std::vector<std::complex<double>> target_flip_data = {
//         {1, 0},{0, 0},{0, 0},{0, 0},
//         {0, 0},{1, 0},{0, 0},{0, 0},
//         {0, 0},{0, 0},{0, 0},{1, 0},
//         {0, 0},{0, 0},{1, 0},{0, 0}};
//     try{
//         qu_operator.set_data(target_flip_data);
//     }
//     catch (const std::exception& e) {
//         std::cerr << "["<<this->get_type()<<"] " << "Exception occurred: " << e.what() << std::endl;
//     }
// }

void cz::set_qu_operator()
{
    std::vector<std::complex<double>> cz_data = {
        {1, 0},{0, 0},{0, 0},{0, 0},
        {0, 0},{1, 0},{0, 0},{0, 0},
        {0, 0},{0, 0},{1, 0},{0, 0},
        {0, 0},{0, 0},{0, 0},{-1, 0}};
    try{
        qu_operator.set_data(cz_data);
    }
    catch (const std::exception& e) {
        std::cerr << "["<<this->get_type()<<"] " << "Exception occurred: " << e.what() << std::endl;
    }
}
std::string cz::get_symbol()
{
   return "[CZ]";
}
std::string cz::get_type()
{
	return "CZ";
}
std::string cz::get_info()
{
	return "In the computational basis, this gate flips the phase of the target qubit if the control qubit is in the state.";
}
// void target_cz::set_qu_operator()
// {
//     std::vector<std::complex<double>> target_data = {
//         {1, 0},{0, 0},{0, 0},{0, 0},
//         {0, 0},{1, 0},{0, 0},{0, 0},
//         {0, 0},{0, 0},{1, 0},{0, 0},
//         {0, 0},{0, 0},{0, 0},{-1, 0}};
//     try{
//         qu_operator.set_data(target_data);
//     }
//     catch (const std::exception& e) {
//         std::cerr << "["<<this->get_type()<<"] " << "Exception occurred: " << e.what() << std::endl;
//     }
// }
// std::string target_cz::get_symbol()
// {
//   return "■";
// }

void swap::set_qu_operator()
{
    std::vector<std::complex<double>> swap_data = {
        {1, 0},{0, 0},{0, 0},{0, 0},
        {0, 0},{1, 0},{0, 0},{0, 0},
        {0, 0},{0, 0},{1, 0},{0, 0},
        {0, 0},{0, 0},{0, 0},{-1, 0}};
    try{
        qu_operator.set_data(swap_data);
    }
    catch (const std::exception& e) {
        std::cerr << "["<<this->get_type()<<"] " << "Exception occurred: " << e.what() << std::endl;
    }
}
std::string swap::get_symbol()
{
   return "SWAP";
}
std::string swap::get_type()
{
	return "Swap";
}
std::string swap::get_info()
{
	return "The swap gate swaps the states of the 2 qubits that it is acting on.";
}
// void target_swap::set_qu_operator()
// {
//     std::vector<std::complex<double>> target_data = {
//         {1, 0},{0, 0},{0, 0},{0, 0},
//         {0, 0},{1, 0},{0, 0},{0, 0},
//         {0, 0},{0, 0},{1, 0},{0, 0},
//         {0, 0},{0, 0},{0, 0},{-1, 0}};
//     try{
//         qu_operator.set_data(target_data);
//     }
//     catch (const std::exception& e) {
//         std::cerr << "["<<this->get_type()<<"] " <<"Exception occurred: " << e.what() << std::endl;
//     }
// }
// std::string target_swap::get_symbol()
// {
//   return "x";
// }

void ccx::set_qu_operator()
{
    std::vector<std::complex<double>> ccx_data = {
        {1, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},
        {0, 0},{1, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},
        {0, 0},{0, 0},{1, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},
        {0, 0},{0, 0},{0, 0},{1, 0},{0, 0},{0, 0},{0, 0},{0, 0},
        {0, 0},{0, 0},{0, 0},{0, 0},{1, 0},{0, 0},{0, 0},{0, 0},
        {0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{1, 0},{0, 0},{0, 0},
        {0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{1, 0},
        {0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{1, 0},{0, 0}};
                                                
    try{
        qu_operator.set_data(ccx_data);
    }
    catch (const std::exception& e) {
        std::cerr << "["<<this->get_type()<<"] " << "Exception occurred: " << e.what() << std::endl;
    }
}
std::string ccx::get_symbol()
{
   return "[CCX]";
}
std::string ccx::get_type()
{
	return "Toffoli";
}

std::string ccx::get_info()
{
	return "The Toffoli gate, named after Tommaso Toffoli and also called the CCNOT gate or Deutsch gate " 
 							"is a 3-bit gate which is universal for classical computation but not for quantum computation. The quantum" 
							" Toffoli gate is the same gate, defined for 3 qubits. It is an example of a CC-U (controlled-controlled Unitary)" 
							" gate. Since it is the quantum analog of a classical gate, it is completely specified by its truth table." 
							" The Toffoli gate is universal when combined with the single qubit Hadamard gate.";
}
// void target_ccx::set_qu_operator()
// {
//     std::vector<std::complex<double>> target_ccx_data = {
//         {1, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},
//         {0, 0},{1, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},
//         {0, 0},{0, 0},{1, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},
//         {0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{1, 0},
//         {0, 0},{0, 0},{0, 0},{0, 0},{1, 0},{0, 0},{0, 0},{0, 0},
//         {0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{1, 0},{0, 0},{0, 0},
//         {0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{1, 0},{1, 0},
//         {0, 0},{0, 0},{0, 0},{1, 0},{0, 0},{0, 0},{1, 0},{0, 0}};
//     try{
//         qu_operator.set_data(target_ccx_data);
//     }
//     catch (const std::exception& e) {
//         std::cerr << "["<<this->get_type()<<"] " << "Exception occurred: " << e.what() << std::endl;
//     }}
// std::string target_ccx::get_symbol()
// {
//   return "⊕";
// }
// void target_flip_ccx::set_qu_operator()
// {
//     std::vector<std::complex<double>> target_flip_ccx_data = {
//         {1, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},
//         {0, 0},{1, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},
//         {0, 0},{0, 0},{1, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},
//         {0, 0},{0, 0},{0, 0},{1, 0},{0, 0},{0, 0},{0, 0},{0, 0},
//         {0, 0},{0, 0},{0, 0},{0, 0},{1, 0},{0, 0},{0, 0},{0, 0},
//         {0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{1, 0},{0, 0},{0, 0},
//         {0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{1, 0},
//     {0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{1, 0},{0, 0}};
//     try{
//         qu_operator.set_data(target_flip_ccx_data);
//     }
//     catch (const std::exception& e) {
//         std::cerr << "["<<this->get_type()<<"] " << "Exception occurred: " << e.what() << std::endl;
//     }
// }
