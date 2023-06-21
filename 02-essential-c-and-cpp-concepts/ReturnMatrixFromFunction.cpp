#include <iostream>
#include <stdio.h>

int ** use_matrix(int r, int c) {
  int **matrix = (int **)malloc(r*sizeof(int *));

  for (int i = 0; i < r; ++i) {
    matrix[i] = (int *)malloc(sizeof(int) * c);
  }

  std::cout<<"Enter matrix elements..."<<std::endl;

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      std::cout<<"Enter element ("<<i<<" "<<j<<") : ";
      std::cin>>matrix[i][j];
    }
  }

  return matrix;
};

void print_matrix(int **matrix, int rows, int cols) {
  std::cout<<std::endl<<"Printing matrix..."<<std::endl;

  for (int i = 0; i < rows; ++i) {
      std::cout<<"| ";
    for (int j = 0; j < cols; ++j) {
      std::cout<<matrix[i][j]<<" | ";
    }
    std::cout<<std::endl;
  } 
}

int main() {
  int rows, cols;

  std::cout<<"Enter rows, cols: ";

  std::cin>>rows>>cols;

  int **matrix = use_matrix(rows, cols);

  print_matrix(matrix, rows, cols);

  free(matrix);
}