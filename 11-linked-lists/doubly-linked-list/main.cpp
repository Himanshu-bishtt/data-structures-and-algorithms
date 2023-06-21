#include <iostream>
#include "linkedlist.h"

int main() {
  int arr[] = {12, 43, 11, 76, 99, 100, 200};

  int length = sizeof(arr)/sizeof(arr[0]);

  create(arr, length);

  reverse(first);

  display(first);

  std::cout<<"Middle node: "<<middle_node_single_scan(first)->data<<std::endl;
};