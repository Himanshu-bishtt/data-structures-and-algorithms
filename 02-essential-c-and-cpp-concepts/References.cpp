#include <iostream>

using namespace std;

int main() {
  int a = 100;

  int &r = a;

  cout<<a<<endl;
  cout<<r<<endl;

  r++;

  cout<<a<<endl;
  cout<<r<<endl;
  
  int b = 999;

  r = b;

  cout<<a<<endl;
  cout<<b<<endl;
  
  return 0;
}