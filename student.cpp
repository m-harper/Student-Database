#include "student.h"

void Student::parse_name(std::string name) {
	first_name = name.substr(0, name.find(" "));
	last_name = name.substr(name.find(" ") + 1);
}

void Student::add_fine(Fine* _fine) {
	fines->push_back(_fine);
	//unpaid_fines += _fine->get_amount();
}

double Student::get_unpaid_fines() const {

	double fine_amount = 0;

	// Sum the values of all the student's fines + interest
	for (std::list<Fine*>::iterator it = fines->begin(); it != fines->end(); ++it) {
		Fine* fine = *it;
		fine_amount += fine->get_amount();
	}

	return fine_amount - paid_fines;
}

bool Student::has_unpaid_fines() {
	return get_unpaid_fines() > 0;
}

int Student::has_fine_from_dept(int _dept_id) {
	for (std::list<Fine*>::iterator it = fines->begin(); it != fines->end(); ++it) {
		Fine* fine = *it;
		if (fine->get_dept_id() == _dept_id)
			return 1;
	}
	return 0;
}


std::string Student::get_report() {
	std::string report = "";
	report += util.int_to_string(id_number) + "\t" + get_name() + "\n";
	report += "Fines:\n";
	for (std::list<Fine*>::iterator it = fines->begin(); it != fines->end(); ++it) {
		report += (*it)->get_fine_type() + "\t\t" + util.double_to_string((*it)->get_amount()) + "\n";
	}
	report += "\nAmount paid: " + util.double_to_string(paid_fines) + "\n";
	report += "Fines  owed: " + util.double_to_string(get_unpaid_fines()) + "\n";
	return report;
}

void Student::pay_fine(double amount) {
	if (unpaid_fines > 0) {
		if (unpaid_fines >= amount) {
			unpaid_fines -= amount;
			paid_fines += amount;
		}
		else { // Payment amount is more than accrued fines
			paid_fines += unpaid_fines;
			unpaid_fines = 0;
		}
	}
}
