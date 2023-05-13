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
  
  int length = 8;

  int arr[length] = {32, 1321, 54, 66, 1, 80, 119, 23};

  create(arr, length);

  display(first);

  // RDisplay(first);

  std::cout<<"Total nodes: "<<count_nodes(first)<<std::endl;
  std::cout<<"Total nodes: "<<recursive_count_nodes(first)<<std::endl;
  std::cout<<"Sum: "<<sum(first)<<std::endl;
  std::cout<<"Sum: "<<recursive_sum(first)<<std::endl;
  std::cout<<"Max element is: "<<max(first)<<std::endl;
  std::cout<<"Max element is: "<<recursive_max(first)<<std::endl;
  std::cout<<"Min element is: "<<min(first)<<std::endl;
  std::cout<<"Min element is: "<<recursive_min(first)<<std::endl;

  return 0;
}