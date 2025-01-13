#ifndef QUANTUM_COMPONENT_H
#define QUANTUM_COMPONENT_H

#include "matrix.h"
#include <string>

class quantum_comp 
{
  protected:
		int qbit_range;
		matrix qoperator;
		virtual void set_operator() = 0;
  public:
    quantum_comp(int rows, int columns, int qbit_range ) : qbit_range{qbit_range}, qoperator(rows, columns){}
    virtual ~quantum_comp() = default;
    virtual std::string get_symbol() = 0;
	virtual std::string get_name() = 0;
	virtual void get_info() = 0;
	int get_qbit_range(){return qbit_range;}
    matrix get_matrix(){return qoperator;}
};

#endif