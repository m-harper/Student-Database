#include "student.h"

void Student::parse_name(std::string name) {

	first_name = name.substr(0, name.find(" "));
	last_name = name.substr(name.find(" ") + 1);

}
