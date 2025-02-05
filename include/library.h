#ifndef LIBRARY_H
#define LIBRARY_H

#include <unordered_map>
#include <functional>
#include "bits.h"
#include "single_bit_gates.h"
#include "multi_bit_gates.h"
#include "circuit_element.h"

namespace library{
	//Library of all possible gates to add:	
	typedef std::unordered_map<std::string, std::shared_ptr<component>> factory;

	extern factory bits;
	extern factory gates;

	std::shared_ptr<component> string_to_ptr(std::string component);
  	void library_creator();
}

#endif