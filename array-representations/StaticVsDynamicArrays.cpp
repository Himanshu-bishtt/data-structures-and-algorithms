#include <iostream>
#include <stdlib.h>

void print_values(int *p, int n) {
  std::cout<<"Printing array..."<<std::endl;
  for (int i = 0; i < n; ++i) {
    std::cout<<p[i]<<" ";
  };
  std::cout<<std::endl;
}

void get_values(int *p, int n) {
  std::cout<<"Enter values of array...."<<std::endl;
  for (int i = 0; i < n; ++i) {
    std::cout<<"Enter "<<(i+1)<<" value: ";
    std::cin>>p[i];
  };
}

int main() {
  int n;
  std::cout<<"Enter n: ";
  std::cin>>n;

  // static array
  int arr[5];

  // int *p = (int *)malloc(n*sizeof(int));

  // dynamic array
  int *p = new int[n];
  
  get_values(p, n);

  print_values(p, n);

  delete []p;

  return 0;
}