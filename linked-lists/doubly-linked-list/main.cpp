#include <iostream>
#include "linkedlist.h"

int main() {
  int arr[] = {12};

  int length = sizeof(arr)/sizeof(arr[0]);

  create(arr, length);

  display(first);
}