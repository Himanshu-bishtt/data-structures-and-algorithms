#include <iostream>
#include "queue.h"

int main() {
  initialize(5);

  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  enqueue(50);

  display();

  std::cout<<"Deleted: "<<dequeue()<<std::endl;
  std::cout<<"Deleted: "<<dequeue()<<std::endl;

  display();

  enqueue(50);
  enqueue(60);
  enqueue(70);

  display();
}