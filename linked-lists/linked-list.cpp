#include <iostream>

struct Node {
  int data;
  struct Node * next;
};

int main() {
  struct Node *head;

  // in C
  head = (struct Node *)malloc(sizeof(struct Node));

  // in C++
  // head = new Node;

  head->data = 10;
  head->next = 0;

  return 0;
}