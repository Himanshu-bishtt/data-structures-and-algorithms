#include <iostream>
#include <stdlib.h>

#include "util.h"

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
  
  int length = 7;

  int arr[length] = {32, 1321, 54, 10, 23, 56, 88};

  create(arr, length);

  // for (int i = 0; i < length; ++i)
  //   insert(i, arr[i]);

  display(first);

  delete_at_begining();

  display(first);

  // RDisplay(first);

  /*
  std::cout<<"Total nodes: "<<count_nodes(first)<<std::endl;
  std::cout<<"Total nodes: "<<recursive_count_nodes(first)<<std::endl;
  std::cout<<"Sum: "<<sum(first)<<std::endl;
  std::cout<<"Sum: "<<recursive_sum(first)<<std::endl;
  std::cout<<"Max element is: "<<max(first)<<std::endl;
  std::cout<<"Max element is: "<<recursive_max(first)<<std::endl;
  std::cout<<"Min element is: "<<min(first)<<std::endl;
  std::cout<<"Min element is: "<<recursive_min(first)<<std::endl;

  struct Node *p = search(first, 119);
  struct Node *p1 = recursive_search(first, 119);
  
  if (!p) std::cout<<"Element not found"<<std::endl;
  else std::cout<<p->data<<" found at address: "<<p<<std::endl;

  if (!p1) std::cout<<"Element not found"<<std::endl;
  else std::cout<<p1->data<<" found at address: "<<p1<<std::endl;

  struct Node *temp = move_to_head_searching(first, 119);

  temp = move_to_head_searching(first, 23);

  display(first);
  */

  return 0;
}