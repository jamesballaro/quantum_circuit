#include "single_bit_components.h"

void pauli_X::set_operator()
{
  std::vector<std::complex<double>> pauli_x_data = {{0, 0},{1, 0},{1, 0},{0, 0}};
  qoperator.set_data(pauli_x_data); 
}
std::string pauli_X::get_symbol()
{
  return "[X]";
}
void pauli_X::get_info()
{
	std::cout<<"Pauli X Matrix Representation:"<<std::endl;
	std::cout<<qoperator;
  std::cout<<"Pauli X Gate Symbol: [X]"<<std::endl;
	std::cout<<"Gate information:"<<std::endl;
	std::cout<<"Pauli X: The Pauli gates (X,Y,Z) are the three Pauli matrices and act on a single qubit. The Pauli X, Y and Z equate,"
							"respectively, to a rotation around the x, y and z axes of the Bloch sphere by pi radians. The Pauli-X gate is the quantum"
							" equivalent of the NOT gate for classical computers with respect to the standard basis It is sometimes called a bit-flip "<<std::endl;
}
std::string pauli_X::get_name()
{
	return "Pauli X";
}

void pauli_Y::set_operator()
{
  std::vector<std::complex<double>> pauli_y_data = {{0, 0},{0, -1},{0, 1},{0, 0}};
  qoperator.set_data(pauli_y_data); 
}
std::string pauli_Y::get_symbol()
{
  return "[Y]";
}
void pauli_Y::get_info()
{
	std::cout<<"Pauli Y Matrix Representation:"<<std::endl;
	std::cout<<qoperator;
  std::cout<<"Pauli Y Gate Symbol: [Y]"<<std::endl;
	std::cout<<"Gate information:"<<std::endl;
	std::cout<<"Pauli Y: The Pauli gates (X,Y,Z) are the three Pauli matrices and act on a single qubit. The Pauli X, Y and Z equate,"
							"respectively, to a rotation around the x, y and z axes of the Bloch sphere by pi radians. The Pauli-X gate is the quantum"
							" equivalent of the NOT gate for classical computers with respect to the standard basis It is sometimes called a bit-flip "<<std::endl;
}
std::string pauli_Y::get_name()
{
	return "Pauli Y";
}

void pauli_Z::set_operator()
{
  std::vector<std::complex<double>> pauli_z_data = {{1, 0},{0, 0},{0, 0},{-1, 0}};
  qoperator.set_data(pauli_z_data);
    
}
std::string pauli_Z::get_symbol()
{
  return "[Z]";
}
void pauli_Z::get_info()
{
	std::cout<<"Pauli Z Matrix Representation:"<<std::endl;
	std::cout<<qoperator;
  std::cout<<"Pauli Z Gate Symbol: [Z]"<<std::endl;
	std::cout<<"Gate information:"<<std::endl;
	std::cout<<"Pauli X: The Pauli gates (X,Y,Z) are the three Pauli matrices and act on a single qubit. The Pauli X, Y and Z equate,"
							"respectively, to a rotation around the x, y and z axes of the Bloch sphere by pi radians. The Pauli-X gate is the quantum"
							" equivalent of the NOT gate for classical computers with respect to the standard basis It is sometimes called a bit-flip "<<std::endl;
}
std::string pauli_Z::get_name()
{
	return "Pauli Y";
}

void hadamard::set_operator()
{
  std::vector<std::complex<double>> hadamard_data = {{1/sqrt(2), 0},{1/sqrt(2), 0},{1/sqrt(2), 0},{-1/sqrt(2), 0}};
  qoperator.set_data(hadamard_data);
    
}
std::string hadamard::get_symbol()
{
  return "[H]";
}
void hadamard::get_info()
{
	std::cout<<"Hadamard Matrix Representation:"<<std::endl;
	std::cout<<qoperator;
  std::cout<<"Hadamard Gate Symbol: [H]"<<std::endl;
	std::cout<<"Gate information:"<<std::endl;
	std::cout<<"Hadamard: The Hadamard transform is used extensively in quantum computing. The 2 x 2 Hadamard transform H1 is the quantum logic gate known as the Hadamard gate,"
							" and the application of a Hadamard gate to each qubit of an n-qubit register in parallel is equivalent to the Hadamard transform "
							" H_{n}."<<std::endl;
}
std::string hadamard::get_name()
{
	return "Hadamard";
}

void phase::set_operator()
{
  std::vector<std::complex<double>> phase_data = {{1, 0},{0, 0},{0, 0},{0, 1}};
  qoperator.set_data(phase_data);
    
}
std::string phase::get_symbol()
{
  return "[P]";
}
void phase::get_info()
{
	std::cout<<"Phase Matrix Representation:"<<std::endl;
	std::cout<<qoperator;
  std::cout<<"Phase Gate Symbol: [P]"<<std::endl;
	std::cout<<"Gate information:"<<std::endl;
	std::cout<<"Phase: info"<<std::endl;
}
std::string phase::get_name()
{
	return "Phase";
}

void qbit::set_operator()
{
  std::vector<std::complex<double>> qbit_data = {{1, 0},{0, 0}};
  qoperator.set_data(qbit_data);
}
std::string qbit::get_symbol()
{
  return "q";
}
void qbit::get_info()
{
	std::cout<<"q-bit Matrix Representation:"<<std::endl;
	std::cout<<qoperator;
	std::cout<<"Gate information:"<<std::endl;
	std::cout<<"q-bit: A quantum bit (qbit) is a basic unit of quantum information—the quantum version of the classic binary" 
						"bit physically realized with a two-state device. A qubit is a two-state (or two-level) quantum-mechanical system,"
						 "one of the simplest quantum systems displaying the peculiarity of quantum mechanics.In a classical system, a bit "
						 "would have to be in one state or the other. However, quantum mechanics allows the qubit to be in a coherent" 
						 "superposition of both states simultaneously, a property that is fundamental to quantum mechanics and quantum computing."<<std::endl;
}
std::string qbit::get_name()
{
	return "Quantum Bit";
}

void cbit::set_operator()
{
  std::vector<std::complex<double>> cbit_data = {{0, 0}};
  qoperator.set_data(cbit_data);
}
std::string cbit::get_symbol()
{
  return"c";
}
void cbit::get_info()
{
	std::cout<<"Classical bit information:"<<std::endl;
	std::cout<<"Cbit info"<<std::endl;
}
std::string cbit::get_name()
{
	return "Classical Bit";
}

void identity::set_operator()
{
  std::vector<std::complex<double>> identity_data = {{1, 0},{0, 0},{0, 0},{1, 0}};
  qoperator.set_data(identity_data); 
}
std::string identity::get_symbol()
{
  return "[I]";
}
std::string identity::get_name()
{
	return "Identity";
}
void identity::get_info()
{
	std::cout<<"Identity Gate Matrix Representation:"<<std::endl;
	std::cout<<qoperator;
	std::cout<<"Gate information:"<<std::endl;
	std::cout<<"Identity: where I is basis independent and does not modify the quantum state." 
							"The identity gate is most useful when describing mathematically the result of"
							 "various gate operations or when discussing multi-qubit circuits."<<std::endl;
}
