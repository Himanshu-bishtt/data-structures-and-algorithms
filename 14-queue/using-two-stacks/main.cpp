#include <iostream>
#include "queue.h"

int main() {
  struct Stack s1, s2;

  create(&s1, "s1", 10);
  create(&s2, "s2", 10);

  enqueue(&s1, 6);
  enqueue(&s1, 3);
  enqueue(&s1, 9);
  enqueue(&s1, 5);
  enqueue(&s1, 4);
  enqueue(&s1, 2);
  enqueue(&s1, 8);
  enqueue(&s1, 12);
  enqueue(&s1, 10);

  std::cout<<"Deleted "<<dequeue(&s1, &s2)<<std::endl;
  std::cout<<"Deleted "<<dequeue(&s1, &s2)<<std::endl;
  std::cout<<"Deleted "<<dequeue(&s1, &s2)<<std::endl;
  std::cout<<"Deleted "<<dequeue(&s1, &s2)<<std::endl;
  std::cout<<"Deleted "<<dequeue(&s1, &s2)<<std::endl;
  std::cout<<"Deleted "<<dequeue(&s1, &s2)<<std::endl;
  std::cout<<"Deleted "<<dequeue(&s1, &s2)<<std::endl;
  std::cout<<"Deleted "<<dequeue(&s1, &s2)<<std::endl;
  std::cout<<"Deleted "<<dequeue(&s1, &s2)<<std::endl;

  enqueue(&s1, 100);
  enqueue(&s1, 200);
  enqueue(&s1, 300);
  
  std::cout<<"Deleted "<<dequeue(&s1, &s2)<<std::endl;
  std::cout<<"Deleted "<<dequeue(&s1, &s2)<<std::endl;

  enqueue(&s1, 400);

  display(s1);
  display(s2);
}