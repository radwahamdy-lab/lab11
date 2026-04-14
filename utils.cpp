#include <regex>
#include <string>
#include <stdexcept>
using namespace std;

void check_email(string email){
	regex pattern(R"([a-zA-Z0-9_-]+@(gmail|email|yahoo)\.com)");
	if(!regex_match(email, pattern)) throw invalid_argument("email is not valid");
}
