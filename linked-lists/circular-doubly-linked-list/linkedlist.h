#include <iostream>

struct Node {
  struct Node *prev;
  int data;
  struct Node  *next;
} *head, *tail;

void create(int arr[], int n) {
  struct Node *temp;

  head = new Node;
  head->prev = NULL;
  head->data = arr[0];
  head->next = NULL;
  tail = head;

  for (int i = 1; i < n; ++i) {
    temp = new Node;
    temp->prev = tail;
    temp->data = arr[i];
    temp->next = NULL;
    tail->next = temp;
    tail = temp;
  };

  tail->next = head;
  head->prev = tail;
};

int count(struct Node *p) {
  int count = 0;
  do {
    count++;
    p = p->next;
  } while (p != head);
  return count;
};

void display(struct Node *p) {
  std::cout<<count(p)<<" Nodes"<<std::endl;
  do {
    printf("Data: %d, Address: %p, Next: %p, Prev: %p\n", p->data, p, p->next, p->prev);
    p = p->next;
  } while (p != head);
  std::cout<<"*****************************************************************************"<<std::endl;
};