#include <iostream>

int factorial_recursion(int n) {
  if (n == 0) return 1;
  return factorial_recursion(n-1)*n;
};

int factorial_loop(int n) {
  int fact = 1;
  for (int i = 1; i <= n; ++i)
    fact *= i;
  return fact;
}

int main() {
  int x = 5;
  printf("Factorial: %d\n", factorial_recursion(5));
  printf("Factorial: %d\n", factorial_loop(5));
  return 0;
}