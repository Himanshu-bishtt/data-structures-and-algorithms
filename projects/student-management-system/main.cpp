#include <iostream>
#include "student/student.h"
#include "utils/utils.h"

int main() {
  int total_students;

  std::cout<<"Enter total students: ";

  std::cin>>total_students;

  Student *students;

  students = (Student *)calloc(total_students, sizeof(Student));

  for (int i = 0; i < total_students; ++i) {
    students[i].set_name(get_student_name());
    
    students[i].set_age(get_student_age());

    students[i].set_roll_number(get_student_roll_number());
  };

  print_all_students(students, total_students);

  free(students);

  students = NULL;

  return 0;
}