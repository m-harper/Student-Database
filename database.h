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
	}

	void add_student(Student _student);
	void add_department(Department _dept);
	void add_fine(Fine _fine);

	void add_student(std::string _student);
	void add_department(std::string _dept);
	std::string add_fine(std::string _fine);

	Student* find_student(int);
	Department* find_department(int);

	std::string process_payment(std::string);
	void print_student_report(std::string);
	void print_department_report(std::string);
	void print_major_report(std::string);

	void set_date(Date _date) {
		today = Date(_date);
	}

private:
	Util util;
	Date today;
	std::list<Student*> student_list;
	std::list<Department*> dept_list;
};

#endif
