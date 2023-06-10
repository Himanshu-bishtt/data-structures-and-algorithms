#include <iostream>

template <class T>
class Queue {
  private: 
    int size;
    int front;
    int rear;
    T *q;

  public:
    Queue(int size) {
      this->size = size;
      this->front = this->rear = -1;
      this->q = new T[this->size];
    };

    ~Queue() {
      delete []this->q;
    };

    void enqueue(T data);
    T dequeue();
    int length();
    void display();
    bool isEmpty();
    bool isFull();
    T first();
    T last();

    int getSize() {return this->size;};
    int getFront() {return this->front;};
    int getRear() {return this->rear;};
};

template <class T>
void Queue<T>::enqueue(T data) {
  if (this->rear == this->size - 1) {
    std::cout<<"Queue overflow"<<std::endl;
    return;
  };
  this->rear++;
  this->q[this->rear] = data;
};

template <class T>
T Queue<T>::dequeue() {
  if (this->front == this->rear) {
    std::cout<<"Queue underflow"<<std::endl;
    return -1;
  };
  this->front++;
  T data = this->q[this->front];
  this->q[this->front] = '\0';
  return data;
};

template <class T>
int Queue<T>::length() {
  int c = 0;
  for (int i = this->front + 1; i <= this->rear; ++i) c++;  
  return c;
};

template <class T>
void Queue<T>::display() {
  std::cout<<"***********************Displaying current queue***********************"<<std::endl;
  for (int i = this->front + 1; i <= this->rear; ++i) {
    std::cout<<this->q[i]<<" ";
  };
  printf("\n");
}

template <class T>
bool Queue<T>::isEmpty() {
  return this->front == this->rear;
};

template <class T>
bool Queue<T>::isFull() {
  return this->rear == this->size - 1;
};

template <class T>
T Queue<T>::first() {
  return this->q[this->front + 1];
};

template <class T>
T Queue<T>::last() {
  return this->q[this->rear];
};
