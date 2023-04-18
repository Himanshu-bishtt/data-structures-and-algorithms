#include <iostream>

using namespace std;

struct Rectangle {
  int length;
  int breath;
};

struct Test {
  int arr[5];
  int n;
};

// call by value
int area(struct Rectangle r1) {
  return r1.length * r1.breath;
}

// call by address
int areaAddress(struct Rectangle *r1) {
  return r1->length * r1->breath;
}

void display(struct Test t) {
  cout<<t.n<<endl;

  int length = sizeof(t.arr)/sizeof(t.arr[0]);

  for (int i = 0; i < length; ++i)  
    cout<<t.arr[i]<<" ";

  cout<<endl;
}

struct Rectangle * createRectangle() {
  Rectangle *p;

  // p = (struct Rectangle *)malloc(sizeof(struct Rectangle));
  p = new Rectangle;

  p->length = 22;
  p->breath = 4;

  return p;
}

int main() {
  Rectangle r = {10,5};
  Rectangle *p1, *p2;
  
  p1 = (Rectangle*)malloc(sizeof(Rectangle));

  p1->length = 12;
  p1->breath = 5;

  int result = area(r);
  int result2 = areaAddress(&r);
  int result3 = areaAddress(p1);

  cout<<result<<endl;
  cout<<result2<<endl;
  cout<<result3<<endl;

  Test t = {{1,2,3,4,5}, 10};

  display(t);

  p2 = createRectangle();

  cout<<"Length: "<<p2->length<<endl;
  cout<<"Breath: "<<p2->breath<<endl;

  delete p1, p2;

  return 0;
}