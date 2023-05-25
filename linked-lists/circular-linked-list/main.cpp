#include <iostream>

#include "linkedlist.h"

int main() {
  int arr[] = {10, 5, 12, 54, 765};

  int length = sizeof(arr)/sizeof(arr[0]);

  create(arr, length);

  // display(head);  

  recursive_display(head);

  return 0;
}