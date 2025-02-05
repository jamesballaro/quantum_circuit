#ifndef SINGLE_BIT_GATES_H
#define SINGLE_BIT_GATES_H

#include "component.h"
class single_bit_gate : public component
{
  protected:
    single_bit_gate() : component(2,2,1) {}
    virtual ~single_bit_gate() = default;
};

class pauli_X : public single_bit_gate 
{	
	private:
		void set_qu_operator();
  public:
    ~pauli_X(){}
    pauli_X() : single_bit_gate(){
      set_qu_operator();
    }
		std::string get_info();
    std::string get_symbol();
		std::string get_type();
};

class pauli_Y : public single_bit_gate 
{
	private:
		void set_qu_operator();
  public:
    ~pauli_Y(){}
		pauli_Y() : single_bit_gate(){
      set_qu_operator();
    }
		std::string get_info();
    std::string get_symbol();
		std::string get_type();
};

class pauli_Z : public single_bit_gate 
{
	private:
		void set_qu_operator();
  public:
    ~pauli_Z(){}
    pauli_Z() : single_bit_gate(){
      set_qu_operator();
    }
		std::string get_info();
    std::string get_symbol();
		std::string get_type();
};

class hadamard : public single_bit_gate 
{
	private:
		void set_qu_operator();
  public:
    ~hadamard(){}
    hadamard() : single_bit_gate(){
      set_qu_operator();
    }
		std::string get_info();
    std::string get_symbol();
		std::string get_type();
};

class phase : public single_bit_gate 
{
	private:
		void set_qu_operator();
  public:
    ~phase(){}
    phase() : single_bit_gate(){
      set_qu_operator();
    }
		std::string get_info();
    std::string get_symbol();
		std::string get_type();
};

class identity : public single_bit_gate
{
	private:
		void set_qu_operator();
  public:
    ~identity(){}
    identity() : single_bit_gate(){
      set_qu_operator();
    }
		std::string get_info();
    std::string get_symbol();
		std::string get_type();
};

#endif