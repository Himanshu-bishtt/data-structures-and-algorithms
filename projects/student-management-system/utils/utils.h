#include <iostream>

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
};