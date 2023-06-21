#include <iostream>
#include "stack.h"

int main() {
  push(100);
  push(200);
  push(300);
  push(400);
  push(500);

  display(top);

  std::cout<<"Deleted "<<pop()<<std::endl;

  display(top);

  std::cout<<"Data at index 5: "<<peek(6)<<std::endl;

  std::cout<<"Data at top: "<<stackTop()<<std::endl;

  std::cout<<"Is Empty: "<<isEmpty()<<std::endl;

  std::cout<<"Is Full: "<<isFull()<<std::endl;
};