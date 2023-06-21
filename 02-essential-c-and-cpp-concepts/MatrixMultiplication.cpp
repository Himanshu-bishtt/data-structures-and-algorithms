#include <iostream>

int ** create_matrix(int r, int c) {
  int ** matrix = (int **)malloc(r * sizeof(int *));

  for (int i = 0; i < r; ++i)
    matrix[i] = (int *)malloc(c * sizeof(int));

  return matrix;
};

void fill_matrix_elements(int **matrix, int r, int c) {
  std::cout<<"Enter matrix elements..."<<std::endl;

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      std::cout<<"Enter element ("<<i<<j<<") : ";
      std::cin>>matrix[i][j];
    };
  };
};

void print_matrix(int ** matrix, int r, int c) {
  std::cout<<std::endl<<"Printing matrix..."<<std::endl;

  for (int i = 0; i < r; ++i) {
    std::cout<<"| ";
    for (int j = 0; j < c; ++j) {
      std::cout<<matrix[i][j]<<" | ";
    }
    std::cout<<std::endl;
  } 
};

int ** mulitly_matrix(int ** source1, int **  source2, int m, int n, int p, int q) {
  int ** matrix = create_matrix(m, q);

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < q; ++j) {
      int sum = 0;
      for (int k = 0; k < p; ++k) {
        sum += source1[i][k] * source2[k][j];
      };
      matrix[i][j] = sum;
    }
  }

  return matrix;
};

void delete_matrix(int ** matrix, int r) {
  for (int i = 0; i < r; ++i) {
    free(matrix[i]);
  };
  free(matrix);
  std::cout<<"Matrix deleted from heap!!!!"<<std::endl;
}

int main() {
  int m, n, p, q;

  std::cout<<"Enter m and n: ";
  std::cin>>m>>n;

  std::cout<<"Enter p and q: ";
  std::cin>>p>>q;

  if (n != p) {
    std::cout<<"Matrix multiplication is not possible"<<std::endl;
    return -1;
  }

  int **matrix1, **matrix2, **matrix3;

  matrix1 = create_matrix(m, n);

  fill_matrix_elements(matrix1, m, n);

  matrix2 = create_matrix(p, q);

  fill_matrix_elements(matrix2, p, q);

  matrix3 = mulitly_matrix(matrix1, matrix2, m, n, p, q);

  print_matrix(matrix1, m, n);

  print_matrix(matrix2, p, q);

  print_matrix(matrix3, m, q);

  int sum = 0;
  
  delete_matrix(matrix1, m);
  
  delete_matrix(matrix2, p);
  
  delete_matrix(matrix3, m);

  return 0;
}