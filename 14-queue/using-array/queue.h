#include <iostream>

struct Queue {
  int size;
  int front;
  int rear;
  int *q;
} queue;

void initialize(int size) {
  queue.size = size;
  queue.front = queue.rear = -1;
  queue.q = (int *)malloc(size * sizeof(int));
};

/**
 * Insert from rear
 * Time: O(1)
*/
void enqueue(int data) {
  if (queue.rear == queue.size - 1) {
    std::cout<<"Queue overflow! Cannot insert "<<data<<std::endl;
    return;
  };
  queue.rear++;
  queue.q[queue.rear] = data;
};

/**
 * Delete from front
 * Time: O(1)
*/
int dequeue() {
  if (queue.front == queue.rear) {
    std::cout<<"Queue underflow"<<std::endl;
    return -1;
  };
  int data;
  queue.front++;
  data = queue.q[queue.front];
  queue.q[queue.front] = '\0';
  return data;
};

void display() {
  std::cout<<"***********************Displaying current queue***********************"<<std::endl;
  for (int i = queue.front + 1; i <= queue.rear; ++i) {
    printf("%d ", queue.q[i]);
  };
  printf("\n");
};

int length() {
  int c = 0;
  for (int i = queue.front + 1; i <= queue.rear; ++i) c++;
  return c;
};

bool isFull() {
  return queue.rear == queue.size - 1;
};

bool isEmpty() {
  return queue.front == queue.rear;
};