#ifndef _DATABASE_H
#define _DATABASE_H

#include "student.h"
#include "department.h"
#include "fine.h"
#include <list>
#include <iostream>
#include <sstream>

class Database {

public:
	Database() {
	}

	void add_student(Student _student);
	void add_department(Department _dept);
	void add_fine(Fine _fine);

	void add_student(std::string _student);
	void add_department(std::string _dept);
	void add_fine(std::string _fine);

	Student find_student(int);

	void process_payment(std::string);

	Student rand_stu() {
		return *(student_list.front());
	}

	Department rand_dept() {
		return *(dept_list.front());
	}

	Fine rand_fine() {
		return *(fine_list.front());
	}

	int get_student_size() {
		return student_list.size();
	}

	int get_dept_list_size() {
		return dept_list.size();
	}

	int get_fine_list_size() {
		return fine_list.size();
	}

private:
	std::list<Student*> student_list;
	std::list<Department*> dept_list;
	std::list<Fine*> fine_list;
	
	int string_to_int(std::string);
	double string_to_double(std::string);
	std::string get_token(std::string&);
};

#endif
