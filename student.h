#ifndef _STUDENT_H
#define _STUDENT_H

#include <string>

class Student {

public:
	Student(int _id, std::string _name, std::string _major) :
		id_number(_id), major(_major) {
		
		parse_name(_name);

	 }
	
	void pay_fine(int payment_amount);
	void parse_name(std::string);
	



	/** * * * * * * * * * * * *
	  Data access
	* * * * * * * * * * * * **/
	
	int get_id_number() {
		return id_number;
	}
	
	std::string get_first_name() {
		return first_name;
	}

	std::string get_last_name() {
		return last_name;
	}

	// Returns "firstname lastname"
	std::string get_name() {
		return first_name + " " + last_name;
	}

	std::string get_major() {
		return major;
	}

	double get_balance() {
		return balance;
	}

	double get_unpaid_fines() {
		return unpaid_fines;
	}

	double get_paid_fines() {
		return paid_fines;
	}

private:
	int id_number; // 9 digits
	std::string first_name, last_name;
	std::string major;
	double balance;
	double unpaid_fines;
	double paid_fines;

};

#endif
