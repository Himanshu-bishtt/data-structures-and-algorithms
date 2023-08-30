#include <iostream>

int sum_recursion(int n) {
  if (n == 0) return 0;
  return sum_recursion(n-1)+n;
};

int sum_formula(int n) {
  return n*(n+1)/2;
};

int sum_loop(int n) {
  int sum = 0;
  for (int i = 1; i <= n; ++i) 
    sum += i;
  return sum;
}

int main() {
  printf("Sum: %d\n", sum_recursion(4));
  printf("Sum: %d\n", sum_formula(4));
  printf("Sum: %d\n", sum_loop(4));
  return 0;
}