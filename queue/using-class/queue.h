#include <iostream>

class Queue {
  private: 
    int size;
    int front;
    int rear;
    int *q;

  public:
    Queue(int size) {
      this->size = size;
      this->front = this->rear = -1;
      this->q = new int[this->size];
    };

    ~Queue() {
      delete []this->q;
    };

    void enqueue(int data);
    int dequeue();
    int length();
    void display();
    bool isEmpty();
    bool isFull();
    int first();
    int last();
};

void Queue::enqueue(int data) {
  if (this->rear == this->size - 1) {
    std::cout<<"Queue overflow"<<std::endl;
    return;
  };
  this->q[++this->rear] = data;
};

int Queue::dequeue() {
  if (this->front == this->rear) {
    std::cout<<"Queue underflow"<<std::endl;
    return -1;
  };
  this->front++;
  int data = this->q[this->front];
  this->q[this->front] = '\0';
  return data;
};

int Queue::length() {
  int c = 0;
  for (int i = this->front + 1; i <= this->rear; ++i) c++;  
  return c;
};

void Queue::display() {
  std::cout<<"***********************Displaying current queue***********************"<<std::endl;
  for (int i = this->front + 1; i <= this->rear; ++i) {
    printf("%d ", this->q[i]);
  };
  printf("\n");
}

bool Queue::isEmpty() {
  return this->front == this->rear;
};

bool Queue::isFull() {
  return this->rear = this->size - 1;
};

int Queue::first() {
  return this->q[this->front + 1];
};

int Queue::last() {
  return this->q[this->rear];
};
