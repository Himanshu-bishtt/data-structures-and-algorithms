#include <iostream>
#include "searching.h"

int main() {
  int arr[] = {10, 20, 30, 40, 50, 60};

  int length = sizeof(arr)/sizeof(arr[0]);

  // int index = binary_search(arr, length, 60);

  // printf(index == -1 ? "Element not found\n" : "Element found at index %d\n", index);

  // int index = transposition_linear_search(arr, length, 50);

  int index = recursive_binary_search(arr, length, 0, length-1, 50);

  printf(index == -1 ? "Element not found\n" : "Element found at index %d\n", index);

  for (int i = 0; i < length; ++i) printf("%d ", arr[i]);

  printf("\n");

  return 0;
}
