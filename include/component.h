#ifndef COMPONENT_H
#define COMPONENT_H

#include "matrix.h"
#include <string>

class component
{
  protected:
		int qubit_range;
		matrix qu_operator;
		virtual void set_qu_operator() = 0;
  public:
    component() : qu_operator(){};
    component(int rows, int columns, int qubit_range) : qubit_range{qubit_range}, qu_operator(rows, columns){}
    virtual ~component() = default;
    virtual std::string get_symbol() = 0;
    virtual std::string get_type() = 0;
		virtual std::string get_info() = 0;
		int get_range(){return qubit_range;}
    matrix get_operator(){return qu_operator;}
};

#endif