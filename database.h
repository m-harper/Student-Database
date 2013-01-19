#ifndef _DATABASE_H
#define _DATABASE_H

#include "student.h"
#include "department.h"
#include "fine.h"
#include <list>

class Database {

public:
	Database() {
	}

	void add_student(Student _student);
	void add_department(Department _dept);
	void add_fine(Fine _fine);

private:
	std::list<Student> student_list;
	std::list<Department> dept_list;
	std::list<Fine> fine_list;

};

#endif
