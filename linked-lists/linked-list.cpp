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

void display2(struct Node *p) {
  if (p != NULL) {
    display2(p->next);
    printf("Data: %d, Address: %p, Next: %p\n", p->data, p, p->next);
  }; 
};

int main() {
  /**
   * 
   * Conditions to check whether head is null
   * 
   * 1. if (head == NULL)
   * 
   * 2. if (head == 0)
   * 
   * 3. if (!head)
   * 
   * Conditions to check whether head is not null
   * 
   * 1. if (head != NULL)
   * 
   * 2. if (head != 0)
   * 
   * 3. if (head)
   * 
  */


  /**
   * 
   * Conditions to check whether head is last node
   * 
   * 1. if (head->next == NULL)
   * 
   * 2. if (head->next == 0)
   * 
   * 3. if (!head->next)
   * 
   * Conditions to check whether head is not last node
   * 
   * 1. if (head->next != NULL)
   * 
   * 2. if (head->next != 0)
   * 
   * 3. if (head->next)
  */
  int arr[5] = {32, 12, 54, 66, 80};

  create(arr, 5);

  // display(first);

  display2(first);

  return 0;
}