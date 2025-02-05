#include "bits.h"
void qubit::set_qu_operator()
{
    std::vector<std::complex<double>> qubit_data = {{1, 0},{0, 0}};
    try{
        qu_operator.set_data(qubit_data);
    }
        catch (const std::exception& e) {
        std::cerr << "["<<this->get_type()<<"] " << "Exception occurred: " << e.what() << std::endl;
    }  
}
void qubit::set_qu_operator(int choice)
{
    std::vector<std::complex<double>> qubit_data = {{1, 0},{0, 0}};
    if(choice == 2){
        qubit_data = {{0, 0},{1, 0}};
    }
    try{
        qu_operator.set_data(qubit_data);
    }
    catch (const std::exception& e) {
        std::cerr << "["<<this->get_type()<<"] " << "Exception occurred: " << e.what() << std::endl;
    }  
}
std::string qubit::get_symbol()
{
    return "q";
}
std::string qubit::get_type()
{
    return "Qubit";
}
std::string qubit::get_info()
{
    return "Quantum Bit INFO";
}

void cbit::set_qu_operator()
{
    std::vector<std::complex<double>> cbit_data = {{0, 0}};
    try{
        qu_operator.set_data(cbit_data);
    }
    catch (const std::exception& e) {
        std::cerr << "["<<this->get_type()<<"] " << "Exception occurred: " << e.what() << std::endl;
    }  
}
std::string cbit::get_symbol()
{
    return"c";
}
std::string cbit::get_type()
{
    return "ClassicalBit";
}
std::string cbit::get_info()
{
    return "cbit INFO";
}

// std::string control_ccx::get_type()
// {
//     return "ControlCCX";
// }
// void control_ccx::set_qu_operator()
// {
//     std::vector<std::complex<double>> control_data = {{1, 0}};
//     try{
//         qu_operator.set_data(control_data);
//     }
//     catch (const std::exception& e) {
//         std::cerr << "["<<this->get_type()<<"] " << "Exception occurred: " << e.what() << std::endl;
// }  
// }
// std::string control_ccx::get_symbol()
// {
//     return "•";
// }
// std::string control_ccx::get_info()
// {
//     return "INFO";
// }

// void control_swap::set_qu_operator()
// {
//     std::vector<std::complex<double>> control_data = {{1, 0}};
//     try{
//         qu_operator.set_data(control_data);
//     }
//     catch (const std::exception& e) {
//         std::cerr << "["<<this->get_type()<<"] " << "Exception occurred: " << e.what() << std::endl;
//     }  
// }
// std::string control_swap::get_type()
// {
//     return "ControlSwap";
// }
// std::string control_swap::get_symbol()
// {
//     return "x";
// }
// std::string control_swap::get_info()
// {
//     return "INFO";
// }

// void control_cz::set_qu_operator()
// {
//     std::vector<std::complex<double>> control_data = {{1, 0}};
//     try{
//         qu_operator.set_data(control_data);
//     }
//     catch (const std::exception& e) {
//         std::cerr << "["<<this->get_type()<<"] " << "Exception occurred: " << e.what() << std::endl;
//     }   
// }
// std::string control_cz::get_type()
// {
//     return "ControlCZ";
// }
// std::string control_cz::get_symbol()
// {
//     return "■";
// }
// std::string control_cz::get_info()
// {
//     return "INFO";
// }

// void control_cnot::set_qu_operator()
// {
// std::vector<std::complex<double>> control_data = {{1, 0}};
//     try{
//         qu_operator.set_data(control_data);
//     }
//     catch (const std::exception& e) {
//         std::cerr << "["<<this->get_type()<<"] " << "Exception occurred: " << e.what() << std::endl;
//     }  
// }
// std::string control_cnot::get_type()
// {
//     return "ControlCNOT";
// }
// std::string control_cnot::get_symbol()
// {
//     return "•";
// }
// std::string control_cnot::get_info()
// {
//     return "INFO";
// }