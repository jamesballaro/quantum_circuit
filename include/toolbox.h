#ifndef TOOLBOX_H
#define TOOLBOX_H

#include "matrix.h"
#include "quantum_component.h"
#include "single_bit_components.h"
#include "multi_bit_components.h"
#include <memory>


using circ_element = std::pair<std::vector<int>,std::shared_ptr<quantum_comp>>;
using bit_row = std::vector<circ_element>;
using component_matrix = std::vector<bit_row>;

namespace toolbox{
    //Convert to uppercase
    std::string to_upper(std::string& string);
    //Verify integer input
    int int_verifier(const std::string& integer);
    //Extract qbit selection for single and multiple qbits
    int extract_number(const std::string& input);
    std::vector<int> extract_number(const std::string& input, int num_qbits);
    //Longest element in a given vector containing any type
    template<typename T>
    size_t longest_element(const std::vector<std::vector<T>>& vector);
	//Last element in vector that is a gate (not identity)
	size_t last_gate(bit_row components);

    //Circuit matrix tools:
    //Recursive tensor product (for a column of gates in parallel)
    void recursive_tensor_product(const component_matrix& components_vector, int num_qbits, int bit_position, int gate_position, matrix& gate_tensor);
    //Recursive matrix multiplication (for a series of tensor products (gates in series))
    void recursive_matrix_multiplication(std::vector<matrix>& tensor_vector, size_t index, matrix& matrix_product);
}

template<typename T>
size_t toolbox::longest_element(const std::vector<std::vector<T>>& vector) 
{
  size_t maxLength{0};
  for(const auto& innerVec : vector){
    if(innerVec.size() > maxLength){
      maxLength = innerVec.size();
    }
  }
  return maxLength;
}

#endif