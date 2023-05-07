#include <iostream>

int * create_array(int n) {
  return (int *)malloc(n * sizeof(int));
};

void get_values(int *p, int n) {
  std::cout<<"Insert values into array..."<<std::endl;
  for (int i = 0; i < n; ++i) {
    std::cout<<"Enter value "<<i+1<<": ";
    std::cin>>p[i];
  };
};

void print_values(int *p, int n) {
  std::cout<<"Printing values..."<<std::endl;
  for (int i = 0; i < n; ++i) {
    std::cout<<p[i]<<" ";
  };
  std::cout<<std::endl;
};

void copy_array_values(int *src, int *dest, int sn) {
  for (int i = 0; i < sn; ++i) {
    dest[i] = src[i];
  };
};

int main() {
  int n1 = 5;

  int *p = create_array(n1);

  get_values(p, n1);

  print_values(p, n1);

  std::cout<<"Increasing array size...."<<std::endl;

  int n2 = 10;

  int *q = create_array(n2);

  copy_array_values(p, q, n1);

  delete []p;

  p = q;

  q = NULL;

  print_values(p, n2);

  return 0;
}