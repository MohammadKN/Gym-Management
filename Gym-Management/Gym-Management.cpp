#include <iostream>
#include <fstream>
#include <map>
#include "classes/client.h"
#include "classes/trainer.h"
#include "classes/nutritionSpecialist.h"
#include "Schedule.h"

using namespace std;

void showClientMenu(string username) {
	cout << "Gym Management System\n";
	cout << "Hello "<< username << "How Was Your Day" << endl;
    cout << "1. Access Schedule\n";
    cout << "2. Communicate with Trainer\n";
    cout << "3. Communicate with Nutrition Specialist\n";
	cout << "4. Logout\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}
void showTrainerMenu(string username) {
	cout << "Gym Management System\n";
	cout << "Hello "<< username << "How Was Your Day" << endl;
    cout << "1. Manage Schedules\n";
    cout << "2. Communicate with a Client\n";
	cout << "3. Logout\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

void showNutritionSpecialistMenu(string username) {
	cout << "Gym Management System\n";
	cout << "Hello "<< username << "How Was Your Day" << endl;
	cout << "1. Create a Diet Plan\n";
    cout << "1. Manage Clients' Diet Plans\n";
    cout << "2. Communicate with a Client\n";
	cout << "3. Logout\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

void showAuth() {
	cout << "Gym Management System\n";
    cout << "1. Login\n";
    cout << "2. Register\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

map<string, string> clients;
map<string, string> trainers;
map<string, string> nutritionSpecialists;

void loadUsers() {
	ifstream infile("clients.txt");
	string username, password;
	while (infile >> username >> password) {
		clients[username] = password;
	}
	infile.close();

	infile.open("trainers.txt");
	while (infile >> username >> password) {
		trainers[username] = password;
	}
	infile.close();

	infile.open("nutritionSpecialists.txt");
	while (infile >> username >> password) {
		nutritionSpecialists[username] = password;
	}
	infile.close();
}

void saveUsers() {
	ofstream outfile("clients.txt");
	for (const auto& user : clients) {
		outfile << user.first << " " << user.second << endl;
	}
	outfile.close();

	outfile.open("trainers.txt");
	for (const auto& user : trainers) {
		outfile << user.first << " " << user.second << endl;
	}
	outfile.close();

	outfile.open("nutritionSpecialists.txt");
	for (const auto& user : nutritionSpecialists) {
		outfile << user.first << " " << user.second << endl;
	}
	outfile.close();
}


bool loginMenu() {
	string username, password;
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;
	cout << "1. Client\n";
	cout << "2. Trainer\n";
	cout << "3. Nutrition Specialist\n";
	cout << "Enter your choice: ";
	int accountType;
	cin >> accountType;
	loadUsers();
	if (clients.find(username) != clients.end() && clients[username] == password) {
		cout << "Login successful!\n";
		if (username == "Client") {
			showClientMenu(username);
		} else if (username == "Trainer") {
			showTrainerMenu(username);
		} else if (username == "Nutrition") {
			showNutritionSpecialistMenu(username);
		}
		return true;
	} else {
		cout << "Invalid username or password. Try again.\n";
		return false;
	}
}


bool registerMenu() {
	string username, password;
	cout << "Enter a new username: ";
	cin >> username;
	cout << "Enter a new password: ";
	cin >> password;
	cout << "Which Type of Account You Want To Create\n";
	cout << "1. Client\n";
	cout << "2. Trainer\n";
	cout << "3. Nutrition Specialist\n";
	cout << "Enter your choice: ";
	int accountType;
	cin >> accountType;
	switch (accountType) {
		case 1:
			cout << "Client account created.\n";
			showClientMenu(username);
			break;
			clients[username] = password;
			saveUsers();
		case 2:
			cout << "Trainer account created.\n";
			showTrainerMenu(username);
			break;
		case 3:
			cout << "Nutrition Specialist account created.\n";
			showNutritionSpecialistMenu(username);
			break;
		default:
			cout << "Invalid choice. Account not created.\n";
			return false;
	}

	
	cout << "Registration successful!.\n";
	return true;
}


int main() {
    int choice;
    do {
        showAuth();
        cin >> choice;
        switch (choice) {
            case 1: if (!loginMenu()) showAuth(); break;
            case 2: registerMenu(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
