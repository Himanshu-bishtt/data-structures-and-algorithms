#include <iostream>

int main() {
  int arr[] = {43, 12, 54, 66, 14};

  int length = sizeof(arr)/sizeof(arr[0]);

  // using loop
  for (int i = 0; i < length; ++i) {
    std::cout<<arr[i]<<" ";
  };

  std::cout<<std::endl;
  
  // normal way
  std::cout<<arr[0]<<std::endl;

  // using array name inside brackets
  std::cout<<(length-1)[arr]<<std::endl;

  std::cout<<1[arr]<<std::endl;

  // using pointer arithmetic
  std::cout<<*(arr+0)<<std::endl;

  // loop using pointer arithmetic

  for (int i = 0; i < length; ++i) {
    std::cout<<*(arr+i)<<" ";
  };

  std::cout<<std::endl;

  return 0;
}