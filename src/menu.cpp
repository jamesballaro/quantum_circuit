#include "menu.h"

void submenu(std::shared_ptr<q_circuit> circuit)
{
	while(true){
   std::this_thread::sleep_for(std::chrono::milliseconds(750));
		std::cout<<"Options:"<<std::endl;
		std::cout<<"1) Add gate."<<std::endl;
		std::cout<<"2) Remove Gate."<<std::endl;
		std::cout<<"3) See circuit."<<std::endl;
		std::cout<<"4) See circuit matrix."<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Or:"<<std::endl;
		std::cout<<"5) Save Circuit."<<std::endl;
		std::cout<<"6) Load Circuit."<<std::endl;
    std::cout<<"7) New circuit."<<std::endl;
		std::cout<<"8) See gate information."<<std::endl;
    std::cout<<"9) Exit program."<<std::endl;
		std::cout<<std::endl;
		std::cout<<"Please pick an option: ";

		std::string choice_2;
		std::getline(std::cin, choice_2);
		if(!choice_2.empty()){
      int option2{toolbox::int_verifier(choice_2)};
			if(option2 < 1 || option2 > 9){
				std::cout<<std::endl;
				std::cerr<<"Error: Please select one of the options:"<<std::endl;
				std::cout<<std::endl;
			}
      if(option2 == 1){circuit->add_gate();}
      if(option2 == 2){circuit->remove_gate();}
      if(option2 == 3){circuit->draw_circuit();}
      if(option2 == 4){circuit->get_circuit_matrix();}
      if(option2 == 5){circuit->save();}
      if(option2 == 6){circuit->load();}
      if(option2 == 7){
        circuit->create_circuit();
      	submenu(circuit);
      }
      if(option2 == 8){circuit->gate_info();}
      if(option2 == 9){
        std::cout<<"Thank you for using this program!"<<std::endl;
        std::cout<<"************************************************"<<std::endl;
        exit(1);
      }
    }
    else {
      std::cout<<"Empty entry!"<<std::endl;
      std::cout<<"Please enter again: "<<std::endl;
    }
	}
}
void menu()
{
 std::cout<<"************************************************"<<std::endl;
 std::cout<<"    Welcome to the Quantum Circuits Program!"<<std::endl;
 std::cout<<"************************************************"<<std::endl;
 std::cout<<std::endl;
 std::shared_ptr<q_circuit> default_circuit = std::make_shared<q_circuit>();
 while(true){
 std::this_thread::sleep_for(std::chrono::milliseconds(750));
	std::cout<<"Options:"<<std::endl;
	std::cout<<"1) Create quantum circuit."<<std::endl;
	std::cout<<"2) See gate information."<<std::endl;
	std::cout<<"3) Exit program."<<std::endl;
	std::cout<<std::endl;
	std::cout<<"Please pick an option: ";

	std::string choice_1;
	std::getline(std::cin, choice_1);
  if(!choice_1.empty()){
    int option1{toolbox::int_verifier(choice_1)};
		if(option1 < 1 || option1 > 3){
			std::cout<<std::endl;
			std::cerr<<"Error: Please select one of the options:"<<std::endl;
			std::cout<<std::endl;
		}
    if(option1 == 1){
      default_circuit->create_circuit();
      submenu(default_circuit);
    }
		if(option1 == 2){default_circuit->gate_info();}
    if(option1 == 3){
      std::cout<<"Thank you for using this program!"<<std::endl;
      std::cout<<"************************************************"<<std::endl;
      exit(1);
    }
  }
  else {
    std::cout<<"Empty entry!"<<std::endl;
  }
 }
}
