#include <iostream>

struct Node {
  struct Node *prev;
  int data;
  struct Node *next;
} *first, *last;

void create(int arr[], int n) {
  struct Node *temp;

  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = arr[0];
  first->prev = NULL;
  first->next = NULL;
  last = first;

  for (int i = 1; i < n; ++i) {
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = arr[i];
    temp->prev = last;
    temp->next = NULL;
    last->next = temp;
    last = temp;
  };
};

void display(struct Node *p) {
  while (p != NULL) {
    printf("Data: %d, Address: %p, Next: %p, Prev: %p\n", p->data, p, p->next, p->prev);
    p = p->next;
  };
  std::cout<<"**********************************************************************************"<<std::endl;
};

int length(struct Node *p) {
  int count = 0;
  while(p != NULL) {
    count++;
    p = p->next;
  };
  return count;
};

void insert(struct Node *p, int index, int data) {
  struct Node *temp, *q;

  int count = length(p);

  if (index <= 0 || index > count) {
    std::cout<<"Invalid index!!"<<std::endl;
    return;
  };

  temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = temp->prev = NULL;

  if (index == 1) {
    // insert at beginning
    temp->prev = NULL;
    temp->next = p;
    p->prev = temp;
    first = temp;
  } else {
    for (int i = 1; i < index; ++i) p = p->next;

    temp->next = p->next;
    temp->prev = p;

    if (p->next != NULL) {
      q = p->next;
      q->prev = temp;
    };
    p->next = temp;

    if (index == count) last = temp;
  };
};