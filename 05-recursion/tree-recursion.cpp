#include <iostream>

void fun(int n) {
  if (n>0) {
    printf("%d ", n);
    fun(n-1);
    fun(n-1);
  };
};

int main() {
  int x = 3;
  fun(3);
  printf("\n");
  return 0;
}