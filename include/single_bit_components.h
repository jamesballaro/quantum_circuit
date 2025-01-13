#ifndef SINGLE_BIT_COMPONENTS_H
#define SINGLE_BIT_COMPONENTS_H

#include "quantum_component.h"

class pauli_X : public quantum_comp 
{	
	private:
		void set_operator();
  public:
    ~pauli_X(){}
    pauli_X(): quantum_comp(2,2,1){
      set_operator();
    }
		void get_info();
    std::string get_symbol();
		std::string get_name();
};

class pauli_Y : public quantum_comp 
{
	private:
		void set_operator();
  public:
    ~pauli_Y(){}
		pauli_Y(): quantum_comp(2,2,1){
      set_operator();
    }
		void get_info();
    std::string get_symbol();
		std::string get_name();
};

class pauli_Z : public quantum_comp 
{
	private:
		void set_operator();
  public:
    ~pauli_Z(){}
    pauli_Z(): quantum_comp(2,2,1){
      set_operator();
    }
		void get_info();
    std::string get_symbol();
		std::string get_name();
};

class hadamard : public quantum_comp 
{
	private:
		void set_operator();
  public:
    ~hadamard(){}
    hadamard(): quantum_comp(2,2,1){
      set_operator();
    }
		void get_info();
    std::string get_symbol();
		std::string get_name();
};

class phase : public quantum_comp 
{
	private:
		void set_operator();
  public:
    ~phase(){}
    phase(): quantum_comp(2,2,1){
      set_operator();
    }
		void get_info();
    std::string get_symbol();
		std::string get_name();
};

class identity : public quantum_comp
{
	private:
		void set_operator();
  public:
    ~identity(){}
    identity(): quantum_comp(2,2,1){
      set_operator();
    }
		void get_info();
    std::string get_symbol();
		std::string get_name();
};

class qbit : public quantum_comp
{
  public:
  ~qbit(){}
  void set_operator();
  qbit() : quantum_comp(2,1,1){
    set_operator();
  }
	void get_info();
  std::string get_symbol();
	std::string get_name();
};

class cbit : public quantum_comp
{
	private:
		void set_operator();
  public:
  ~cbit(){}
  cbit() : quantum_comp(1,1,1){
  	set_operator();
  }
	void get_info();
  std::string get_symbol();
	std::string get_name();
};

#endif