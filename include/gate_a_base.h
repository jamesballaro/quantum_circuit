#ifndef GATE_A_BASE_H
#define GATE_A_BASE_H

#include <map>
#include <memory>
#include "quantum_component.h"
#include "single_bit_components.h"
#include "multi_bit_components.h"

namespace Gate_a_base{
	//Library of all possible gates to add:
  typedef std::map<std::string,std::shared_ptr<quantum_comp>> gate_library;
	//Library of designated target and control bits so that the right matrix can be added
	typedef std::map<std::string,std::shared_ptr<quantum_comp>> gate_bit_library;
	extern gate_bit_library bits;
	extern gate_library gates;
	//Library searcher, takes a key and returns a component
	std::shared_ptr<quantum_comp> search_library(int choice, std::string& request);
	//Function to intialize the library with necessary gates and control bits etc.
  void library_creator();
}

#endif