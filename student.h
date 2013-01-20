#ifndef _STUDENT_H
#define _STUDENT_H

#include <string>
#include <sstream>

class Student {

public:
	Student(int _id, std::string _name, std::string _major) :
		id_number(_id), major(_major) {
		
		parse_name(_name);
		init_balance();
	 }

	Student(const Student& _student) {
		id_number = _student.get_id_number();
		major = _student.get_major();
		parse_name(_student.get_name());
		init_balance();
	}
	
	void pay_fine(double);
	void parse_name(std::string);
	
	std::string get_summary() {
		
		return int_to_string(id_number) + "\t" + first_name + " " + last_name + "\t" + major;
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

	double get_balance() const {
		return balance;
	}

	double get_unpaid_fines() const {
		return unpaid_fines;
	}

	double get_paid_fines() const {
		return paid_fines;
	}

private:
	int id_number; // 9 digits
	std::string first_name, last_name;
	std::string major;
	double unpaid_fines;
	double paid_fines;

	std::string int_to_string(int num) {
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
