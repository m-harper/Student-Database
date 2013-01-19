#include "database.h"
#include <iostream>

using namespace std;

int main() {

	Database db = Database();
	db.add_student(Student(123456789, "Bob Harris", "CPSC"));

	return 0;

}
