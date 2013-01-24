#include "student.h"

void Student::parse_name(std::string name) {
	first_name = name.substr(0, name.find(" "));
	last_name = name.substr(name.find(" ") + 1);
}

void Student::add_fine(Fine* _fine) {
	fines->push_back(_fine);
}

double Student::get_unpaid_fines() const {

	double fine_amount = 0;

	// Sum the values of all the student's fines + interest
	for (std::list<Fine*>::iterator it = fines->begin(); it != fines->end(); ++it) {
		Fine* fine = *it;
		if ( ! fine->is_paid())
			fine_amount += fine->get_amount();
	}

	// Return the total amount of the students unpaid fines less the students current balance
	return fine_amount - balance;
}

bool Student::has_unpaid_fines() {
	return get_unpaid_fines() > 0;
}

bool Student::has_fine_from_dept(int _dept_id) {
	// Return true if the student has a fine from dept_id that is unpaid
	for (std::list<Fine*>::iterator it = fines->begin(); it != fines->end(); ++it) {
		Fine* fine = *it;
		if (fine->get_dept_id() == _dept_id && ! fine->is_paid())
			return true;
	}
	return false;
}


std::string Student::get_report() {
	// Return the students ID and name, along with any fines or fees the student has incurred
	
	std::string report = "";
	report += util.int_to_string(id_number) + "\t" + get_name() + "\n";

	// Append any fines the student has received
	report += "Fines:\n";
	for (std::list<Fine*>::iterator it = fines->begin(); it != fines->end(); ++it) {
		Fine* fine = *it;
		report += fine->get_fine_type() + "\t\t" + util.double_to_string(fine->get_amount_before_interest()) + "\n";
	}
	// Append account totals
	report += "\nAmount paid: " + util.double_to_string(paid_fines) + "\n";
	report += "Fines  owed: " + util.double_to_string(get_unpaid_fines());
	return report;
}

void Student::pay_fine(double _amount) {
	// Increase the balance and total paid fines
	balance += _amount;
	paid_fines += _amount;

	// Iterate through fines, paying off the first encountered fine that can be afforded
	for (std::list<Fine*>::iterator it = fines->begin(); it != fines->end(); ++it) {
		Fine* fine =  *it;
		if ( ! fine->is_paid()) {
			if (balance >= fine->get_amount()) {
				balance -= fine->get_amount();	
				fine->mark_paid();
			}	
		}
	}
}

void Student::update_fine_dates(std::string _date) {
	for (std::list<Fine*>::iterator it = fines->begin(); it != fines->end(); ++it) {
		Fine* fine = *it;
		fine->update_interest_date(_date);
	}
}
