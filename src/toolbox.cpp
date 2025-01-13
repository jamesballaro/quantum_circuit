#include "toolbox.h"
#include <algorithm>
#include <regex>
#include <unordered_set>

std::string toolbox::to_upper(std::string& lower)
{
  std::transform(lower.begin(), lower.end(), lower.begin(),
                  [](unsigned char c){return std::toupper(c);
								});
  return lower;
}

int toolbox::int_verifier(const std::string& integer)
{
  for (char c : integer) {
    if (!std::isdigit(c)) {
      return -1;
    }
  }
  return std::stoi(integer);
}

int toolbox::extract_number(const std::string& input)
{
  std::regex pattern("^(q|c)\\d+$");
  std::smatch match;
  int selection;
  if (std::regex_search(input, match, pattern)){
    std::string matched = match.str(0);
    selection = std::stoi(matched.substr(1));
  } 
	else {
    selection = -1;
  }
  return selection;
}

std::vector<int> toolbox::extract_number(const std::string& input, int num_qbits)
{
  std::vector<int> selections;
  selections.reserve(num_qbits);
  std::stringstream ss(input);
  while(ss.good()){
    std::string substring;
    getline(ss, substring, ',' );
    int element_int{toolbox::extract_number(substring)};
    if(element_int == -1){
      selections[0] = -1;
    }
    if(element_int >= num_qbits){
      selections[0] = -2;
    }
    else{
      selections.push_back(element_int);
    }
  }
	if(std::unordered_set<int>{selections.begin(), selections.end()}.size() < selections.size()){
    selections[0] = -1;
	}
  return selections;
}

size_t toolbox::last_gate(bit_row components)
{
	auto it = std::find_if(components.rbegin(),components.rend(), 
													[](const circ_element& ptr){
													return ptr.second->get_symbol() != "[I]";
												});
	size_t position = components.rend() -it;
	return position;
}

void toolbox::recursive_tensor_product(const component_matrix& components_vector, int num_qbits, int bit_position, int gate_position, matrix& gate_tensor)
{
  if(bit_position >= num_qbits){
    return;
  }
  matrix gate_matrix(components_vector[bit_position][gate_position].second->get_matrix());
  gate_tensor = gate_tensor.tensor_product(gate_matrix);
  recursive_tensor_product(components_vector, num_qbits, bit_position+1, gate_position, gate_tensor);
}
void toolbox::recursive_matrix_multiplication(std::vector<matrix>& tensor_vector, size_t index, matrix& matrix_product)
{
  if(index >= tensor_vector.size()){
    return;
  }
  matrix_product = tensor_vector[index]*matrix_product;
  recursive_matrix_multiplication(tensor_vector, index+1, matrix_product);
}
