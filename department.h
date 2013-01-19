#ifndef _DEPT_H
#define _DEPT_H

class Department {

public:
	Department(int _dept_id, std::string _dept_name) :
		dept_id(_dept_id), dept_name(_dept_name) {
	
	}


	/** * * * * * * * * * * * *
 		Data access
	* * * * * * * * * * * * **/

	std::string get_dept_name() {
		return dept_name;
	}

	int get_dept_id() {
		return dept_id;
	}

private:
	std::string dept_name;
	int dept_id;

};

#endif
