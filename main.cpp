#include <iostream>
#include <stdexcept>
#include <regex>
#include <map>
#include <string>
using namespace std;
#include "utils.hpp"

int main() {
	bool loggedin=false;
	string option;
	map<string, string> users;
	while(true){
	if(loggedin) cout << "Choose: Login / Logout: ";
	else cout << "Choose: Sign Up / Login: ";
	cin >> option;
	if(option == "signup" || option=="login"){
		string password;
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
		cout << "Please Enter your password: ";
		cin >> password;
		if(option=="signup") users[email] = password;
		else{
			for(pair p:users){
				if(p.first == email && p.second == password) loggedin=true;
			}
		}
	} else if(option == "logout"){
		loggedin=false;
	}
	}
	return 0;
}

