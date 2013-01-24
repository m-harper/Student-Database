#ifndef _UTIL_H
#define _UTIL_H

#include <sstream>
#include <ctime>

class Date;

class Util {

public:
	std::string int_to_string(int num) {
		std::stringstream ss;
		ss << num;
		return ss.str();	
	}

	std::string double_to_string(double num) {
		std::stringstream ss;
		ss << num;
		return ss.str();
	}

	double string_to_double(std::string dub) {
		double converted;
		std::istringstream(dub) >> converted;
		return converted;
	}

	int string_to_int(std::string num) {
		int converted;
		std::istringstream(num) >> converted;
		return converted;
	}

	std::string get_token(std::string& full_string) {
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

private:

	std::string pad_date(std::string _num) {
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

	int firsts_before(Date _after) {
		int firsts = 0;
		
		while ( month <= _after.get_month() && year <= _after.get_year()) {
			day = 1;
			if (month < 12)
				month++;
			else {
				month = 1;
				year++;
			}
			firsts++;
		}

		return firsts;
	}

	std::string to_string() {
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
		int token = util.string_to_int(_date.substr(0, _date.find('/')));
		_date = _date.substr(_date.find('/') + 1);
		return token;
	}

};

#endif
