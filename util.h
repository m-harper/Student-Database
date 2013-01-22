#ifndef _UTIL_H
#define _UTIL_H

#include <sstream>

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

	int int_to_string(std::string num) {
		int converted;
		std::istringstream(num) >> converted;
		return converted;
	}

	std::string get_token(std::string& full_string) {
		std::string token = full_string.substr(0, full_string.find(' '));
		full_string = full_string.substr(full_string.find(' ') + 1);
		return token;
	}
};

#endif
