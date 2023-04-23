#include <iostream>
#include <stdlib.h>

template<class T>
class Matrix {
  private: 
    int rows;
    int cols;
    T **matrix;

  public:
    Matrix() {
      this->rows = 2;
      this->cols = 2;
    };

    Matrix(int rows, int cols) {
      this->rows = rows;
      this->cols = cols;
    };

    T ** create_matrix() {
      this->matrix = (T **)malloc(this->rows * sizeof(T *));

      for (int i = 0; i < this->rows; ++i) {
        this->matrix[i] = (T *)malloc(this->cols * sizeof(T *));
      };

      return this->matrix;
    };

    void fill_matrix_elements() {
      std::cout<<"Enter matrix elements..."<<std::endl;

      for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
          T value;
          std::cout<<"Enter element ("<<i<<j<<") : ";
          std::cin>>value;
          this->matrix[i][j] = value;
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
  int rows, cols;

  std::cout<<"Enter rows and cols: ";
  std::cin>>rows>>cols;

  if (rows < 0 || cols < 0) {
    std::cout<<"Rows or Cols cannot be negative"<<std::endl;
    return -1;
  }

  Matrix<float> m = Matrix<float>(rows, cols);

  m.create_matrix();
  
  m.fill_matrix_elements();

  m.print_matrix();
}