#include <iostream>
#include "queue.h"

int main() {
  initialize(10);

  enqueue(50);
  enqueue(100);
  enqueue(150);
  enqueue(200);
  enqueue(250);

  std::cout<<dequeue()<<" deleted from queue"<<std::endl;

  display();
}