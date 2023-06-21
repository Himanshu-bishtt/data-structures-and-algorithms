#include <iostream>

using namespace std;

template<class T>
class Arithmetic {
  private: 
    T a;
    T b;

  public:
    Arithmetic(T a, T b);

    T add();

    T sub();

    T mul();

    ~Arithmetic() {
      cout<<"Destructor!!"<<endl;
    }
};

template<class T>
Arithmetic<T>::Arithmetic(T a, T b) {
  this->a = a;
  this->b = b;
}

template<class T>
T Arithmetic<T>::add() {
  return this->a + this->b;
};

template<class T>
T Arithmetic<T>::sub() {
  return this->a - this->b;
};

template<class T>
T Arithmetic<T>::mul() {
  return this->a * this->b;
};

int main() {
  Arithmetic<int> obj1(10,5);
  Arithmetic<float> obj2(11.5, 2.1);
  Arithmetic<double>obj3(1,2);

  cout<<obj1.add()<<endl;
  cout<<obj2.add()<<endl;
  cout<<obj3.add()<<endl;

  return 0;
}