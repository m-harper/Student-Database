#ifndef _FINE_H
#define _FINE_H

#include "util.h"
#include <math.h>

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
	
	double get_amount() const {
		return get_interest();
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
	
	double get_interest() const {
		Util util;
		Date today(util.get_todays_date());
		Date fine_issued(date);
		double fine_amt = get_amount_before_interest();
		
		int months_of_interest = fine_issued.firsts_before(today);
		for ( ; months_of_interest > 0; months_of_interest--) {
			double interest = fine_amt * .01;
			interest = round_down(interest);
			fine_amt += interest;
		}
		return fine_amt;
	}

	double round_down(double _unrounded) const {
		double rounded = floor(_unrounded * 100) / 100;
		return rounded;
	}
};

#endif
