#include <iostream>
#include <stdlib.h>

struct Node {
  int data;
  struct Node * next;
} *first;

void create(int arr[], int n) {
  struct Node *t, *last;

  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = arr[0];
  first->next = NULL;
  last = first;

  for (int i = 1; i < n; ++i) {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = arr[i];
    t->next = NULL;
    last->next = t;
    last = t;
  };
};

void display(struct Node *p) {
  while (p != NULL) {
    printf("Data: %d, Address: %p, Next: %p\n", p->data, p, p->next);
    p = p->next;
  };
};

void recursive_display(struct Node *p) {
  if (p != NULL) {
    recursive_display(p->next);
    printf("Data: %d, Address: %p, Next: %p\n", p->data, p, p->next);
  }; 
};

int count_nodes(struct Node *p) {
  int count = 0;
  while(p != NULL) {
    count++;
    p = p->next;
  };
  return count;
};

int recursive_count_nodes(struct Node *p) {
  // if (p == NULL) return 0;
  // else return recursive_count_nodes(p->next)+1;

  if (p != NULL) return recursive_count_nodes(p->next)+1;
  return 0;
};

int sum(struct Node *p) {
  int sum = 0;
  while(p != NULL) {
    sum += p->data;
    p = p->next;
  };
  return sum;
};

int recursive_sum(struct Node *p) {
  if (!p) return 0;
  return recursive_sum(p->next)+p->data;
};