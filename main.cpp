#include "database.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

enum Command {S, D, F, P, PS, PD, PM, err = -1};

Command parse_command(string);
void add_student(Database&, string);
void add_department(Database&, string);
void add_fine(Database&, string);

int main() {

	Database db = Database();
	string input;
	
	cout << "> ";
	getline(cin, input, '\n');
	string parameters = input.substr(input.find(' ') + 1);

	switch (parse_command(input)) {
	case S:
		add_student(db, parameters);
		break;
	case D:
		add_department(db, parameters);
		break;
	case F:
		add_fine(db, parameters);
		break;
	case P:
		break;
	case PS:
		break;
	case PD:
		break;
	case PM:
		break;
	case err:
		break;

	}
	Student stu = db.rand_stu();
	cout << stu.get_summary() << endl;
	return 0;

}

Command parse_command(string command) {

	string identifier = command.substr(0, command.find(' '));
	if (identifier == "S")
		return S;
	if (identifier == "D")
		return D;
	if (identifier == "F")
		return F;
	if (identifier == "P")
		return P;
	if (identifier == "PS")
		return PS;
	if (identifier == "PD")
		return PD;
	if (identifier == "PM")
		return PM;
	return err;
}

int string_to_int(string id) {

	int num;
	istringstream(id) >> num;
	return num;

}

// Returns the portion of a string up to a space character.
// That portion is dropped off of the original string.
string get_token(string& full_string) {
	string token = full_string.substr(0, full_string.find(' '));
	full_string = full_string.substr(full_string.find(' ') + 1);
	return token;
}

void add_student(Database& db, string _student) {
	
	string student = _student;

	int student_id = string_to_int(get_token(student));
	
	string first_name = get_token(student);
	string last_name = get_token(student);
	string name = first_name + " " + last_name;
	
	string major = student;
	
	db.add_student(Student(student_id, name, major));

}

void add_department(Database& db, string _department) {

	string department = _department;
	int dept_id = string_to_int(get_token(department));
	string dept_name = get_token(department);	

	db.add_department(Department(dept_id, dept_name));
}

void add_fine(Database& db, string _fine) {

}
