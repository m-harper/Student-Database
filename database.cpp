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

	// Apply fine to student
	Student* student = find_student(_fine.get_student_id());
	student->add_fine(fine);
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

	Student* student = find_student(student_id);
	student->pay_fine(amount);
}

void Database::print_student_report(std::string _id) {
	int id = string_to_int(get_token(_id));
	Student* student = find_student(id);
	std::string report = student->get_report();
	std::cout << report << std::endl;
}

void Database::print_department_report(std::string _dept_id) {
	int dept_id = string_to_int(get_token(_dept_id));
	Department* dept = find_department(dept_id);
	std::string report = dept->get_report() + "\n";
	report += "Students who have fines: \n";

	// Loop through students searching for ones with dept fines
	for (std::list<Student*>::iterator it = student_list.begin(); it != student_list.end(); ++it) {
		Student* student = *it;
		if (student->has_fine_from_dept(dept_id))
			report += dept->int_to_string((student->get_id_number())) + "\t" + student->get_name()+ "\n";
	}
	std::cout << std::endl << report << std::endl;
}

Department* Database::find_department(int _id) {
	Department* dept;
	for (std::list<Department*>::iterator it = dept_list.begin(); it != dept_list.end(); ++it) {
		dept = *it;
		if (dept->get_dept_id() == _id) {
			return dept;
		}
	}

}

void Database::print_major_report(std::string _major) {
	std::string major = get_token(_major);
	std::string report = major + "\n";

	Student* student;
	// Find students with a matching major and have unpaid fines
	for (std::list<Student*>::iterator it = student_list.begin(); it != student_list.end(); ++it) {
		student = *it;
		if (student->has_unpaid_fines() && student->get_major() == major)
			report += util.int_to_string(student->get_id_number()) + '\t' + student->get_name() + '\t' + util.double_to_string(student->get_unpaid_fines()) + '\n';
	}
	std::cout << report << std::endl;

}

Student* Database::find_student(int id) {
	
	Student* student;
	for (std::list<Student*>::iterator it = student_list.begin(); it != student_list.end(); ++it) {
		student = *it;	
		if (student->get_id_number() == id)
			return student;
	}
	// TODO: handle id not found
}

