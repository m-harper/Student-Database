#ifndef _STUDENT_H
#define _STUDENT_H

#include <string>
#include <sstream>
#include <list>
#include "fine.h"
#include <iostream>

class Student {

public:
	Student(int _id, std::string _name, std::string _major) :
		id_number(_id), major(_major) {
		
		parse_name(_name);
		init_balance();
		fines = new std::list<Fine*>;
	 }

	Student(const Student& _student) {
		id_number = _student.get_id_number();
		major = _student.get_major();
		parse_name(_student.get_name());
		init_balance();
		fines = new std::list<Fine*>;
	}

	~Student() {
		delete fines;
	}
	
	void add_fine(Fine*);
	void pay_fine(double);
	std::string get_report();
	void parse_name(std::string);
	int has_fine_from_dept(int);
	
	std::string get_summary() {
		return int_to_string(id_number) + "\t" + first_name + " " + last_name + "\t" + major + "\t" + double_to_string(unpaid_fines);
	}
	
	/** * * * * * * * * * * * *
	  Data access
	* * * * * * * * * * * * **/
	
	int get_id_number() const {
		return id_number;
	}
	
	std::string get_first_name() const {
		return first_name;
	}

	std::string get_last_name() const {
		return last_name;
	}

	// Returns "firstname lastname"
	std::string get_name() const {
		return first_name + " " + last_name;
	}

	std::string get_major() const {
		return major;
	}

	double get_unpaid_fines() const {
		return unpaid_fines;
	}

	double get_paid_fines() const {
		return paid_fines;
	}

	int get_num_fines() const {
		return fines->size();
	}

private:
	int id_number; // 9 digits
	std::string first_name, last_name;
	std::string major;
	double unpaid_fines;
	double paid_fines;
	std::list<Fine*>* fines;

	std::string int_to_string(int num) {
		std::ostringstream stringstream;
		stringstream << num;
		return stringstream.str();
	}

	std::string double_to_string(double num) {
		std::ostringstream stringstream;
		stringstream << num;
		return stringstream.str();
	}	

	void init_balance() {
		unpaid_fines = 0;
		paid_fines = 0;
	}

};

#endif
