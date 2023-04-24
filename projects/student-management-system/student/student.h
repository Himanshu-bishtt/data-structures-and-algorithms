#include <iostream>

class Student {
  private:
    std::string name;
    int age;
    int roll_number;
  
  public:
    Student() {
      this->name = "John Doe";
      this->age = 0;
      this->roll_number = 0;
    };

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

    void set_name(std::string name) {
      this->name  = name;
    };

    void set_age(int age) {
      this->age = age;
    };

    void set_roll_number(int roll_number) {
      this->roll_number = roll_number;
    };
};