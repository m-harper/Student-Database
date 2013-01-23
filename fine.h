#ifndef _FINE_H
#define _FINE_H

#include "util.h"

class Fine {

public:
	Fine(int _student_id, int _dept_id, double _amount, 
		std::string _date, std::string _fine_type) :
		student_id(_student_id), dept_id(_dept_id),
		amount(_amount), date(_date), fine_type(_fine_type) {

	}

	double calculate_interest() {
		Util util;
		Date today(util.get_todays_date());
		Date fine_issued(date);
		
		int months_of_interest = fine_issued.firsts_before(today);
		return (double) months_of_interest;
	}

	/** * * * * * * * * * * * * *
 		Data access
	* * * * * * * * * * * * * **/

	int get_student_id() {
		return student_id;
	}
	
	int get_dept_id() {
		return dept_id;
	}

	double get_amount() {
		return amount;
	}
	
	std::string get_date() {
		return date;
	}

	std::string get_fine_type() {
		return fine_type;
	}

private:
	int student_id;
	int dept_id;
	double amount;
	std::string date;
	std::string fine_type;
};

#endif
