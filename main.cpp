#include <iostream>
#include <stdexcept>
#include <regex>
using namespace std;
#include "utils.hpp"

int main() {
	cout << "Please Enter your email address: " << endl;
	string email;
	cin >> email;
	try{
		check_email(email);
	} catch (invalid_argument) {
		regex pattern(R"([a-zA-Z0-9_-]+@(gmail|email|yahoo)\.com)");

		while(!regex_match(email, pattern)){
			if(regex_match(email, pattern))
				break;
			else{
				cout << "Please enter you email again: ";
				cin >> email;
			}
		}
	}
	return 0;
}

