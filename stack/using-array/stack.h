#include <iostream>

struct Stack {
  int SIZE;
  int TOP;
  int *s;
} st;

void create(struct Stack *st) {
  std::cout<<"Enter stack size: ";
  std::cin>>st->SIZE;

  st->s = (int *)malloc(sizeof(int)*st->SIZE);
  st->TOP = -1;
};

void display(struct Stack st) {
  std::cout<<"******************************************************"<<std::endl;
  for (int i = st.TOP, j = 1; i >= 0; --i, ++j) {
    printf("Top: %d, i: %d, pos: %d, Data: %d\n", st.TOP, i, j, *(st.s + i));
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

int pop(struct Stack *st) {
  int data = -1;
  if (st->TOP == -1) {
    std::cout<<"Stack underflow!!"<<std::endl;
    return data;
  };

  data = st->s[st->TOP];
  st->s[st->TOP] = '\0';
  st->TOP--;
  return data;
};

int peek(struct Stack st, int pos) {
  if (pos < 0 || pos > st.TOP) {
    std::cout<<"Invalid pos!!"<<std::endl;
    return -1;
  };
  // stack[TOP - position + 1]
  return st.s[st.TOP - pos + 1];
};

int stackTop(struct Stack st) {
  return st.TOP == -1 ? -1 : st.s[st.TOP];
};

bool isEmpty(struct Stack st) {
  return st.TOP == -1;
};

bool isFull(struct Stack st) {
  return st.TOP == st.SIZE - 1;
};