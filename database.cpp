#include "database.h"

void Database::add_student(Student _student) {
	student_list.push_back(_student);
}

void Database::add_department(Department _dept) {
	dept_list.push_back(_dept);
}

void Database::add_fine(Fine _fine) {
	fine_list.push_back(_fine);
}
