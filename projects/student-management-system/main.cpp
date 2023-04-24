#include <iostream>

#include "student/student.h"

std::string get_student_name() {
  std::string name;

  std::cout<<"Enter student name: ";

  getline(std::cin, name);

  return name;
};

int get_student_age() {
  std::cout<<"Enter student age: ";

  int age;

  std::cin>>age;

  return age;
};

int get_student_roll_number() {
  std::cout<<"Enter student roll_number: ";

  int roll_number;

  std::cin>>roll_number;

  return roll_number;
}

int main() {
  std::string name = get_student_name();
  int age = get_student_age();
  int roll_number = get_student_roll_number();

  Student s1(name, age, roll_number);

  std::cout<<s1.get_name()<<std::endl;
  std::cout<<s1.get_age()<<std::endl;
  std::cout<<s1.get_roll_number()<<std::endl;

  return 0;
}