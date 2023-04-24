#include <iostream>

class Student {
  private:
    std::string name;
    int age;
    int roll_number;
  
  public:
    Student(std::string name, int age, int roll_number) {
      this->name = name;
      this->age = age;
      this->roll_number = roll_number;
    };

    std::string get_name() {
      return this->name;
    };

    int get_age() {
      return this->age;
    };

    int  get_roll_number() {
      return this->roll_number;
    };
};