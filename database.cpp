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

	// Apply fine to student
	Student* student = find_student(_fine.get_student_id());
	student->add_fine(fine);
}

void Database::add_student(std::string _student) {
	std::string student = _student;
	
	// Parse input in the form "id first_name last_name major"
	int id = util.string_to_int(util.get_token(student));
	
	std::string first_name = util.get_token(student);
	std::string last_name = util.get_token(student);
	std::string name = first_name + " " + last_name;
	std::string major = student;

	// Add a student object to the database
	add_student(Student(id, name, major));	
}

void Database::add_department(std::string _dept) {
	std::string dept = _dept;

	// Parse input in the form "department_id department_name
	int id = util.string_to_int(util.get_token(dept));
	std::string dept_name = dept;

	// Add a department object to the database
	add_department(Department(id, dept_name));

}

void Database::add_fine(std::string _fine) {
	std::string fine = _fine;

	// Parse input in the form "student_id department_id fine_amount date fine_type"
	int student_id = util.string_to_int(util.get_token(fine));
	int dept_id = util.string_to_int(util.get_token(fine));
	double amount = util.string_to_double(util.get_token(fine));
	std::string date = util.get_token(fine);
	std::string fine_type = fine;

	// Add a fine object to the database
	add_fine(Fine(student_id, dept_id, amount, date, fine_type));

	update_date(date);
}

void Database::process_payment(std::string _payment) {
	std::string payment = _payment;

	// Parse input in the form "student_id payment_amount date"
	int student_id = util.string_to_int(util.get_token(payment));
	double amount = util.string_to_double(util.get_token(payment));
	std::string date = payment;

	// Apply the payment to the stored student object
	Student* student = find_student(student_id);
	student->pay_fine(amount);

	update_date(date);
}

void Database::print_student_report(std::string _id) {
	// Find the student object to generate the report
	int id = util.string_to_int(util.get_token(_id));
	Student* student = find_student(id);
	std::string report = student->get_report();

	// Print the student generated report with a standard header and footer
	std::cout << util.get_header() << report << std::endl << util.get_header() << std::endl;
}

void Database::print_department_report(std::string _dept_id) {
	// Find the department object to generate the report
	int dept_id = util.string_to_int(util.get_token(_dept_id));
	Department* dept = find_department(dept_id);

	// Apply header to department generated report
	std::string report = dept->get_report() + "\n";
	report = util.get_header() + report;

	// Append a section containing students who have fines with the department
	report += "Students who have fines: \n";

	// Loop through students searching for ones with dept fines
	for (std::list<Student*>::iterator it = student_list.begin(); it != student_list.end(); ++it) {
		Student* student = *it;
		if (student->has_fine_from_dept(dept_id))
			report += util.int_to_string((student->get_id_number())) + "\t" + student->get_name()+ "\n";
	}

	// Print the report with its additions, with a standard footer
	std::cout << std::endl << report << util.get_header() << std::endl;
}

Department* Database::find_department(int _id) {
	Department* dept;
	for (std::list<Department*>::iterator it = dept_list.begin(); it != dept_list.end(); ++it) {
		dept = *it;
		if (dept->get_dept_id() == _id) {
			return dept;
		}
	}
	
	// Return null if the department id was not found
	return NULL;
}

void Database::print_major_report(std::string _major) {
	// Begin a report string with a standard header and the major name
	std::string major = util.get_token(_major);
	std::string report = util.get_header() + major + "\n";

	Student* student;
	// Append students with a matching major and have unpaid fines
	for (std::list<Student*>::iterator it = student_list.begin(); it != student_list.end(); ++it) {
		student = *it;
		if (student->has_unpaid_fines() && student->get_major() == major)
			report += util.int_to_string(student->get_id_number()) + '\t' + student->get_name() + '\t' + util.double_to_string(student->get_unpaid_fines()) + '\n';
	}

	// Print the major report with a standard footer
	std::cout << report << util.get_header() << std::endl;
}

Student* Database::find_student(int id) {
	Student* student;
	for (std::list<Student*>::iterator it = student_list.begin(); it != student_list.end(); ++it) {
		student = *it;	
		if (student->get_id_number() == id)
			return student;
	}
	
	// Return null if student id not found
	return NULL;
}

void Database::update_date(std::string _date) {
	// Update each students fines with current date
	for (std::list<Student*>::iterator stu_it = student_list.begin(); stu_it != student_list.end(); ++stu_it) {
		Student* student = *stu_it;
		student->update_fine_dates(_date);
	}
}
