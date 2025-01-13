#include "complex_custom.h"

std::ostream & complex_custom::operator<<(std::ostream &output, const std::complex<double> number)
{	
	if(number.imag() < 0){
		output<<number.real()<<number.imag()<<"i";
	}
	else if(number.imag() == 0){
		output<<number.real();
	}
	else{
		output<<number.real()<<"+"<<number.imag()<<"i";
	}
	return output;
}