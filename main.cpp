#include "database.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

enum Command {S, D, F, P, PS, PD, PM, err = -1, QUIT = -2};

Command parse_command(string);

int main() {

	Database db = Database();
	string input;
	
	while (true) {
		getline(cin, input, '\n');
		string parameters = input.substr(input.find(' ') + 1);
		if (parse_command(input) == QUIT)
			break;
		switch (parse_command(input)) {
		case S:
			db.add_student(parameters);
			break;
		case D:
			db.add_department(parameters);
			break;
		case F:
			db.add_fine(parameters);
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
	
	}
	Student stu = db.rand_stu();
	cout << stu.get_summary() << endl;
	Department dept = db.rand_dept();
	cout << dept.get_summary() << endl;
	Fine fine = db.rand_fine();
	cout << fine.get_summary() << endl;
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
