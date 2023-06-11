#include <iostream>

struct Queue {
  int size;
  int front;
  int rear;
  int *q;
} queue;

void initialize(int size) {
  queue.size = size;
  queue.front = queue.rear = 0;
  queue.q = new int[queue.size];
};

void enqueue(int data) {
  if ((queue.rear + 1)%queue.size == queue.front) {
    std::cout<<"Queue overflow, cannot insert "<<data<<std::endl;
    return;
  };
  queue.rear = (queue.rear+1)%queue.size;
  queue.q[queue.rear] = data;
};

int dequeue()  {
  if (queue.rear == queue.front) {
    std::cout<<"Queue underflow"<<std::endl;
    return -1;
  };
  int data;
  queue.front = (queue.front+1)%queue.size;
  data = queue.q[queue.front];
  return data;
};

void display() {
  std::cout<<"*****************************Displaying queue elements****************************"<<std::endl;
  int i = queue.front + 1;
  do {
    printf("%d ", queue.q[i]);
    i = (i+1)%queue.size;
  } while (i != (queue.rear+1)%queue.size);

  std::cout<<std::endl;
};