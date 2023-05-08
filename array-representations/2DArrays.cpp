#include <iostream>
#include <stdlib.h>

#define row 3
#define col 4

int main() {
  // 1. First method of declaring arrays
  int arr[row][col] = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };

  // // 2. Using array of pointers
  int *arr2[row];

  for (int i = 0; i < row; ++i) {
    arr2[i] = (int *)malloc(col*sizeof(int));
  };

  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      printf("Enter element (%d%d): ",i,j);
      std::cin>>arr2[i][j];
    };
  };

  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      std::cout<<arr2[i][j]<<" ";
    };
    std::cout<<std::endl;
  };


  for (int i = 0; i < row; ++i) {
    free(arr2[i]);
  };

  // // 3. Using double pointers
  int ** arr3;

  arr3 = new int * [row];

  for (int i = 0; i < row; ++i) {
    arr3[i] = new int[col];
  };

  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      printf("Enter element (%d%d): ", i,j);
      std::cin>>arr3[i][j];
    };
  };

  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      printf("%d ", arr3[i][j]);
    };
    printf("\n");
  };

  free(arr3);

  return 0;
};