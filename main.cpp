#include "database.h"
#include <iostream>
//#include <string>
//#include <sstream>

using namespace std;

enum Command {S, D, F, P, PS, PD, PM, err = -1, QUIT = -2};

Command parse_command(string);

int main() {

	Database db = Database();
	string input;
	string _date;
	
	while (true) {
		getline(cin, input, '\n');
		string parameters = input.substr(input.find(' ') + 1);
		if (parse_command(input) == QUIT || input == "")
			break;
		switch (parse_command(input)) {
		case S:
			db.add_student(parameters);
			break;
		case D:
			db.add_department(parameters);
			break;
		case F:
			_date = db.add_fine(parameters);
			db.set_date(Date(_date));
			break;
		case P:
			_date = db.process_payment(parameters);
			db.set_date(Date(_date));
			break;
		case PS:
			db.print_student_report(parameters);
			break;
		case PD:
			db.print_department_report(parameters);
			break;
		case PM:
			db.print_major_report(parameters);
			break;
		case err:
			break;

		}
	
	}
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
	if (identifier == "Q")
		return QUIT;
	return err;
}
