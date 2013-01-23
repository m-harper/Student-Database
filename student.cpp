#include "student.h"

void Student::parse_name(std::string name) {
	first_name = name.substr(0, name.find(" "));
	last_name = name.substr(name.find(" ") + 1);
}

void Student::add_fine(Fine* _fine) {
	fines->push_back(_fine);
	//unpaid_fines += _fine->get_amount();
}

double Student::get_unpaid_fines(Date _date) const {

	double fine_amount = 0;

	// Sum the values of all the student's fines + interest
	for (std::list<Fine*>::iterator it = fines->begin(); it != fines->end(); ++it) {
		Fine* fine = *it;
		fine_amount += fine->get_amount(_date);
	}

	return fine_amount - balance;
}

bool Student::has_unpaid_fines() {
	for (std::list<Fine*>::iterator it = fines->begin(); it != fines->end(); ++it) {
		Fine* fine = *it;
		if (! fine->is_paid())
			return true;
	}
	return false;
}

int Student::has_fine_from_dept(int _dept_id) {
	for (std::list<Fine*>::iterator it = fines->begin(); it != fines->end(); ++it) {
		Fine* fine = *it;
		if (fine->get_dept_id() == _dept_id)
			return 1;
	}
	return 0;
}


std::string Student::get_report(Date _today) {
	std::string report = "";
	report += util.int_to_string(id_number) + "\t" + get_name() + "\n";
	report += "Fines:\n";
	for (std::list<Fine*>::iterator it = fines->begin(); it != fines->end(); ++it) {
		Fine* fine = *it;
		report += fine->get_fine_type() + "\t\t" + util.double_to_string(fine->get_amount_before_interest()) + "\n";
	}
	report += "\nAmount paid: " + util.double_to_string(paid_fines) + "\n";
	report += "Fines  owed: " + util.double_to_string(get_unpaid_fines(_today)) + "\n";
	return report;
}

void Student::pay_fine(double _amount, Date _day) {
	balance += _amount;
	paid_fines += _amount;
	
	for (std::list<Fine*>::iterator it = fines->begin(); it != fines->end(); ++it) {
		Fine* fine = *it;
		if ((! fine->is_paid()) && balance >= fine->get_amount(_day)) {
			balance -= fine->get_amount(_day);
			fine->mark_paid();
		}
	}	
}

double Student::sum_fines(Date _day) {
	double total = 0;
	for (std::list<Fine*>::iterator it = fines->begin(); it != fines->end(); ++it) {
		Fine* fine = *it;
		if (! fine->is_paid())
			total += fine->get_amount(_day);
	}

	return total;
}
