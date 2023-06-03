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
    if (p == head)
      printf("Data: %d, Address: %p, Next: %p, Prev: %p (HEAD)\n", head->data, head, head->next, head->prev);
    else if (p == tail)
      printf("Data: %d, Address: %p, Next: %p, Prev: %p (TAIL)\n", tail->data, tail, tail->next, tail->prev);
    else
      printf("Data: %d, Address: %p, Next: %p, Prev: %p\n", p->data, p, p->next, p->prev);
    p = p->next;
  } while (p != head);
  std::cout<<"*****************************************************************************"<<std::endl;
};

void insert(struct Node *p, int index, int data) {
  int total = count(p);

  if (index < 0 || index > total) {
    std::cout<<"Invalid index"<<std::endl;
    return;
  };

  Node *temp = new Node;
  temp->data = data;
  temp->prev = NULL;
  temp->next = NULL;

  if (index == 0) {
    // insert at beginning
    temp->next = p;
    p->prev = temp;
    temp->prev = tail;
    tail->next = temp;
    head = temp;
  } else {
    // insert at other position
    for (int i = 1; i < index; ++i)
      p = p->next;
    temp->next = p->next;
    temp->prev = p;
    p->next->prev = temp;
    p->next = temp;
  };

  printf("%d insert at pos %d!!\n", data, index);

  return;
};