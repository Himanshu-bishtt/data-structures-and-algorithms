#include <iostream>

int main() {
  char expr[] = "a-bn!log*+";

  for (int i = 0; expr[i] != '\0'; ++i) {
    std::cout<<expr[i]<<std::endl;
  };

  return 0;
}