#include <iostream>

using namespace std;

// call by value
int add(int x, int y) {
  return x + y;
}

void swap(int x, int y) {
  int temp;
  temp = x;
  x = y;
  y = temp;
}

void swapAdd(int *x, int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void swapRef(int &x, int &y) {
  int temp;
  temp = x;
  x = y;
  y = temp;
}

int main() {
  int num1, num2;

  cout<<"Enter num1: ";
  cin>>num1;

  cout<<"Enter num2: ";
  cin>>num2;

  
  cout<<"Before swapping"<<endl;
  cout<<num1<<", "<<num2<<endl;
  swapRef(num1, num2);

  cout<<"After swapping"<<endl;
  cout<<num1<<", "<<num2<<endl;

  return 0;
}