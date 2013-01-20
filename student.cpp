#include "student.h"

void Student::parse_name(std::string name) {

	first_name = name.substr(0, name.find(" "));
	last_name = name.substr(name.find(" ") + 1);

}

void Student::pay_fine(double amount) {
	if (unpaid_fines > 0) {
		if (unpaid_fines >= amount) {
			unpaid_fines -= amount;
			paid_fines += amount;
		}
		else {
			
		}
	}

}
