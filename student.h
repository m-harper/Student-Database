#ifndef _STUDENT_H
#define _STUDENT_H

#include <list>
#include "fine.h"
#include "util.h"

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
		for(std::list<Fine*>::iterator it = fines->begin(); it != fines->end(); ++it) {
			Fine* fine = *it;
			delete fine;
		}
		delete fines;
	}
	
	void add_fine(Fine*);
	void pay_fine(double);
	bool has_unpaid_fines();
	std::string get_report();
	void parse_name(std::string);
	int has_fine_from_dept(int);
	
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

	/*double get_unpaid_fines() const {
		return unpaid_fines;
	}*/

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
	//double unpaid_fines;
	double paid_fines;
	std::list<Fine*>* fines;

	void init_balance() {
		//unpaid_fines = 0;
		paid_fines = 0;
	}

};

#endif
