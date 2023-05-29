#include <iostream>
#include "linkedlist.h"

int main() {
  int arr[] = {12, 43, 11, 76, 99, 100};

  int length = sizeof(arr)/sizeof(arr[0]);

  create(arr, length);

  reverse(first);

  display(first);
};