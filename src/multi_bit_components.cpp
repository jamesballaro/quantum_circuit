#include "multi_bit_components.h"

void cnot::set_operator()
{
  std::vector<std::complex<double>> cnot_data = {{1, 0},{0, 0},{0, 0},{0, 0},
                                                {0, 0},{1, 0},{0, 0},{0, 0},
                                                {0, 0},{0, 0},{0, 0},{1, 0},
                                                {0, 0},{0, 0},{1, 0},{0, 0}};
  qoperator.set_data(cnot_data);
}
std::string cnot::get_symbol()
{
   return "[CX]";
}
std::string cnot::get_name()
{
	return "CNOT";
}
void cnot::get_info()
{
	std::cout<<"CNOT Matrix Representation:"<<std::endl;
	std::cout<<qoperator;
  std::cout<<"CNOT Gate Symbol: [CX]"<<std::endl;
  std::cout<<"On circuit: "<<std::endl;
  std::cout<<"  ⊕"<<std::endl<<"  |"<<std::endl<<"  •"<<std::endl;
  std::cout<<std::endl;
  std::cout<<"Gate information:"<<std::endl;
	std::cout<<"CNOT: The controlled NOT gate (also CX or CNOT), controlled-X gate is a quantum logic gate that is an essential component in the" 
						" construction of a gate-based quantum computer. It can be used to entangle and disentangle Bell states." 
						"Any quantum circuit can be simulated to an arbitrary degree of accuracy using a combination of CNOT" 
						" gates and single qubit rotations. The gate is sometimes named after Richard Feynman who developed" 
						" an early notation for quantum gate diagrams in 1986."<<std::endl;
}
void control_cnot::set_operator()
{
  std::vector<std::complex<double>> control_data = {{1, 0}};
  qoperator.set_data(control_data); 
}
std::string control_cnot::get_symbol()
{
  return "•";
}
void target_cnot::set_operator()
{
  std::vector<std::complex<double>> target_data = {{1, 0},{0, 0},{0, 0},{0, 0},
																												{0, 0},{0, 0},{0, 0},{1, 0},
																												{0, 0},{0, 0},{1, 0},{0, 0},
																												{0, 0},{1, 0},{0, 0},{0, 0}};
  qoperator.set_data(target_data);
}
std::string target_cnot::get_symbol()
{
  return "⊕";
}
void target_flip_cnot::set_operator()
{
  std::vector<std::complex<double>> target_flip_data = {{1, 0},{0, 0},{0, 0},{0, 0},
																									{0, 0},{1, 0},{0, 0},{0, 0},
																									{0, 0},{0, 0},{0, 0},{1, 0},
																									{0, 0},{0, 0},{1, 0},{0, 0}};
  qoperator.set_data(target_flip_data);
}

void cz::set_operator()
{
  std::vector<std::complex<double>> cz_data = {{1, 0},{0, 0},{0, 0},{0, 0},
                                              	{0, 0},{1, 0},{0, 0},{0, 0},
                                                {0, 0},{0, 0},{1, 0},{0, 0},
                                                {0, 0},{0, 0},{0, 0},{-1, 0}};
  qoperator.set_data(cz_data);
}
std::string cz::get_symbol()
{
   return "[CZ]";
}
std::string cz::get_name()
{
	return "CZ";
}
void cz::get_info()
{
	std::cout<<"Controlled-Z (CZ) Matrix Representation:"<<std::endl;
	std::cout<<qoperator;
  std::cout<<"CZ Gate Symbol: [CZ]"<<std::endl;
  std::cout<<"On circuit: "<<std::endl;
  std::cout<<"  ■"<<std::endl<<"  |"<<std::endl<<"  ■"<<std::endl;
  std::cout<<std::endl;
	std::cout<<"Gate information:"<<std::endl;
  std::cout<<std::endl;
	std::cout<<"CZ: In the computational basis, this gate flips the phase of the target qubit if the control qubit is in the state."<<std::endl;
}
void control_cz::set_operator()
{
  std::vector<std::complex<double>> control_data = {{1, 0}};
  qoperator.set_data(control_data); 
}
std::string control_cz::get_symbol()
{
  return "■";
}
void target_cz::set_operator()
{
  std::vector<std::complex<double>> target_data = {{1, 0},{0, 0},{0, 0},{0, 0},
                                                {0, 0},{1, 0},{0, 0},{0, 0},
                                                {0, 0},{0, 0},{1, 0},{0, 0},
                                                {0, 0},{0, 0},{0, 0},{-1, 0}};
  qoperator.set_data(target_data);
}
std::string target_cz::get_symbol()
{
  return "■";
}

