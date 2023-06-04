#include <iostream>
#include "linkedlist.h"

int main() {
  int arr[] = {34, -1, 54, -4, 61, 54};
  
  int length = sizeof(arr)/sizeof(arr[0]);

  create(arr, length);

  display(head);

  insert(head, 0, 100);
  
  insert(head, 7, 999);

  display(head);

  std::cout<<"Deleted "<<delete_el(head, 7)<<std::endl;

  display(head);
}