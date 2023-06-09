#include <iostream>
#include <stdlib.h>

struct Node {
  int data;
  struct Node * next;
} *first, *last, *third;

/**
 * 
 * Creating a new linked list by taking an array and number of elements as arguments.
 * 
 * We create a first node and intialize its value. Then we loop over the array and create other nodes of the linked list.
 * 
*/
struct Node * create(int arr[], int n) {
  struct Node *first, *t, *last;

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

  return first;
};

/**
 * Iterative display of all the nodes of the linked list by taking head pointer as argument
*/
void display(struct Node *p) {
  std::cout<<"-----------------------------------------------------------"<<std::endl;
  if (p == NULL) {
    std::cout<<"Linked list is empty!!"<<std::endl;
    return;
  };
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
};

void insert_at_beginning(int data) {
  struct Node *t = (struct Node *)malloc(sizeof(struct Node));
  t->data = data;
  t->next = first;
  first = t;
};

void insert_at_position(int data, int pos) {
  struct Node *p = first;

  struct Node *t = (struct Node *)malloc(sizeof(struct Node));
  t->data = data;
  t->next = NULL;

  for (int i = 0; i < pos - 1; ++i) {
    p = p->next;
  };

  t->next = p->next;
  p->next = t;
};

void insert(int pos, int data) {
  struct Node *t, *p;
  
  p = first;
  
  if (pos < 0 || pos > count_nodes(p)) {
    std::cout<<pos<<": Invalid position!!"<<std::endl;
    return;
  };
  
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = data;


  if (pos == 0) {
    t->next = first;
    first = t;
  } else {
    for (int i = 0; i < pos - 1; ++i)
      p = p->next;

    t->next = p->next;
    p->next = t;
  };
};

/**
 * 
 * Space Complexity: O(1)
 * Time Complexity: O(1)
 * 
*/
int delete_at_begining() {
  struct Node *t = first;
  first = first->next;
  int data = t->data;
  free(t);
  return data;
};

/**
 * 
 * Space Complexity: O(1)
 * Time Complexity: O(n)
 * 
*/
int delete_at_end() {
  struct Node *p = first;
  struct Node *t = first;

  while (p->next != NULL) {
    t = p;
    p = p->next;
  };

  t->next = NULL;
  int data = p->data;
  free(p);
  return data;
};

/**
 * 
 * Space Complexity: O(1)
 * Time Complexity: O(n)
 * 
*/
int delete_at_pos(int pos) {
  struct Node *p = first;
  struct Node *t;
  int data;

  int count = count_nodes(first);

  if (pos < 0 || pos > count) {
    std::cout<<"Invalid index!!"<<std::endl;
    return -1;
  };

  if (pos == 1) {
    data = delete_at_begining();
    return data;
  }; 
    
  for (int i = 0; i < pos - 1; ++i) {
    t = p;
    p = p->next;
  };
  
  t->next = p->next;
  data = p->data;
  free(p);

  return data;
};

/**
 * 
 * Space Complexity: O(1)
 * Time Complexity: O(1)
 * 
*/
void insert_last(int data) {
  struct Node *t;

  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = data;
  t->next = NULL;

  if (first == NULL) {
    first = last = t;
    return;
  };

  last->next = t;
  last = t;
};

/**
 * 
 * Space Complexity: O(1)
 * Time Complexity: O(n)
 * 
*/
void insert_in_sorted_list(struct Node *p, int data) {
  struct Node *t, *trail;

  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = data;
  t->next = NULL;

  if (first == NULL) {
    first = t;
    return;
  };

  if (p->data > data) {
    t->next = p;
    first = t;
    return;
  };

  while (p && p->data < data) {
    trail = p;
    p = p->next;
  };

  t->next = trail->next;
  trail->next = t;
};

/**
 * 
 * Space Complexity: O(1)
 * Time Complexity: O(n)
 * 
*/
bool is_sorted(struct Node *p) {
  int x = INT32_MIN;
  bool sorted = true;

  while(p != NULL) {
    if (p->data < x) return false;
    x = p->data;
    p = p->next;
  };
  
  return sorted;
};

/**
 * 
 * Space Complexity: O(1)
 * Time Complexity: O(n)
 * 
*/
void remove_duplicates_from_sorted_list(struct Node *p) {
  struct Node *q = p->next;

  if (is_sorted(first)) {
    while(q != NULL) {
      if (q->data == p->data) {
        p->next = q->next;
        delete q;
        q = p->next;
      } else {
        p = q;
        q = q->next;
      };
    };
  } else {
    std::cout<<"List is not sorted!!"<<std::endl;
    return;
  };

  delete q;
};

/**
 * 
 * Space Complexity: O(n)
 * Time Complexity: O(n)
 * 
*/
void reverse_list(struct Node *p) {
  int count = count_nodes(p);

  int arr[count];

  int i = 0;

  while (p != NULL) {
    arr[i] = p->data;
    p = p->next;
    i++;
  };

  i = count - 1;
  p = first;
  
  while (p != NULL) {
    p->data = arr[i];
    p = p->next;
    i--;
  };
};

/**
 * 
 * This is much more efficient way of reversing a linked list than reversing data element of the linked list.
 * 
 * Space Complexity: O(1)
 * Time Complexity: O(n)
 * 
*/
void reverse_list_sliding_pointers(struct Node *p) {
  struct Node *q, *r;
  q = r = NULL;

  while (p != NULL) {
    r = q;
    q = p;
    p = p->next;
    q->next = r; 
  };

  first = q;
};

void recursive_reverse_list(struct Node *q, struct Node *p) {
  if (p != NULL) {
    recursive_reverse_list(p, p->next);
    p->next = q;
  } else {
    first = q;
  };
};

void concat_linked_lists(struct Node *ll1, struct Node *ll2) {
  while(ll1->next != NULL) {
    ll1 = ll1->next;
  };
  ll1->next = ll2;
  ll2 = NULL;
};

void merging(struct Node *first, struct Node *second) {
  struct Node *last;

  if (first->data < second->data) {
    third = last = first;
    first = first->next;
    third->next = NULL;
  } else {
    third = last = second;
    second = second->next;
    third->next = NULL;
  };

  while (first && second) {
    if (first->data < second->data) {
      last->next = first;
      last = first;
      first = first->next;
      last->next  = NULL;
    } else {
      last->next = second;
      last = second;
      second = second->next;
      last->next = NULL;
    };
  };

    if (first != NULL) last->next = first;
    else last->next = second;
};

bool isLoop(struct Node *p) {
  struct Node *q, *r;

  q = r = p;

  do {
    q = q->next;
    r = r->next;
    r = r->next != NULL ? r->next : NULL; 
  } while (q && r && q != r);

  return q == r ? true : false;
};