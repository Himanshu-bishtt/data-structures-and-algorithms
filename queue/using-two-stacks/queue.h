#include <iostream>

struct Stack {
  int size;
  int top;
  int *s;
  std::string name;
};

void create(struct Stack *stack, std::string name, int size) {
  stack->size = size;
  stack->top = -1;
  stack->s = new int[stack->size];
  stack->name = name;
};

void push(struct Stack *stack, int data) {
  if (stack->size == stack->size - 1) {
    std::cout<<"Stack overflow"<<std::endl;
    return;
  };
  stack->top++;
  stack->s[stack->top] = data;
};

int pop(struct Stack *stack) {
  if (stack->top == -1) {
    std::cout<<"Stack underflow"<<std::endl;
    return -1;
  };
  int data = stack->s[stack->top--];
  return data;
};

bool isEmpty(struct Stack *stack) {
  return stack->top == -1;
};

void display(struct Stack stack) {
  if(stack.top == -1) {
    std::cout<<stack.name<<" stack is empty"<<std::endl;
    return;
  };
  std::cout<<"************************Displaying "<<stack.name<<" stack************************"<<std::endl;
  for (int i = stack.top; i >= 0; i--)
    printf("Data: %d, Top: %d\n", stack.s[i], stack.top);
};

void enqueue(struct Stack *stack, int data) {
  push(stack, data);
};

int dequeue(struct Stack *s1, struct Stack *s2) {
  if (isEmpty(s2)) {
    if (isEmpty(s1)) {
      std::cout<<"stack s1 is empty"<<std::endl;
      return -1;
    } else {
      for (int i = s1->top; i >= 0; --i)
        push(s2, pop(s1));
    };
  };
  return pop(s2);
};