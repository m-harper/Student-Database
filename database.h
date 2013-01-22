#ifndef _DATABASE_H
#define _DATABASE_H

#include "student.h"
#include "department.h"
#include "fine.h"
#include "util.h"
#include <list>
#include <iostream>

class Database {

public:
	Database() {
	}
	~Database() {
		for (std::list<Student*>::iterator it = student_list.begin(); it != student_list.end(); ++it) {
			Student* student = *it;
			delete student;
		}
		for(std::list<Department*>::iterator it = dept_list.begin(); it != dept_list.end(); ++it) {
			Department* dept = *it;
			delete dept;
		}
		for (std::list<Fine*>::iterator it = fine_list.begin(); it != fine_list.end(); ++it) {
			Fine* fine = *it;
			delete fine;
		}

	}

	void add_student(Student _student);
	void add_department(Department _dept);
	void add_fine(Fine _fine);

	void add_student(std::string _student);
	void add_department(std::string _dept);
	void add_fine(std::string _fine);

	Student* find_student(int);
	Department* find_department(int);

	void process_payment(std::string);
	void print_student_report(std::string);
	void print_department_report(std::string);
	void print_major_report(std::string);

private:
	Util util;
	std::list<Student*> student_list;
	std::list<Department*> dept_list;
	std::list<Fine*> fine_list;
};

#endif
