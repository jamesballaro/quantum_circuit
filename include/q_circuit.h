#ifndef Q_CIRCUIT_H
#define Q_CIRCUIT_H

#include "matrix.h"
#include "toolbox.h"
#include "gate_a_base.h"
#include "quantum_component.h"
#include "single_bit_components.h"
#include "multi_bit_components.h"
#include <memory>

class q_circuit
{ 
  private:
  int num_qbits;
	int total_bits;
  component_matrix components_vector;
  matrix circuit_matrix;
  std::vector<matrix> tensor_vector;
	static std::vector<std::shared_ptr<q_circuit>> saved_circuits;
  public:
  q_circuit() : num_qbits{2}{Gate_a_base::library_creator();}
  q_circuit(int q) : num_qbits{q}, total_bits{q+1}{
    components_vector.resize(total_bits);
		for(int i{0}; i < num_qbits; i++){
			components_vector[i].push_back(pair(std::make_shared<qbit>()));
    }
		components_vector[num_qbits].push_back(pair(std::make_shared<cbit>()));
    matrix A(1<<num_qbits,1<<num_qbits);
    circuit_matrix = A;
    Gate_a_base::library_creator();
  }
  ~q_circuit()= default;
  void add_gate();
  void multi_qbit_gate(std::shared_ptr<quantum_comp> gate, int qbit_range, int num_qbits);
  void series_add(std::string gate_choice, std::shared_ptr<quantum_comp> gate);
  void parallel_add(std::shared_ptr<quantum_comp> gate);
	void gate_info();
	void create_circuit();
	void draw_circuit();
  void remove_gate();
  void calculate_circuit_matrix(int gate_pos);
  void get_circuit_matrix();
	void save();
  void load();
  void add_to_circuit(std::shared_ptr<q_circuit> circuit, int circ_no);
	//Pair creator
	circ_element pair(std::vector<int> qbit_choice, std::shared_ptr<quantum_comp> gate);
	circ_element pair(std::shared_ptr<quantum_comp> gate);
};

#endif