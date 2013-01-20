#include "database.h"

void Database::add_student(Student _student) {
	Student* student = new Student(_student);
	student_list.push_back(student);
}

void Database::add_department(Department _dept) {
	Department* department = new Department(_dept);
	dept_list.push_back(department);
}

void Database::add_fine(Fine _fine) {
	Fine* fine = new Fine(_fine);
	fine_list.push_back(fine);
}


