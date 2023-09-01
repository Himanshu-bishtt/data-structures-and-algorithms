#include <iostream>

void fib_loop(int x) {
  int first = 0, second = 1;
  int third;

  printf("Fib using iteration\n");
  printf("%d %d ", first, second);

  for (int i = 1; i <= x; ++i) {
    third = first + second;
    printf("%d ", third);
    first = second;
    second = third;
  };
  printf("\n");
};

int fib_loop2(int n) {
  if (n <= 1) return n;
  int first = 0, second = 1, third = 0;

  for (int i = 2; i <= n; ++i) {
    third = first + second;
    first = second;
    second = third;
  }
  return third;
}

int fib_recursion(int n) {
  if (n == 0 || n == 1) return n;
  return fib_recursion(n-2)+fib_recursion(n-1);
};

int F[10];
int fib_recursion2(int n) {
  if (n <= 1) {
    // F[n] = n;
    // return n;
    
    // short circuit evaluation
    return (F[n] = n) && n;
  }
  if (F[n-2] == -1)
    F[n-2] = fib_recursion2(n-2);
  if (F[n-1] == -1)
    F[n-1] = fib_recursion2(n-1);
  F[n] = F[n-2]+F[n-1];
  return F[n-2]+F[n-1];
}

int main() {
  int n = 10;
  for (int i = 0; i < 10; ++i)
    F[i] = -1;

  printf("Fib using loop\n");
  printf("%d \n", fib_loop2(n));
  printf("Fib using recursion\n");
  printf("%d \n", fib_recursion(n));
  printf("Fib using recursion\n");
  printf("%d \n", fib_recursion2(n));


  return 0;
}