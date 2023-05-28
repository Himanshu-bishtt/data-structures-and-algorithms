#include <iostream>
#include "linkedlist.h"

int main() {
  int arr[] = {12};

  int length = sizeof(arr)/sizeof(arr[0]);

  create(arr, length);

  display(first);

  // insert(first, 3, 100);

  // display(first);

  std::cout<<delete_el(first, 1)<<" deleted!"<<std::endl;

  display(first);
};