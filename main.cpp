#include "database.h"
#include <iostream>
#include <fstream>

using namespace std;

enum Command {S, D, F, P, PS, PD, PM, err = -1, QUIT = -2};

Command parse_command(string);
void read_from_stdin();
void read_from_file();
void parse_input(string, Database*);

int main() {
	// Try to access "input.txt" for reading in
	ifstream file_stream;
	file_stream.open("input.txt", fstream::in);
	if ( ! file_stream.is_open()) {
		// No file found
		// Close file stream and read in from stdin instead
		file_stream.close();

		cout << "File input.txt not found, reading in from stdin" << endl;

		read_from_stdin();
	}
	else {
		// Close the file stream
		file_stream.close();
		
		cout << "File input.txt found, using input.txt for input data" << endl;
		// Read in from file
		read_from_file();
	}
	
	return 0;
}

void read_from_file() {
	Database* db = new Database();

	// Open file "input.txt"
	ifstream file_stream;
	file_stream.open("input.txt", fstream::in);
	if ( ! file_stream.is_open()) {
		cout << "Error reading input.txt" << endl;
		return;
	}

	// File is open and ready to ready
	char file_line[256];
	string line;
	file_stream.getline(file_line, 256);
	line = file_line;

	while (line != "" && line != "Q") {
		// Parse the input line and perform action
		parse_input(line, db);

		// Read the next line
		file_stream.getline(file_line, 256);
		line = file_line;
	}	
}

void read_from_stdin() {
	Database* db = new Database();

	string line;
	getline(cin, line, '\n');
	
	while (line != "" && line != "Q") {
		parse_input(line, db);
		getline(cin, line, '\n');
	}
}

void parse_input(string _line, Database* db) {
	string line = _line;
	Util util;
	string command = util.get_token(line);
	string date;

	switch(parse_command(command)) {
	case S:
		db->add_student(line);
		break;
	case D:
		db->add_department(line);
		break;
	case F:
		date = db->add_fine(line);
		db->update_date(date);
		break;
	case P:
		date = db->process_payment(line);
		db->update_date(date);
		break;
	case PS:
		db->print_student_report(line);
		break;
	case PD:
		db->print_department_report(line);
		break;
	case PM:
		db->print_major_report(line);
		break;	
	case err:
		cout << "Unrecognized command " << command << endl;
		break;
	}
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
