#include <iostream>

struct Node {
  int data;
  struct Node *next;
} *top;

void display(struct Node *p) {
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

void insert(int data) {
  struct Node *temp = new Node;

  if (temp == NULL) {
    std::cout<<"Stack overflow!"<<std::endl;
    return;
  };
  temp->data = data;
  temp->next = top;
  top = temp;
};

int remove() {
  struct Node *temp = top;
  int data = -1;
  if (top == NULL) {
    std::cout<<"Stack underflow"<<std::endl;
    return data;
  };
  data = top->data;
  top = top->next;
  delete temp;
  return data;
};

int peek(int index) {
  struct Node *p = top;
  for (int i = 1; p && i < index; ++i) p = p->next;
  if (!p) return -1;
  return p->data;
};

int stackTop() {
  return top ? top->data : -1;
};

bool isEmpty() {
  return top == NULL;
};

bool isFull() {
  struct Node *temp = new Node;
  return temp == NULL;
};