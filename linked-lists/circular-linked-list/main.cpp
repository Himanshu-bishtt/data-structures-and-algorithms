#include <iostream>

#include "linkedlist.h"

int main() {
  int arr[] = {10, 5, 12, 54, 765};

  int length = sizeof(arr)/sizeof(arr[0]);

  create(arr, length);

  insert(head, 1, 999);

  display(head);

  insert(head, 1, 9999);

  display(head);

  std::cout<<head<<std::endl;

  std::cout<<tail<<std::endl;

  return 0;
}