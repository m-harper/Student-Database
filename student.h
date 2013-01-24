#ifndef _STUDENT_H
#define _STUDENT_H

#include <list>
#include "fine.h"
#include "util.h"

class Student {

public:
	Student(int _id, std::string _name, std::string _major) :
		id_number(_id), major(_major) {
	
		// Parse and set the student name	
		parse_name(_name);
		// Initialze the student balance and paid fine amounts
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
		// Iterate through the students list of fines and delete each object
		for(std::list<Fine*>::iterator it = fines->begin(); it != fines->end(); ++it) {
			Fine* fine = *it;
			delete fine;
		}
		delete fines;
	}
	
	void add_fine(Fine*);
	void pay_fine(double);
	bool has_unpaid_fines();
	int has_fine_from_dept(int);

	std::string get_report();
	
	void parse_name(std::string);
	void update_fine_dates(std::string);
	
	/** * * * * * * * * * * * *
		Data access
	* * * * * * * * * * * * **/
	double get_unpaid_fines() const;

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

	double get_paid_fines() const {
		return paid_fines;
	}

	int get_num_fines() const {
		return fines->size();
	}

private:
	Util util;
	int id_number;
	std::string first_name, last_name;
	std::string major;
	double paid_fines;
	double balance;
	std::list<Fine*>* fines;

	void init_balance() {
		paid_fines = 0;
		balance = 0;
	}

};

#endif
