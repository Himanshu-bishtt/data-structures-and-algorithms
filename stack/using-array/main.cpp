#include <iostream>
#include "stack.h"

int main() {
  create();
  std::cout<<"Size: "<<st.SIZE<<std::endl;
  std::cout<<"Top: "<<st.TOP<<std::endl;
  std::cout<<"Array: "<<st.s<<std::endl;

  push(&st, 100);
  push(&st, 200);
  push(&st, 300);
  push(&st, 400);
  push(&st, 500);
  push(&st, 600);

  display(st);

  std::cout<<"Deleted "<<pop(&st)<<std::endl;

  display(st);
};