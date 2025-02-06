#ifndef BITS_H
#define BITS_H

#include "component.h"

class bit : public component
{
  protected:
    bit(){};
    bit(int matrix) : component(matrix, 1, 1) {}
    virtual ~bit() = default;
};

class qubit : public bit
{ 
  private:
  int state;
  public:
  ~qubit(){}
  void set_qu_operator();
  void set_qu_operator(int choice) ;
  qubit(int choice) : bit(2), state{choice}{
    set_qu_operator(state);
  }
  qubit() : bit(2), state{0}{
    set_qu_operator(state);
  }
  std::string get_symbol();
	std::string get_type();
  std::string get_info();
};
class cbit : public bit
{
	private:
		void set_qu_operator();
  public:
  ~cbit(){}
  cbit() : bit(1){
  	set_qu_operator();
  }
  std::string get_symbol();
	std::string get_type();
  std::string get_info();
};
// class control_swap : public bit 
// {
// 	private:
// 	  void set_qu_operator();
//   public:
//     ~control_swap(){}
//     control_swap() : bit(1){
//       set_qu_operator();
//     }
//     std::string get_symbol();
//     std::string get_type();
//     std::string get_info();
// };
// class control_cz : public bit 
// {
// 	private:
// 		void set_qu_operator();
//   public:
//     ~control_cz(){}
//     control_cz() : bit(1){
//       set_qu_operator();
//     }
//     std::string get_symbol();
//     std::string get_type();
//     std::string get_info();
// };
// class control_cnot : public bit 
// {
// 	private:
// 		void set_qu_operator();
//   public:
//     ~control_cnot(){}
//     control_cnot() : bit(1){
//       set_qu_operator();
//     }
//     std::string get_symbol();
//     std::string get_type();
//     std::string get_info();
// };
// class control_ccx : public bit 
// {
// 	private:
//     void set_qu_operator();
//   public:
//     ~control_ccx(){}
//     control_ccx() : bit(1){
//       set_qu_operator();
//     }
//     std::string get_symbol();
//     std::string get_type();
//     std::string get_info();
// };


#endif