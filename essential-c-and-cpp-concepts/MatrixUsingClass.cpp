#include <iostream>
#include <stdlib.h>

class Matrix {
  private: 
    int rows;
    int cols;
    int **matrix;

  public:
    Matrix() {
      this->rows = 2;
      this->cols = 2;
    };

    Matrix(int rows, int cols) {
      this->rows = rows;
      this->cols = cols;
    };

    int ** create_matrix() {
      this->matrix = (int **)malloc(this->rows * sizeof(int *));

      for (int i = 0; i < this->rows; ++i) {
        this->matrix[i] = (int *)malloc(this->cols * sizeof(int *));
      };

      return this->matrix;
    };

    void fill_matrix_elements() {
      std::cout<<"Enter matrix elements..."<<std::endl;

      for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
          std::cout<<"Enter element ("<<i<<j<<") : ";
          std::cin>>this->matrix[i][j];
        };
      };
    };

    void print_matrix() {
      std::cout<<std::endl<<"Printing matrix..."<<std::endl;

      for (int i = 0; i < this->rows; ++i) {
        std::cout<<"| ";
        for (int j = 0; j < this->cols; ++j) {
          std::cout<<this->matrix[i][j]<<" | ";
        }
        std::cout<<std::endl;
      } 
    };

  ~Matrix() {
    for (int i = 0; i < this->rows; ++i) {
      free(this->matrix[i]);
    };

    free(matrix);

    std::cout<<"Matrix deleted from heap"<<std::endl;
  };
};

int main() {
  Matrix m = Matrix(3, 3);

  m.create_matrix();
  
  m.fill_matrix_elements();

  m.print_matrix();
}