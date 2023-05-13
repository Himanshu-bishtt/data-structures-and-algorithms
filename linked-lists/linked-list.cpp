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
  int arr[5] = {32, 12, 54, 66, 80};

  create(arr, 5);

  display(first);

  // RDisplay(first);

  std::cout<<"Total nodes: "<<count_nodes(first)<<std::endl;
  std::cout<<"Total nodes: "<<recursive_count_nodes(first)<<std::endl;
  std::cout<<"Sum: "<<sum(first)<<std::endl;
  std::cout<<"Sum: "<<recursive_sum(first)<<std::endl;

  return 0;
}