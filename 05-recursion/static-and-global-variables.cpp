#include <iostream>

int fun(int n) {
  if (n > 0) {
    return fun(n-1)+n;
  };
  return 0;
};

int fun2(int n) {
  static int x = 0;
  if (n > 0) {
    x++;
    return fun2(n-1)+x;
  };
  return 0;
}

int main() {
  int x = 5;
  printf("%d\n", fun(x));
  printf("%d\n", fun2(x));

  return 0;
}