#include <iostream>
#include "queue.h"

int main() {
  int arr[] = {123, 43, 54, 66, 12};

  int length = sizeof(arr)/sizeof(arr[0]);

  // create(arr, length);

  display(front);

  enqueue(100);

  display(front);

  enqueue(200);

  enqueue(300);

  display(front);

  std::cout<<"Deleted "<<dequeue()<<std::endl;

  display(front);

  std::cout<<"Front: "<<front<<std::endl;

  std::cout<<"Rear: "<<rear<<std::endl;
};