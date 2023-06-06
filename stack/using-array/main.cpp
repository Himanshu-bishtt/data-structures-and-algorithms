#include <iostream>
#include "stack.h"

int main() {
  create(&st);

  push(&st, 100);
  push(&st, 200);
  push(&st, 300);
  push(&st, 400);
  push(&st, 500);
  push(&st, 600);

  display(st);

  std::cout<<"Deleted "<<pop(&st)<<std::endl;

  display(st);

  printf("Data at pos %d: %d\n", 8, peek(st, 8));
};