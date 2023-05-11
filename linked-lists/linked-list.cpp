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

  head->data = 10;
  head->next = 0;

  return 0;
}