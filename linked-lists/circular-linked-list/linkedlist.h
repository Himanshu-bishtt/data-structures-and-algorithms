#include <iostream>

struct Node {
  int data;
  struct Node *next;
} *head;

void create(int arr[], int n) {
  struct Node *t, *tail;

  head = (struct Node *)malloc(sizeof(struct Node));
  head->data = arr[0];
  head->next = NULL;
  tail = head;

  for (int i = 1; i < n; ++i) {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = arr[i];
    t->next = NULL;
    tail->next = t;
    tail = t;
  };

  // use this for making a circular linked list
  tail->next = head;
};

void display(struct Node *p) {
  do {
    printf("Data: %d, Address: %p, Next: %p\n", p->data, p, p->next);
    p = p->next;
  } while (p != head);
};


void recursive_display(struct Node *p) {
  static int flag = 0;
  
  if (p != head || flag == 0) {
    flag = 1;
    printf("Data: %d, Address: %p, Next: %p\n", p->data, p, p->next);
    recursive_display(p->next);
  };

  flag = 0;
};