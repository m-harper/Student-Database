#include "database.h"
#include <iostream>
#include <string>

using namespace std;

enum Command {S, D, F, P, PS, PD, PM, err = -1};

Command parse_command(string command);

int main() {

	Database db();
	string input;
	
	cout << "> ";
	getline(cin, input, '\n');

	switch (parse_command(input)) {
	case S:
		cout << "Test" << endl;
		break;

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
	return err;
}

