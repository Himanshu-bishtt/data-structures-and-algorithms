#include <iostream>

// MORE EFFICIENT

// int power_recursion(int m, int n) {
//   if (n == 0) return 1;
//   if(n%2 == 0) return power_recursion(m*m, n/2);
//   return m*power_recursion(m*m, (n-1)/2);
// };

int power_recursion(int m, int n) {
  if (n == 0) return 1;
  return power_recursion(m, n-1)*m;
};

int power_loop(int m, int n) {
  int power = 1;
  for(int i = 1; i <= n; ++i)
    power *= m;
  return power;
};

int main() {
  int x = 5, y = 5;
  printf("Power: %d\n", power_recursion(x, y));
  printf("Power: %d\n", power_loop(x, y));
  return 0;
}