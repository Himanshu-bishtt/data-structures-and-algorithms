#include <iostream>
#include "stack.h"

int main() {
  insert(100);
  insert(200);
  insert(300);
  insert(400);
  insert(500);

  display(top);

  std::cout<<"Deleted "<<remove()<<std::endl;

  display(top);

  std::cout<<"Data at index 5: "<<peek(6)<<std::endl;

  std::cout<<"Data at top: "<<stackTop()<<std::endl;

  std::cout<<"Is Empty: "<<isEmpty()<<std::endl;

  std::cout<<"Is Full: "<<isFull()<<std::endl;
};