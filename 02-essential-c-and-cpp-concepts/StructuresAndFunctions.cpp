#include <iostream>

using namespace std;

struct Rectangle {
  int length;
  int breath;
};

void initalize(struct Rectangle *r, int length, int breath) {
  r->length = length;
  r->breath = breath;
};

int area(struct Rectangle r) {
  return r.length * r.breath;
};

void changeLength(struct Rectangle *r, int length) {
  r->length = length;
};

int main() {
  struct Rectangle r;

  initalize(&r, 10, 5);

  int area_of_rectangle = area(r);

  cout<<"Area: "<<area_of_rectangle<<endl;

  changeLength(&r, 20);

  cout<<"Length: "<<r.length<<endl;
  cout<<"Breath: "<<r.breath<<endl;

  return 0;
}