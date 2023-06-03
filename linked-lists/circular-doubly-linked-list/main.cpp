#include <iostream>
#include "linkedlist.h"

int main() {
  int arr[] = {34, -1, 54, -44, 612, 54};
  
  int length = sizeof(arr)/sizeof(arr[0]);

  create(arr, length);

  display(head);
}