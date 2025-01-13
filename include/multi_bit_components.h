#ifndef MULTI_BIT_COMPONENTS_H
#define MULTI_BIT_COMPONENTS_H

#include "quantum_component.h"

class cnot : public quantum_comp 
{	
	protected:
		virtual void set_operator();
  public:
    ~cnot(){}
    cnot(): quantum_comp(4,4,2){
    	set_operator();
    }
    cnot(int rows, int columns, int qbit_range) : quantum_comp(rows, columns, qbit_range) {}
		void get_info();
		virtual std::string get_symbol();
    std::string get_name();
};
class target_cnot  : public cnot 
{
	protected:
		virtual void set_operator();
	public:
		virtual ~target_cnot(){}
		target_cnot() : cnot(4,4,1){
			set_operator();
		}
		std::string get_symbol();
};
class target_flip_cnot : public target_cnot
{
	private:
		void set_operator();
	public:
		~target_flip_cnot(){}
		target_flip_cnot() : target_cnot(){
			set_operator();
		}
};
class control_cnot : public cnot 
{
	private:
		void set_operator();
  public:
    ~control_cnot(){}
    control_cnot() : cnot(1,1,1){
      set_operator();
    }
    std::string get_symbol();
};

class cz : public quantum_comp 
{
	protected:
		virtual void set_operator();
  public:
    ~cz(){}
    cz(): quantum_comp(4,4,2){
      set_operator();
    }
    cz(int rows, int columns, int qbit_range) : quantum_comp(rows, columns, qbit_range) {}
		void get_info();
    virtual std::string get_symbol();
		std::string get_name();
};
class target_cz : public cz 
{
	private:
	  void set_operator();
  public:
    virtual ~target_cz(){}
    target_cz() : cz(4,4,1){
      set_operator();
    }
    std::string get_symbol();
};
class control_cz : public cz 
{
	private:
		void set_operator();
  public:
    ~control_cz(){}
    control_cz() : cz(1,1,1){
      set_operator();
    }
    std::string get_symbol();
};

class swap : public quantum_comp 
{
	protected:
		virtual void set_operator();
  public:
    ~swap(){}
    swap(): quantum_comp(4,4,2){
      set_operator();
    }
    swap(int rows, int columns, int qbit_range) : quantum_comp(rows, columns, qbit_range) {}
    virtual std::string get_symbol();
		void get_info();
		std::string get_name();
};
class target_swap : public swap 
{
	private:
	  virtual void set_operator();
  public:
    virtual ~target_swap(){}
    target_swap() : swap(4,4,1){
      set_operator();
    }
    std::string get_symbol();
};
class control_swap : public swap 
{
	private:
	  void set_operator();
  public:
    ~control_swap(){}
    control_swap() : swap(1,1,1){
      set_operator();
    }
    std::string get_symbol();
};

class ccx : public quantum_comp 
{
	protected:
    virtual void set_operator();
  public:
    ~ccx(){}
    ccx(): quantum_comp(8,8,3){
    	set_operator();
    }
    ccx(int rows, int columns, int qbit_range) : quantum_comp(rows, columns, qbit_range) {}
		void get_info();
    virtual std::string get_symbol();
		std::string get_name();
};
class target_ccx  : public ccx 
{
	protected:
		virtual void set_operator();
	public:
		virtual ~target_ccx(){}
		target_ccx() : ccx(8,8,1){
			set_operator();
		}
	std::string get_symbol();
};
class target_flip_ccx : public target_ccx
{
	private:
		void set_operator();
	public:
		~target_flip_ccx(){}
		target_flip_ccx() : target_ccx(){
			set_operator();
		}
};
class control_ccx : public ccx 
{
	private:
    void set_operator();
  public:
    ~control_ccx(){}
    control_ccx() : ccx(1,1,1){
      set_operator();
    }
    std::string get_symbol();
};

#endif