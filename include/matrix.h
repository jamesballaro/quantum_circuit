#ifndef MATRIX_H
#define MATRIX_H

#include <iostream> // for std::ostream, std::istream, and std::cout
#include <complex>  // for std::complex
#include <cstdlib>  // for exit
#include <vector>  

class matrix
{
  // Friends
  friend std::ostream & operator<<(std::ostream &os, const matrix &mat);
  friend std::istream & operator>>(std::istream &is, matrix &mat);
private:
  std::complex<double> *matrix_data {nullptr};
  int rows{0};
  size_t size;
  int columns{0};
public:
  // Default constructor, constructs an empty 2x2 matrix by default.
  matrix(){
    this->rows = 2;
    this->columns = 2;
    this->size = 4;
    this->matrix_data = new std::complex<double> [4]{0}; // All entries set to zero
  }
  // Parameterized constructor
  matrix(int rows, int columns){
    this->rows = rows;
    this->columns = columns;
    this->size = rows*columns;
    this->matrix_data = new std::complex<double>[size];
  }
  // Destructor
  ~matrix(){
    delete[] matrix_data;
    matrix_data = nullptr;
  }
  // Access functions
  int get_rows() const {return rows;} // Return number of rows
  int get_cols() const {return columns;} // Return number of columns
  int index(int m, int n) const // Return position in array of element (m,n)
  {
    if(m>0 && m<=rows && n>0 && n<=columns) return (n-1)+(m-1)*columns;
    else {std::cout<<"Error: out of range"<<std::endl; exit(1);}
  }
  std::complex<double> & operator()(int m, int n)const{return matrix_data[index(m,n)];}

  //Set data:
  void set_data(std::vector<std::complex<double>> &vector);
  // Copy constructor
  matrix(const matrix &mat);
  // Move constructor
  matrix(matrix &&mat);
  // Copy  Assignment operator
  matrix & operator=(const matrix &mat);
  // Move Assignment operator
  matrix & operator=(matrix&& mat);
  // Multiplication and tensor product
  matrix operator*(matrix& mat);
  matrix tensor_product(matrix& mat_B);
};

#endif





