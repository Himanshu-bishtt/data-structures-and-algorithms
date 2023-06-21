#include <iostream>
#include "node.h"

class Stack {
  private: 
    Node *top;

  public:
    Stack();
    ~Stack();

    void push(int data);
    int pop();
    void display();
    int peek(int index);
    int stackTop();
    bool isEmpty();
    bool isFull();
};

Stack::Stack() {
  this->top = NULL;
};

Stack::~Stack() {
  std::cout<<"Destructor"<<std::endl;
  delete this->top;
};

void Stack::push(int data) {
  Node *temp = new Node;
  if(temp == NULL) {
    std::cout<<"Stack overflow"<<std::endl;
    return;
  };
  temp->data = data;
  temp->next = top;
  top = temp;
};

int Stack::pop() {
  if (this->top == NULL) {
    std::cout<<"Stack underflow"<<std::endl;
    return -1;
  };
  Node *temp = this->top;
  int data;
  data = this->top->data;
  this->top = this->top->next;
  delete temp;
  return data;
};

void Stack::display() {
  Node *p = this->top;
  std::cout<<"************************************************************************"<<std::endl;
  if (!p) {
    std::cout<<"Stack is empty"<<std::endl;
    return;
  };
  while(p != NULL) {
    printf("Data: %d, Address: %p, Next: %p\n", p->data, p, p->next);
    p = p->next;
  };
};

int Stack::peek(int index) {
  Node *p = this->top;
  for (int i = 1; p && i < index; ++i) p = p->next;
  if (!p) return -1;
  return p->data;
};

int Stack::stackTop() {
  return this->top == NULL ? -1 : this->top->data;
};

bool Stack::isEmpty() {
  return this->top == NULL;
};

bool Stack::isFull() {
  Node *t = new Node;
  return t == NULL;
};