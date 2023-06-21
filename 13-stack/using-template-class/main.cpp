#include <iostream>
#include "stack.h"

int main() {
  Stack<int> st;

  st.push(100);
  st.push(200);
  st.push(300);
  st.push(400);
  st.push(500);
  st.push(600);

  st.display();

  std::cout<<"Deleted "<<st.pop()<<std::endl;

  st.display();
};