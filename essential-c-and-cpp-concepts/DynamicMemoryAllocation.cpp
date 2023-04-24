#include <iostream>
#include <stdlib.h>

int * create_space(int n) {
  return (int *)malloc(n*sizeof(int));
};

void enter_elements(int *p, int n) {
  std::cout<<"Enter "<<n<<" elements..."<<std::endl;

  for (int i = 0; i < n; ++i) {
    std::cin>>p[i];
  };
};

void print_elements(int *p, int n) {
  std::cout<<std::endl<<"Printing elements..."<<std::endl;

  for (int i = 0; i < n; ++i) {
    std::cout<<p[i]<<" ";
  };

  std::cout<<std::endl;
}

void free_space(int *p) {
  std::cout<<"Deleting memory"<<std::endl;
  free(p);
  p = NULL;
};


int main() {
  int n;
  char c;
  int *p;

  do {
    std::cout<<"Enter n: ";
    std::cin>>n;

    p = create_space(n);

    enter_elements(p, n);

    print_elements(p, n);

    free_space(p);

    std::cout<<"Enter c: ";

    std::cin>>c;
  } while (c != 'X');

  return 0;
}