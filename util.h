#ifndef _UTIL_H
#define _UTIL_H

#include <sstream>
#include <ctime>

class Date;

class Util {

public:
	std::string int_to_string(int num) {
		// Return an integer value as a string
		std::stringstream ss;
		ss << num;
		return ss.str();	
	}

	std::string double_to_string(double num) {
		// Return a double value as a string
		std::stringstream ss;
		ss << num;
		return ss.str();
	}

	double string_to_double(std::string dub) {
		// Return a double represented by a string to a double value
		double converted;
		std::istringstream(dub) >> converted;
		return converted;
	}

	int string_to_int(std::string num) {
		// Return an integer represented by a string to an integer value
		int converted;
		std::istringstream(num) >> converted;
		return converted;
	}

	std::string get_token(std::string& full_string) {
		// Return the portion of the string up the the first space
		// Remove that portion from the original string
		std::string token = full_string.substr(0, full_string.find(' '));
		full_string = full_string.substr(full_string.find(' ') + 1);
		return token;
	}

	std::string get_todays_date() {
		std::time_t date = time(NULL);
		struct tm * dateinfo = localtime(&date);
		std::string day = int_to_string(dateinfo->tm_mday);
		std::string month = int_to_string(dateinfo->tm_mon + 1);
		std::string year = int_to_string(dateinfo->tm_year + 1900);

		day = pad_date(day);
		month = pad_date(month);

		std::string sep = "/";

		return month + sep + day + sep + year;
		
	}

	std::string get_header() {
		// Return standard header for database reports
		return "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	}

private:

	std::string pad_date(std::string _num) {
		// Add a 0 to the beginning of the month or day value if the value
		// is only a single digit
		if (_num.length() == 1)
			return "0" + _num;
		else if (_num.length() == 2)
			return _num;
	}

};

class Date {

public:
	Date(std::string _date) {
		std::string date = _date;
		month = get_token(date);
		day = get_token(date);
		year = get_token(date);
	}

	int firsts_before(Date _after) const {
		int firsts = 0;
		
		int _day = day;
		int _month = month;
		int _year = year;

		// Loop while the year value is <= the end date
		while (_year <= _after.get_year()) {
			if (_year == _after.get_year()) {
				// It is the same year, as the end date
				// Increment months until the desired month
				while (_month < _after.get_month()) {
					firsts++;	
					_month++;	
				}
				// The total months have been found
				// Exit the loop
				break;
			}
			else {
				firsts++;
				if (_month < 12) {
					_month++;
				}
				else {
					// Its a new year
					_month = 1;
					_year++;
				}
			}

		}
		return firsts;
	}

	std::string to_string() {
		// Return month/day/year
		std::string sep = "/";
		return util.int_to_string(month) + sep + util.int_to_string(day) + sep + util.int_to_string(year);
	}

	/** * * * * * * * * * * * * 
 		Data Access
	* * * * * * * * * * * * **/

	int get_day() const{
		return day;
	}

	int get_month() const {
		return month;
	}

	int get_year() const {
		return year;
	}

	void set_day(int _day) {
		day = _day;
	}

	void set_month(int _month) {
		month = _month;
	}

	void set_year(int _year) {
		year = _year;
	}

private:
	int day, month, year;
	Util util;

	int get_token(std::string& _date) {
		// Return the portion of a date string up to a '/'
		// Remove that portion from the date string
		int token = util.string_to_int(_date.substr(0, _date.find('/')));
		_date = _date.substr(_date.find('/') + 1);
		return token;
	}

};

#endif
