#include <iostream>
#include "queue.h"

int main() {
  Queue<char> queue(10);

  queue.enqueue('h');
  queue.enqueue('i');
  queue.enqueue('m');
  queue.enqueue('a');
  queue.enqueue('n');
  queue.enqueue('s');
  queue.enqueue('h');
  queue.enqueue('u');

  // std::cout<<"Deleted "<<queue.dequeue()<<" from queue"<<std::endl;

  queue.display();

  std::cout<<"First: "<<queue.first()<<std::endl;
  std::cout<<"Last: "<<queue.last()<<std::endl;
  std::cout<<"Full: "<<queue.isFull()<<std::endl;
  std::cout<<"Empty: "<<queue.isEmpty()<<std::endl;
  std::cout<<"Front: "<<queue.getFront()<<std::endl;
  std::cout<<"Rear: "<<queue.getRear()<<std::endl;
  std::cout<<"Size: "<<queue.getSize()<<std::endl;

  return 0;
}