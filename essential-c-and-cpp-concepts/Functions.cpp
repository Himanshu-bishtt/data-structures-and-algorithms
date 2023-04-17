#include <iostream>

using namespace std;

// call by value
int add(int x, int y) {
  return x + y;
}

int main() {
  int x, y;

  cout<<"Enter x: ";
  cin>>x;

  cout<<"Enter y: ";
  cin>>y;

  int sum = add(x,y);

  cout<<"Sum: "<<sum<<endl;

  return 0;
}