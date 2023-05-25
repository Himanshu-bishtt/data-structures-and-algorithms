#include "node.h"

class LinkedList {
  private:
    Node *first;
    Node *last;

  public:
    LinkedList() {
      this->first = NULL;
    };

    LinkedList(int arr[], int n);

    ~LinkedList();

    void display();

    void insert(int index, int data);

    int delete_el(int index);

    int length();

    Node * getFirst() {
      return this->first;
    };

    Node * getLast() {
      return this->last;
    };
};

LinkedList::LinkedList(int arr[], int n) {
  Node *temp;

  this->first = new Node;
  this->first->data = arr[0];
  this->first->next = NULL;
  this->last = first;

  for (int i = 1; i < n; ++i) {
    temp = new Node;
    temp->data = arr[i];
    temp->next = NULL;
    this->last->next = temp;
    this->last = temp;
  };
};

LinkedList::~LinkedList() {
  std::cout<<"Destructor called"<<std::endl;

  Node *p = this->first;

  while(first) {
    first = first->next;
    delete p;
    p = first;
  };
};

void LinkedList::display() {
  std::cout<<"******************************************************"<<std::endl;
  Node *p = this->first;
  while (p != NULL) {
    printf("Data: %d, Address: %p, Next: %p\n", p->data, p, p->next);
    p = p->next;
  };
  std::cout<<"******************************************************"<<std::endl;
};

void LinkedList::insert(int index, int data) {
  Node *temp, *p = this->first;
  int length = this->length();

  if (index < 0 || index > length) return;

  temp = new Node;
  temp->data = data;
  temp->next = NULL;

  if (this->first == NULL) {
    this->first = temp;
    return;
  };

  if (index == 0) {
    temp->next = this->first;
    this->first = temp;
    return;
  };

  for (int i = 0; i < index - 1; ++i) {
    p = p->next;
  };
  temp->next = p->next;
  p->next = temp;
};

int LinkedList::delete_el(int index) {
  if (this->first == NULL) return -1;

  int data;

  Node *p = this->first;
  Node *q;

  int count = this->length();

  if (index < 0 || index > count) return -1;

  if (index == 1) {
    this->first = p->next;
    data = p->data;
    delete p;
    return data;
  };

  for (int i = 0; i < index - 1; ++i) {
    q = p;
    p = p->next;
  };

  q->next = p->next;
  data = p->data;
  delete p;

  return data;
};

int LinkedList::length() {
  Node * t = this->first;

  int count = 0;

  while (t != NULL) {
    count++;
    t = t->next;
  };

  return count;
};