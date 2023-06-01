#include <iostream>
#include "searching.h"

int main() {
  int arr[] = {10, 20, 30, 40, 50, 60};

  int length = sizeof(arr)/sizeof(arr[0]);

  int index = binary_search(arr, length, 60);

  printf(index == -1 ? "Element not found\n" : "Element found at index %d\n", index);

  return 0;
}
