#include <iostream>

struct Node {
  int data;
  struct Node *next;
} *front, *rear;

void create(int arr[], int n) {
  front = new Node;
  front->data = arr[0];
  front->next = NULL;
  rear = front;

  for (int i = 1; i < n; ++i) {
    struct Node *temp = new Node;
    temp->data = arr[i];
    temp->next = NULL;
    rear->next =  temp;
    rear = temp;
  };
}

void display(struct Node *p) {
  if (p == NULL) {
    std::cout<<"Queue is empty"<<std::endl;
    return;
  };
  std::cout<<"***********************Displaying queue elements***********************"<<std::endl;
  while(p != NULL) {
    printf("Data: %d, Address: %p, Next: %p\n", p->data, p, p->next);
    p = p->next;
  };
  std::cout<<std::endl;
};

void enqueue(int data) {
  struct Node *temp = new Node;
  temp->data = data;
  temp->next = NULL;
  
  if (front == NULL) {
    front = rear = temp;
  } else {
    rear->next = temp;
    rear = temp;
  };
};