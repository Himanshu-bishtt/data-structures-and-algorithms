#include <iostream>
#include <stdlib.h>

struct Node {
  int data;
  struct Node * next;
} *first;

/**
 * 
 * Creating a new linked list by taking an array and number of elements as arguments.
 * 
 * We create a first node and intialize its value. Then we loop over the array and create other nodes of the linked list.
 * 
*/
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

/**
 * Iterative display of all the nodes of the linked list by taking head pointer as argument
*/
void display(struct Node *p) {
  std::cout<<"-----------------------------------------------------------"<<std::endl;
  while (p != NULL) {
    printf("Data: %d, Address: %p, Next: %p\n", p->data, p, p->next);
    p = p->next;
  };
  std::cout<<"-----------------------------------------------------------"<<std::endl;
};

/**
 * Recursive display of all the nodes of the linked list by taking head pointer as argument
*/
void recursive_display(struct Node *p) {
  if (p != NULL) {
    recursive_display(p->next);
    printf("Data: %d, Address: %p, Next: %p\n", p->data, p, p->next);
  }; 
};

/**
 * Iteratively couting number of nodes in a linked list by taking head pointer as argument
*/
int count_nodes(struct Node *p) {
  int count = 0;
  while(p != NULL) {
    count++;
    p = p->next;
  };
  return count;
};

/**
 * Recursively couting number of nodes in a linked list by taking head pointer as argument
*/
int recursive_count_nodes(struct Node *p) {
  if (p != NULL) return recursive_count_nodes(p->next)+1;
  return 0;
};

/**
 * Iterative sum of every node's data of the linked list and accepts head pointers as argument
*/
int sum(struct Node *p) {
  int sum = 0;
  while(p != NULL) {
    sum += p->data;
    p = p->next;
  };
  return sum;
};

/**
 * Recursive sum of every node's data of the linked list and accepts head pointers as argument
*/
int recursive_sum(struct Node *p) {
  if (!p) return 0;
  return recursive_sum(p->next)+p->data;
};

/**
 * Iteratively finding a node whose data value is maximum by taking head pointer as argument,
 * and checking for each node linearly.
*/
int max (struct Node *p) {
  int max = p->data;
  while (p != NULL) {
    if (p->data > max)
      max = p->data;
    p = p->next;
  };
  return max;
};

/**
 * Recursively finding a node whose data value is maximum by taking head pointer as argument.
*/
int recursive_max(struct Node *p) {
  if (p == NULL) return 0;
  return p->data > recursive_max(p->next) ? p->data : recursive_max(p->next);
};

/**
 * Interatively finding a node whose data value is minimum by taking head pointer as argument.
*/ 
int min(struct Node *p) {
  int min = p->data;
  while (p != NULL) {
    if (p->data < min)
      min = p->data;
    p = p->next;
  };
  return min;
};

/**
 * Recursively finding a node whose data value is minimum by taking head pointer as argument.
*/ 
int recursive_min(struct Node *p) {
  int min = INT32_MAX;
  if (p == NULL) return min;
  return p->data < recursive_min(p->next) ? p->data : recursive_min(p->next);
};

/**
 * Iterative searching for a node whose data matches with el parameters. Returns the nodes address if found, else 0 or NULL.
*/
struct Node * search(struct Node *p, int el) {
  while(p != NULL) {
    if (p->data == el) return p;
    p = p->next;
  };
  return 0;
};

/**
 * Recursive searching for a node whose data matches with el parameters. Returns the nodes address if found, else 0 or NULL.
*/
struct Node * recursive_search(struct Node *p, int el) {
  if (p == NULL) return 0;
  if (p->data == el) return p;
  return recursive_search(p->next, el);
};


/**
 * Optimized linear search by moving the found node as the first node in the linked list. 
 * 
 * In this method, tail pointer is used which is one node behind the p pointer which helps us to move the found node to the first position and change the next address to other nodes to correct address.
*/
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