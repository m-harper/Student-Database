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

std::string Database::get_token(std::string& full_string) {
	std::string token = full_string.substr(0, full_string.find(' '));
	full_string = full_string.substr(full_string.find(' ') + 1);
	return token;
}

double Database::string_to_double(std::string dub) {
	double converted;
	std::istringstream(dub) >> converted;
	return converted;

}

int Database::string_to_int(std::string num) {
	int converted;
	std::istringstream(num) >> converted;
	return converted;
}

void Database::add_student(std::string _student) {
	std::string student = _student;
	
	int id = string_to_int(get_token(student));

	std::string first_name = get_token(student);
	std::string last_name = get_token(student);
	std::string name = first_name + " " + last_name;
	std::string major = student;

	add_student(Student(id, name, major));	
}

void Database::add_department(std::string _dept) {
	std::string dept = _dept;

	int id = string_to_int(get_token(dept));
	std::string dept_name = dept;

	add_department(Department(id, dept_name));

}

void Database::add_fine(std::string _fine) {
	std::string fine = _fine;

	int student_id = string_to_int(get_token(fine));
	int dept_id = string_to_int(get_token(fine));
	double amount = string_to_double(get_token(fine));
	std::string date = get_token(fine);
	std::string fine_type = fine;

	add_fine(Fine(student_id, dept_id, amount, date, fine_type));
}

void Database::process_payment(std::string _payment) {
	std::string payment = _payment;
	int student_id = string_to_int(get_token(payment));
	double amount = string_to_double(get_token(payment));
	std::string date = payment;

	Student student = find_student(student_id);
	student.pay_fine(amount);

}

Student Database::find_student(int id) {
	
	Student* student;
	for (std::list<Student*>::iterator it = student_list.begin(); it != student_list.end(); ++it) {
		student = *it;	
		if (student->get_id_number() == id)
			return *student;
	}
	// TODO: handle id not found
}

