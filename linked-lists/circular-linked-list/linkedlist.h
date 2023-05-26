#include <iostream>

struct Node {
  int data;
  struct Node *next;
} *head, *tail;

void create(int arr[], int n) {
  struct Node *t;

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
  std::cout<<"********************************************************************"<<std::endl;
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

int count(struct Node *p) {
  int count = 0;

  do {
    count++;
    p = p->next;
  } while (p != head);

  return count;
};

void insert(struct Node *p, int index, int data) {
  struct Node *temp;

  int length = count(head);

  if (index <= 0 || index > length) {
    std::cout<<"INVALID INDEX "<<index<<std::endl;
    return;
  };

  temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = NULL;

  if (index == 1) {
    // insert beginning
    temp->next = head;
    head = temp;
    tail->next = head;
  } else {
    // insert at pos
    for (int i = 1; i < index; ++i)
      p = p->next;
    temp->next = p->next;
    p->next = temp;
  };

  if (p == tail) {
    tail = temp;
  };
};