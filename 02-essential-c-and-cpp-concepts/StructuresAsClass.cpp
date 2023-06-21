#include <iostream>

using namespace std;

struct Rectangle {
  int length;
  int breath;
  int area = 0;

  void intitalize(int length, int breath) {
    this->length = length;
    this->breath = breath;
    this->area = this->length * this->breath;
  };

  void changeLength(int length) {
    cout<<"Changing length to " <<length<<endl;
    this->length = length;
    this->area = this->length * this->breath;
  };

  void display() {
    cout<<"Length: "<<this->length<<endl<<"Breath: "<<this->breath<<endl<<"Area: "<<this->area<<endl;
    cout<<"-----------------"<<endl;
  }
};

int main() {
  Rectangle r;

  int l = 0, b = 0;

  cout<<"Enter length: ";
  cin>>l;

  cout<<"Enter breath: ";
  cin>>b;

  r.intitalize(l, b);

  r.display();

  r.changeLength(55);

  r.display();

  r.changeLength(100);

  r.display();

  return 0;
};