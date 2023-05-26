#include <iostream>

#include "linkedlist.h"

int main() {
  int arr[] = {10};

  int length = sizeof(arr)/sizeof(arr[0]);

  create(arr, length);

  // display(head);  

  display(head);

  std::cout<<count(head)<<std::endl;

  // insert(head, 5, 500);

  // display(head);

  // insert(head, 1, 999);

  // display(head);

  std::cout<<head<<std::endl;

  std::cout<<tail<<std::endl;

  return 0;
}