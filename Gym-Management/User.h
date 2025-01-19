#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

enum UserType { CLIENT, TRAINER, NUTRITION_SPECIALIST, ADMIN };
class User {
public:
    string username;
    string password;
    int id;
    UserType accountType = CLIENT;
	User() {
		username = "";
		password = "";
		id = 0;
		accountType = CLIENT;
	}
	User(string username, string password, int id, UserType accountType) {
		this->username = username;
		this->password = password;
		this->id = id;
		this->accountType = accountType;
	}
};

#endif