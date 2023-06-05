#include <iostream>

struct Stack {
  int SIZE;
  int TOP;
  int *s;
} st;

void create() {
  std::cout<<"Enter stack size: ";
  std::cin>>st.SIZE;

  st.s = (int *)malloc(sizeof(int)*st.SIZE);
  st.TOP = -1;
};

