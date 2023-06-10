#include <iostream>
#include "queue.h"

int main() {
  Queue queue(5);

  queue.enqueue(10);
  queue.enqueue(20);
  queue.enqueue(30);
  queue.enqueue(40);
  queue.enqueue(50);

  std::cout<<"Deleted "<<queue.dequeue()<<" from queue"<<std::endl;

  queue.display();

  std::cout<<"First: "<<queue.first()<<std::endl;

  std::cout<<"Last: "<<queue.last()<<std::endl;
  
  return 0;
}