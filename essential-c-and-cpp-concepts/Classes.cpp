#include <iostream>

using namespace std;

class Rectangle {
  private: 
    int length;
    int breath;

  public:
    Rectangle(int length, int breath) {
      this->length = length;
      this->breath = breath;
    };

    int area();

    int perimeter();

    int getLength() {return this->length;};

    int getBreath() {return this->breath;}

    void setLength(int length) {this->length = length;};

    void setBreath(int breath) {this->breath = breath;};

    ~Rectangle();
};

int Rectangle::area() {
  return this->length * this->breath;
};

int Rectangle::perimeter() {
  return 2*(this->length + this->breath);
};

Rectangle::~Rectangle() {
  cout<<"Deleting rectangle object from memory!"<<endl;
};

int main() {
  Rectangle r(10, 5);

  cout<<r.area()<<endl;
  cout<<r.perimeter()<<endl;
}