#include<iostream>

using namespace std;

int isPrime(int n) {
  if (n == 1 || n == 2) return 1;

  for (int i = 2; i <= n / 2; ++i)
    if (n % i == 0) return 0;

  return 1;
}

int main() {
  FILE *fp;

  fp = fopen("PRIME.txt", "w");

  for (int i = 1; i <= 100; ++i) {
    if (isPrime(i))
      putw(i, fp);
  };

  fclose(fp);

  fp = fopen("PRIME.txt", "r");

  if (fp == NULL) {
    cout<<"Error loading file"<<endl;
    return -1;
  }

  int value;

  while((value = getw(fp)) != EOF)
    cout<<value<<endl;
  
  fclose(fp);

  return 0;
}