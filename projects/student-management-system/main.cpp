#include <iostream>

#include "student/student.h"
#include "utils/utils.h"

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