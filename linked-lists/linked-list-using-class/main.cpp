#include <iostream>

#include "linkedlist.h"

int main() {
  int arr[] = {32, 12, 54, 76, 23};

  int length = sizeof(arr)/sizeof(arr[0]);

  LinkedList ll(arr, length);

  ll.display();


  std::cout<<ll.length()<<std::endl;

  ll.insert(3, 99);

  ll.display();

  std::cout<<ll.getFirst()<<std::endl;

  std::cout<<ll.getLast()<<std::endl;

  std::cout<<"Element deleted: "<<ll.delete_el(3)<<std::endl;

  std::cout<<"Element deleted: "<<ll.delete_el(5)<<std::endl;

  ll.display();

  return 0;
};