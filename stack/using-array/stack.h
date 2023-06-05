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

void display(struct Stack st) {
  std::cout<<"******************************************************"<<std::endl;
  for (int i = st.TOP; i >= 0; --i) {
    printf("Top: %d, Index %d, Data: %d\n", st.TOP, i, *(st.s + i));
  };
  std::cout<<"******************************************************"<<std::endl;
};

void push(struct Stack *st, int data) {
  if (st->TOP == st->SIZE - 1) {
    std::cout<<"Stack overflow!!"<<std::endl;
    return;
  };

  st->TOP++;
  st->s[st->TOP] = data; 
  std::cout<<"Inserted "<<data<<std::endl;
};

