#ifndef _FINE_H
#define _FINE_H

#include "util.h"
#include <iostream>

class Fine {

public:
	Fine(int _student_id, int _dept_id, double _amount, 
		std::string _date, std::string _fine_type) :
		student_id(_student_id), dept_id(_dept_id),
		amount(_amount), date(_date), fine_type(_fine_type) {
		paid = false;
	}

	/** * * * * * * * * * * * * *
 		Data access
	* * * * * * * * * * * * * **/

	int get_student_id() const {
		return student_id;
	}
	
	int get_dept_id() const {
		return dept_id;
	}

	double get_amount_before_interest() const {
		return amount;
	}
	
	double get_amount(Date _date) const {
		return get_interest(_date);
	}
	
	std::string get_date() const {
		return date;
	}

	std::string get_fine_type() const {
		return fine_type;
	}
	
	void mark_paid() {
		paid = true;
	}
	
	bool is_paid() const {
		return paid;
	}

private:
	int student_id;
	int dept_id;
	double amount;
	std::string date;
	std::string fine_type;
	bool paid;
	
	double get_interest(Date _today) const {
		Util util;
		Date today(_today);
		Date fine_issued(date);
		double fine_amt = amount;
		
		int months_of_interest = fine_issued.firsts_before(today);
		for ( ; months_of_interest > 0; months_of_interest--) {
			fine_amt = fine_amt * 1.01;
		}
		return fine_amt;
	}
};

#endif
