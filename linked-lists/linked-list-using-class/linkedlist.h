#include "node.h"

template<class T>
class LinkedList {
  private:
    Node<T> *first;
    Node<T> *last;

  public:
    LinkedList() {
      this->first = NULL;
    };

    LinkedList(T arr[], int n);

    ~LinkedList();

    void display();

    void insert(int index, T data);

    T delete_el(int index);

    int length();

    Node<T> * getFirst() {
      return this->first;
    };

    Node<T> * getLast() {
      return this->last;
    };
};

template <class T>
LinkedList<T>::LinkedList(T arr[], int n) {
  Node<T> *temp;

  this->first = new Node<T>;
  this->first->data = arr[0];
  this->first->next = NULL;
  this->last = first;

  for (int i = 1; i < n; ++i) {
    temp = new Node<T>;
    temp->data = arr[i];
    temp->next = NULL;
    this->last->next = temp;
    this->last = temp;
  };
};

template <class T>
LinkedList<T>::~LinkedList() {
  std::cout<<"Destructor called"<<std::endl;

  Node<T> *p = this->first;

  while(first) {
    first = first->next;
    delete p;
    p = first;
  };
};

template <class T>
void LinkedList<T>::display() {
  std::cout<<"******************************************************"<<std::endl;
  Node<T> *p = this->first;
  while (p != NULL) {
    printf("Data: %f, Address: %p, Next: %p\n", p->data, p, p->next);
    p = p->next;
  };
  std::cout<<"******************************************************"<<std::endl;
};

template <class T>
void LinkedList<T>::insert(int index, T data) {
  Node<T> *temp, *p = this->first;
  int length = this->length();

  if (index < 0 || index > length) return;

  temp = new Node<T>;
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

template <class T>
T LinkedList<T>::delete_el(int index) {
  if (this->first == NULL) return -1;

  int data;

  Node<T> *p = this->first, *q;

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

template <class T>
int LinkedList<T>::length() {
  Node<T> *t = this->first;

  int count = 0;

  while (t != NULL) {
    count++;
    t = t->next;
  };

  return count;
};