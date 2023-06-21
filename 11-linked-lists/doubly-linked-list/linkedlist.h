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
  if (!p) {
    std::cout<<"Linked list is empty!!"<<std::endl;
    return;
  };
  
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

int delete_el(struct Node *p, int index) {
  int count = length(p);

  if (index <= 0 || index > count) {
    std::cout<<"Invalid index"<<std::endl;
    return -1;
  };

  struct Node *temp = p;
  int data = -1;

  if (index == 1) {
    // remove first node
    first = temp->next;
    data = temp->data;
    if (temp->next) temp->next->prev = NULL;
    delete temp;
  } else {
    // remove any other node
    for (int i = 0; i < index - 1; ++i) {
      p = temp;
      temp = temp->next;
    };

    p->next = temp->next;
    data = temp->data;

    if(temp->next != NULL) 
          temp->next->prev = p;

    delete temp;

    if (index == count) last = p;
  };

  return data;
};

void reverse(struct Node *p) {
  struct Node *temp = NULL;

  while (p != NULL) {
    temp = p->next;
    p->next = p->prev;
    p->prev = temp;
    p = p->prev;

    if (p!= NULL && p->next == NULL) first = p;
  };
};

struct Node * middle_node(struct Node *p) {
  struct Node *temp = p;
  int total = length(p);
  int mid = total / 2;

  for (int i = 1; i <= mid; ++i) {
    temp = temp->next;
  };
  return temp;
};

struct Node * middle_node_single_scan(struct Node *p) {
  struct Node *q = p;

  while (q != NULL) {
    q = q->next;
    
    if (q != NULL) {
      q = q->next;
      p = p->next;
    }
  };

  return p;
};