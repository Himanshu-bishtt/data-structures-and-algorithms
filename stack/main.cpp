#include <iostream>

#define MAX 50

int stack[MAX + 1], top = -1;

void create() {
  int n;

  std::cout<<"Enter number of elements you want to insert into stack: ";
  std::cin>>n;

  if (n <= 0) {
    std::cout<<"Please enter a valid number"<<std::endl;
    return;
  };

  for (int i = 0; i < n; ++i) {
    std::cout<<"Enter elements "<<i+1<<": ";
    std::cin>>stack[i];
    top++;
  };
};

void display(int stack[]) {
  std::cout<<"********Current stack elements********"<<std::endl;
  for (int i = top; i >= 0; --i) {
    printf("Top: %d, Index: %d, Data: %d\n",top, i, stack[i]);
  };
};

void push(int data) {
  if (top == MAX) {
    std::cout<<"Stack overflow"<<std::endl;
    return;
  };
  top++;
  stack[top] = data;
};

int pop() {
  int data;
  if (top == -1) {
    std::cout<<"Stack underflow"<<std::endl;
    return -1;
  };
  data = stack[top];
  stack[top] = '\0';
  top--;
  return data;
};

int main() {
  create();

  display(stack);

  push(100);

  display(stack);

  push(200);

  display(stack);

  std::cout<<"Popped element "<<pop()<<std::endl;

  display(stack);

  std::cout<<top<<std::endl;
};