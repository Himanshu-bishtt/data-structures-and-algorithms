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