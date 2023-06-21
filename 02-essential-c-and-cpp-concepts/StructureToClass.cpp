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

    int area() {
      return this->length * this->breath;
    };

    void changeLength(int length) {
      this->length = length;
    };

    void changeBreath(int breath) {
      this->breath = breath;
    };
};

int main() {
  Rectangle r(10,5);

  cout<<"Area: "<<r.area()<<endl;

  r.changeLength(20);
}