#include <iostream>
#include "queue.h"

int main() {
  initialize(5);

  enqueue(50);
  enqueue(100);
  enqueue(150);
  enqueue(200);
  enqueue(250);
  enqueue(300);

  std::cout<<dequeue()<<" deleted from queue"<<std::endl;

  std::cout<<"Is Full: "<<(isFull() ? "True" : "False")<<std::endl;

  std::cout<<"Is Empty: "<<(isEmpty() ? "True" : "False")<<std::endl;

  std::cout<<"Length: "<<length()<<std::endl;

  display();
}