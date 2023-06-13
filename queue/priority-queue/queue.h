#include <iostream>

struct Element {
  int data;
  int priority;
};

struct Queue {
  int size;
  int front;
  int rear;
  Element *q;
};

void create(struct Queue *queue, int size) {
  queue->size = size;
  queue->front = queue->rear = -1;
  queue->q = new Element[queue->size];
};

void enqueue(struct Queue *queue, Element elem) {
  if (queue->rear == queue->size - 1) {
    std::cout<<"Queue is full, cannot insert "<<elem.data<<std::endl;
    return;
  };
  queue->rear++;
  queue->q[queue->rear].data = elem.data;
  queue->q[queue->rear].priority = elem.priority;
};

Element * dequeue(struct Queue *queue) {
  Element *elem = new Element;
  if (queue->front == queue->rear) {
    std::cout<<"Queue is empty"<<std::endl;
    return NULL;
  };
  queue->front++;
  elem->data = queue->q[queue->front].data;
  elem->priority = queue->q[queue->front].priority;
  return elem;
};

void display(struct Queue queue) {
  if (queue.front == queue.rear) {
    std::cout<<"Queue is empty"<<std::endl;
    return;
  };

  std::cout<<"************************Displaying queue***********************"<<std::endl;
  for (int i = queue.front+1; i <= queue.rear; ++i)   
    printf("Data: %d, Priority: %d\n", queue.q[i].data, queue.q[i].priority);
};

void insert(struct Queue *q1, struct Queue *q2, struct Queue *q3, struct Element element) {
  if (element.priority == 1)  enqueue(q1, element);
  if (element.priority == 2)  enqueue(q2, element);
  if (element.priority == 3)  enqueue(q3, element);
};

bool isEmpty(struct Queue *q1) {
  return q1->front == q1->rear;
};

Element * delete_el(struct Queue *q1, struct Queue *q2, struct Queue *q3) {
  Element * element;
  if (!isEmpty(q1)) element = dequeue(q1);
  else if (!isEmpty(q2)) element = dequeue(q2); 
  else element = dequeue(q3);
  return element;
};
