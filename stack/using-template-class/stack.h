#include <iostream>
#include "node.h"

template <class T>
class Stack {
  private: 
    Node<T> *top;

  public:
    Stack();
    ~Stack();

    void push(T data);
    T pop();
    void display();
    T peek(int index);
    T stackTop();
    bool isEmpty();
    bool isFull();
};

template <class T>
Stack<T>::Stack() {
  this->top = NULL;
};

template <class T>
Stack<T>::~Stack() {
  std::cout<<"Destructor"<<std::endl;
  delete this->top;
};

template <class T>
void Stack<T>::push(T data) {
  Node<T> *temp = new Node<T>;
  if(temp == NULL) {
    std::cout<<"Stack overflow"<<std::endl;
    return;
  };
  temp->data = data;
  temp->next = top;
  top = temp;
};

template <class T>
T Stack<T>::pop() {
  if (this->top == NULL) {
    std::cout<<"Stack underflow"<<std::endl;
    return -1;
  };
  Node<T> *temp = this->top;
  T data;
  data = this->top->data;
  this->top = this->top->next;
  delete temp;
  return data;
};

template <class T>
void Stack<T>::display() {
  Node<T> *p = this->top;
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

template <class T>
T Stack<T>::peek(int index) {
  Node<T> *p = this->top;
  for (int i = 1; p && i < index; ++i) p = p->next;
  if (!p) return -1;
  return p->data;
};

template <class T>
T Stack<T>::stackTop() {
  return this->top == NULL ? -1 : this->top->data;
};

template <class T>
bool Stack<T>::isEmpty() {
  return this->top == NULL;
};

template <class T>
bool Stack<T>::isFull() {
  Node<T> *t = new Node<T>;
  return t == NULL;
};