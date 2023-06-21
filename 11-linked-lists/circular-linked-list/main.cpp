#include <iostream>

#include "linkedlist.h"

int main() {
  int arr[] = {10, 5, 12, 54, 765, 444, 999};

  int length = sizeof(arr)/sizeof(arr[0]);

  create(arr, length);

  insert(head, 1, 999);

  display(head);

  int el = delete_el(head, 1);

  std::cout<<el<<" is deleted!"<<std::endl;

  display(head);

  std::cout<<"Head: "<<head<<std::endl;
  std::cout<<"Tail: "<<tail<<std::endl;

  return 0;
}