#include "matrix.h"
#include "complex_custom.h"
#include <algorithm>    
#include <limits>
#include <cmath>        
#include <iomanip>

void matrix::set_data(std::vector<std::complex<double>> &vector)
{
  if (vector.size() == size){
    for(size_t i{0}; i<size; i++){ 
			matrix_data[i] = vector[i];
			}
    } 
  else{
		std::cout<<std::endl;
    std::cout<<"Error: The array must have the same number of elements as the matrix"<<std::endl; 
    exit(1);
  }
}
//Copy Constructor
matrix::matrix(const matrix &mat)
{
  // Copy size and declare new array
  matrix_data = nullptr; 
  rows = mat.rows;
  columns = mat.columns;
  size = mat.size;
  if(size > 0) {
    matrix_data = new std::complex<double>[size];
    // Copy values into new array
    for(size_t i{0}; i < size; i++){
      matrix_data[i] = mat.matrix_data[i];
    }
  }
}
//Move Constructor
matrix::matrix(matrix &&mat)
{ 
  std::cout<<"Move Constructor Called"<<std::endl;
  size = mat.size;
  rows = mat.rows;
  columns = mat.columns;
  matrix_data = mat.matrix_data;
  mat.columns = 0;
  mat.rows = 0;
  mat.size = 0;
  mat.matrix_data = nullptr;
}
//Copy assignment
matrix & matrix::operator=(const matrix &mat)
{
  if(&mat == this){ 
    std::cout<<"Self-assignment in copy assignment operator"<<std::endl;  
    return *this; // no self assignment
  }
    // First delete this object's array
  delete[] matrix_data; matrix_data = nullptr; size = 0;
    // Now copy size and declare new array
  size = mat.size;
  rows = mat.rows;
  columns = mat.columns;
  if(size > 0){
    matrix_data = new std::complex<double>[size];
    // Copy values into new array
    for(size_t i{}; i < size; i++) matrix_data[i] = mat.matrix_data[i];
  }
  return *this; // Special pointer!!!
}
//Move Assignment
matrix & matrix::operator=(matrix&& mat)
{
  std::swap(rows, mat.rows);
  std::swap(columns, mat.columns);
  std::swap(size, mat.size);
  std::swap(matrix_data, mat.matrix_data);
  mat.columns = 0;
  mat.rows = 0;
  mat.size = 0;
  mat.matrix_data = nullptr;
  return *this; 
}

//Matrix operations:
//Multiplication
matrix matrix::operator*(matrix& mat)
{
  matrix temp(rows, mat.columns);
  if (columns == mat.rows){
		for(int i{1}; i <= rows; i++){
			for(int j{1}; j <= mat.columns; j++){
				std::complex<double> sum = 0;
				for(int k{1}; k <= columns; k++){
					sum += operator()(i, k) * mat(k, j);
				}
				temp(i, j) = sum;
			}
		}
	} 
	else{
		std::cout<<std::endl;
    std::cout<<"Error: These two matrices are not compatible for multiplication"<<std::endl; 
    temp.matrix_data[0] = {NAN};
  }
  return temp;
}
//Kronecker Product
matrix matrix::tensor_product(matrix& mat_B) 
{
  int rows_A = this->rows;
  int cols_A = this->columns;
  int rows_B = mat_B.rows;
  int cols_B = mat_B.columns;
  matrix temp(rows_A * rows_B, cols_A * cols_B);
  for (int i{1}; i <= rows_A; ++i) {
    for (int j{1}; j <= cols_A; ++j) {
      for (int k{1}; k <= rows_B; ++k) {
        for (int l{1}; l <= cols_B; ++l) {
          temp((i-1) * rows_B + k, (j-1) * cols_B + l) = operator()(i,j) * mat_B(k,l);
        }
      }
    }
  }
  return temp;
}

std::ostream & operator<<(std::ostream &output, const matrix &mat)
{
  using complex_custom::operator<<;
  int max_width = 0;
  std::stringstream ss;
  if(mat.size > 0){
    for(int i{1}; i <= mat.rows; i++){
      for(int j{1}; j <= mat.columns; j++){
        ss.str("");
        if(mat(i,j).imag() == 0){
          ss<<std::setw(4)<<mat(i,j).real();
        }
        else{
          ss<<std::setw(4)<<mat(i,j);
        }
        max_width = std::max(max_width, static_cast<int>(ss.str().length())); 
      }
    }
    for(int i{1}; i <= mat.rows; i++){
      output << "[  ";
      for(int j{1}; j <= mat.columns; j++){
      	ss.str("");
        if(mat(i,j).imag() == 0){
        	ss<<std::setw(3)<<mat(i,j).real();
        }
        else{
          ss<<std::setw(3)<<mat(i,j);
        }
        output<<ss.str()<<std::string(max_width - ss.str().length(), ' ');
      }
      output << "  ]" << std::endl;
    }
  }
  else{
		std::cout<<std::endl;
    output << "Error: This matrix has no elements.";
  }
  output << std::endl;
  return output;
}

// Overload the extraction operator for the matrix class
std::istream & operator>>(std::istream &input, matrix &mat) 
{
  std::vector<std::complex<double>> values;
  char delimiter;
  std::complex<double> value; 
  std::cout<<"Please enter values for your matrix, "<<mat.size<<" values expected:";
    // Read values separated by commas
  while (input>>value) {
    values.push_back(value);
    if (input.eof() || input.peek() == '\n') {
    	break;
    }
    input>>delimiter;
    if (delimiter != ',' || input.peek() == ',' || input.peek() == '\n') {
      throw std::invalid_argument("Please enter values as such X,X,X,X");
    }
  }
  // Check if the correct number of elements were input
  if (values.size() != mat.size) {
    std::cerr<<"Incorrect number of elements. Expected "<<mat.size<<" elements."<<std::endl;
    std::cerr<<"Please enter the elements again: ";
    input.clear();
    input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return input>>mat;
  }
  // Assign values to the matrix
  mat.set_data(values);
  return input;
}












