#ifndef _DEPT_H
#define _DEPT_H

#include "util.h"

class Department {

public:
	Department(int _dept_id, std::string _dept_name) :
		dept_id(_dept_id), dept_name(_dept_name) {
	
	}

	Department(const Department& _dept) {
		dept_id = _dept.get_dept_id();
		dept_name = _dept.get_dept_name();
	}

	std::strng get_report() {
		// Return the departments ID and name
		return util.int_to_string(dept_id) + "\t" + dept_name;
	}

	/** * * * * * * * * * * * *
 		Data access
	* * * * * * * * * * * * **/

	std::string get_dept_name() const {
		return dept_name;
	}

	int get_dept_id() const {
		return dept_id;
	}

private:
	Util util;
	std::string dept_name;
	int dept_id;
};

#endif
