#include <iostream>
#include "linkedlist.h"

int main() {
  int arr[] = {12, 43, 111, 999};

  int length = sizeof(arr)/sizeof(arr[0]);

  create(arr, length);

  display(first);

  std::cout<<first<<std::endl;

  std::cout<<last<<std::endl;

  insert(first, 3, 100);

  display(first);

  std::cout<<first<<std::endl;

  std::cout<<last<<std::endl;
}