void swap::set_operator()
{
  std::vector<std::complex<double>> swap_data = {{1, 0},{0, 0},{0, 0},{0, 0},
                                                {0, 0},{1, 0},{0, 0},{0, 0},
                                                {0, 0},{0, 0},{1, 0},{0, 0},
                                                {0, 0},{0, 0},{0, 0},{-1, 0}};
  qoperator.set_data(swap_data);
}
std::string swap::get_symbol()
{
   return "SWAP";
}
std::string swap::get_name()
{
	return "SWAP";
}
void swap::get_info()
{
	std::cout<<"SWAP Matrix Representation:"<<std::endl;
	std::cout<<qoperator;
  std::cout<<"SWAP gate on circuit: "<<std::endl;
  std::cout<<"  x"<<std::endl<<"  |"<<std::endl<<"  x"<<std::endl;
  std::cout<<std::endl;
	std::cout<<"Gate information:"<<std::endl;
	std::cout<<"SWAP: The swap gate swaps the states of the 2 qbits that it is acting on."<<std::endl;
}
void control_swap::set_operator()
{
  std::vector<std::complex<double>> control_data = {{1, 0}};
  qoperator.set_data(control_data); 
}
std::string control_swap::get_symbol()
{
  return "x";
}
void target_swap::set_operator()
{
  std::vector<std::complex<double>> target_data = {{1, 0},{0, 0},{0, 0},{0, 0},
																									{0, 0},{1, 0},{0, 0},{0, 0},
																									{0, 0},{0, 0},{1, 0},{0, 0},
																									{0, 0},{0, 0},{0, 0},{-1, 0}};
  qoperator.set_data(target_data);
}
std::string target_swap::get_symbol()
{
  return "x";
}

void ccx::set_operator()
{
  std::vector<std::complex<double>> ccx_data = {{1, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},
                                                {0, 0},{1, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},
                                                {0, 0},{0, 0},{1, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},
                                                {0, 0},{0, 0},{0, 0},{1, 0},{0, 0},{0, 0},{0, 0},{0, 0},
                                                {0, 0},{0, 0},{0, 0},{0, 0},{1, 0},{0, 0},{0, 0},{0, 0},
                                                {0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{1, 0},{0, 0},{0, 0},
                                                {0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{1, 0},
																								{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{1, 0},{0, 0}};
                                                
  qoperator.set_data(ccx_data);
}
std::string ccx::get_symbol()
{
   return "[CCX]";
}
std::string ccx::get_name()
{
	return "CCX";
}
void ccx::get_info()
{
	std::cout<<"CCX/Toffoli Matrix Representation:"<<std::endl;
	std::cout<<qoperator;
  std::cout<<"CCX Gate Symbol: [CCX]"<<std::endl;
  std::cout<<"On circuit: "<<std::endl;
  std::cout<<"  ⊕"<<std::endl<<"  |"<<std::endl<<"  •"<<std::endl<<"  |"<<std::endl<<"  •";
  std::cout<<std::endl;
	std::cout<<"Gate information:"<<std::endl;
	std::cout<<"CCX/Toffoli: The Toffoli gate, named after Tommaso Toffoli and also called the CCNOT gate or Deutsch gate " 
 							"is a 3-bit gate which is universal for classical computation but not for quantum computation. The quantum" 
							" Toffoli gate is the same gate, defined for 3 qubits. It is an example of a CC-U (controlled-controlled Unitary)" 
							" gate. Since it is the quantum analog of a classical gate, it is completely specified by its truth table." 
							" The Toffoli gate is universal when combined with the single qubit Hadamard gate."<<std::endl;
}
void control_ccx::set_operator()
{
  std::vector<std::complex<double>> control_data = {{1, 0}};
  qoperator.set_data(control_data); 
}
std::string control_ccx::get_symbol()
{
  return "•";
}
void target_ccx::set_operator()
{
  std::vector<std::complex<double>> target_ccx_data = {{1, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},
																															{0, 0},{1, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},
																															{0, 0},{0, 0},{1, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},
																															{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{1, 0},
																															{0, 0},{0, 0},{0, 0},{0, 0},{1, 0},{0, 0},{0, 0},{0, 0},
																															{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{1, 0},{0, 0},{0, 0},
																															{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{1, 0},{1, 0},
																															{0, 0},{0, 0},{0, 0},{1, 0},{0, 0},{0, 0},{1, 0},{0, 0}};
  qoperator.set_data(target_ccx_data);
}
std::string target_ccx::get_symbol()
{
  return "⊕";
}
void target_flip_ccx::set_operator()
{
  std::vector<std::complex<double>> target_flip_ccx_data = {{1, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},
																												{0, 0},{1, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},
																												{0, 0},{0, 0},{1, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},
																												{0, 0},{0, 0},{0, 0},{1, 0},{0, 0},{0, 0},{0, 0},{0, 0},
																												{0, 0},{0, 0},{0, 0},{0, 0},{1, 0},{0, 0},{0, 0},{0, 0},
																												{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{1, 0},{0, 0},{0, 0},
																												{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{1, 0},
																												{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{1, 0},{0, 0}};
  qoperator.set_data(target_flip_ccx_data);
}
