#ifndef MULTI_BIT_GATES_H
#define MULTI_BIT_GATES_H

#include "component.h"
#include <memory>

class multi_bit_gate : public component
{
  protected:
    multi_bit_gate(){};
    multi_bit_gate(int range) : component(1<<range, 1<<range, range) {}
    virtual ~multi_bit_gate() = default;
};

class cnot : public multi_bit_gate 
{	
	protected:
		virtual void set_qu_operator();
  public:
    ~cnot(){}
    cnot(): multi_bit_gate(2){
    	set_qu_operator();
    }
		
	virtual std::string get_symbol();
    std::string get_type();
	std::string get_info();
};
// class target_cnot  : public cnot 
// {
// 	protected:
// 		virtual void set_qu_operator();
// 	public:
// 		virtual ~target_cnot(){}
// 		target_cnot() : cnot(){
// 			set_qu_operator();
// 		}
// 		std::string get_symbol();
// };
// class target_flip_cnot : public target_cnot
// {
// 	private:
// 		void set_qu_operator();
// 	public:
// 		~target_flip_cnot(){}
// 		target_flip_cnot() : target_cnot(){
// 			set_qu_operator();
// 		}
// };

class cz : public multi_bit_gate 
{
	protected:
		virtual void set_qu_operator();
  public:
    ~cz(){}
    cz(): multi_bit_gate(2){
      set_qu_operator();
    }
    virtual std::string get_symbol();
	std::string get_info();
	std::string get_type();
};
// class target_cz : public cz 
// {
// 	private:
// 	  void set_qu_operator();
//   public:
//     virtual ~target_cz(){}
//     target_cz() : cz(){
//       set_qu_operator();
//     }
//     std::string get_symbol();
// };

class swap : public multi_bit_gate 
{
	protected:
		virtual void set_qu_operator();
  public:
    ~swap(){}
    swap(): multi_bit_gate(2){
      set_qu_operator();
    }
    virtual std::string get_symbol();
	std::string get_info();
	std::string get_type();
};
// class target_swap : public swap 
// {
// 	private:
// 	  virtual void set_qu_operator();
//   public:
//     virtual ~target_swap(){}
//     target_swap() : swap(){
//       set_qu_operator();
//     }
//     std::string get_symbol();
// };

class ccx : public multi_bit_gate 
{
	protected:
    virtual void set_qu_operator();
  public:
    ~ccx(){}
    ccx(): multi_bit_gate(3){
    	set_qu_operator();
    }
		std::string get_info();
    	virtual std::string get_symbol();
		std::string get_type();
};
// class target_ccx  : public ccx 
// {
// 	protected:
// 		virtual void set_qu_operator();
// 	public:
// 		virtual ~target_ccx(){}
// 		target_ccx() : ccx(){
// 			set_qu_operator();
// 		}
// 	std::string get_symbol();
// };
// class target_flip_ccx : public target_ccx
// {
// 	private:
// 		void set_qu_operator();
// 	public:
// 		~target_flip_ccx(){}
// 		target_flip_ccx() : target_ccx(){
// 			set_qu_operator();
// 		}
// };


#endif