#include <iostream>
#include <stdlib.h>

#include "util.h"

int count_nodes(struct Node *p) {
  int count = 0;
  while(p != NULL) {
    count++;
    p = p->next;
  };
  return count;
};

int R_count_nodes(struct Node *p) {
  // if (p == NULL) return 0;
  // else return R_count_nodes(p->next)+1;

  if (p != NULL) return R_count_nodes(p->next)+1;
  return 0;
}

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

  display(first);

  // RDisplay(first);

  std::cout<<"Total nodes: "<<count_nodes(first)<<std::endl;
  std::cout<<"Total nodes: "<<R_count_nodes(first)<<std::endl;

  return 0;
}