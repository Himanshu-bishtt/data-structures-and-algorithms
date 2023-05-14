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
  std::cout<<"-----------------------------------------------------------"<<std::endl;
  while (p != NULL) {
    printf("Data: %d, Address: %p, Next: %p\n", p->data, p, p->next);
    p = p->next;
  };
  std::cout<<"-----------------------------------------------------------"<<std::endl;
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

int max (struct Node *p) {
  int max = p->data;
  while (p != NULL) {
    if (p->data > max)
      max = p->data;
    p = p->next;
  };
  return max;
};

int recursive_max(struct Node *p) {
  if (p == NULL) return 0;
  return p->data > recursive_max(p->next) ? p->data : recursive_max(p->next);
};

int min(struct Node *p) {
  int min = p->data;
  while (p != NULL) {
    if (p->data < min)
      min = p->data;
    p = p->next;
  };
  return min;
};

int recursive_min(struct Node *p) {
  int min = INT32_MAX;
  if (p == NULL) return min;
  return p->data < recursive_min(p->next) ? p->data : recursive_min(p->next);
};

struct Node * search(struct Node *p, int el) {
  while(p != NULL) {
    if (p->data == el) return p;
    p = p->next;
  };
  return 0;
};

struct Node * recursive_search(struct Node *p, int el) {
  if (p == NULL) return 0;
  if (p->data == el) return p;
  return recursive_search(p->next, el);
};

struct Node * move_to_head_searching(struct Node *p, int el) {
  struct Node * tail;
  while(p != NULL) {
    if (p->data == el) {
      tail->next = p->next;
      p->next = first;
      first = p;
      return p;
    };
    tail = p;
    p = p->next;
  };
  return 0;
}