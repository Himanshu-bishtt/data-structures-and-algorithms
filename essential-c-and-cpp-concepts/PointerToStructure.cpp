#include <iostream>

using namespace std;

struct Rectangle {
  int length;
  int breath;
};

int main() {
  /*

  struct Rectangle r = {10,5};
  p->length = 15;

  cout<<(*p).length<<endl;
  cout<<(*p).breath<<endl;

  cout<<p->length<<endl;
  cout<<p->breath<<endl;

  cout<<"Area: "<<p->length*p->breath<<endl;
  
  */

  struct Rectangle *p;
  p = (struct Rectangle *)malloc(sizeof(Rectangle));

  p->length = 100;
  p->breath = 2;

  cout<<p->length<<endl;
  cout<<p->breath<<endl;

  cout<<sizeof(p)<<endl;
  cout<<sizeof(Rectangle)<<endl;

  return 0;
}