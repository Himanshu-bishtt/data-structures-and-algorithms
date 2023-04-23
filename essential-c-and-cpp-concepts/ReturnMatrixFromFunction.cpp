#include <iostream>

using namespace std;

int ** useMatrix(int r, int c) {
  int **matrix = (int **)malloc(r*sizeof(int));

  for (int i = 0; i < c; ++i) {
    matrix[i] = (int *)malloc(sizeof(int));
  }

  cout<<"Enter matrix elements..."<<endl;

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cout<<"Enter element ("<<i<<" "<<j<<") : ";
      cin>>matrix[i][j];
    }
  }

  return matrix;
};

void printMatrix(int **matrix, int rows, int cols) {
  cout<<"Printing matrix..."<<endl;

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  } 
}

int main() {
  int rows, cols;

  cout<<"Enter rows, cols: ";
  cin>>rows>>cols;

  int **matrix = useMatrix(rows, cols);

  printMatrix(matrix, rows, cols);

  free(matrix);
}