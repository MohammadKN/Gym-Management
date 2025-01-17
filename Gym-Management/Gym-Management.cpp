#include <iostream>
#include <fstream>
#include <map>
#include "trainer.h"
#include "nutritionSpecialist.h"
#include "Schedule.h"
#include "hashr.h"
#include "Trainer.h"
#include "client.h"
#include "linkedlist.cpp"

using namespace std;

LinkedList clients;

bool loggedIn = false;
string username;
enum UserType { CLIENT, TRAINER, NUTRITION_SPECIALIST, ADMIN };


Client client;
Trainer trainer;


void displayUsers() {
	cout << "Clients:\n";
	cout << "Trainers:\n";
	cout << "Nutrition Specialists:\n";
}
void showUserMenu(string username,UserType userType) {
	int choice;

	Day workingDays[] = { Monday, Wednesday, Friday };
	Day restDays[] = { Sunday, Tuesday };
	

	string message;

	string table[MAX];
	string exercises[5] = { "Push-ups", "Squats", "Plank", "Lunges", "Pull-ups" };
	Schedule schedule(101, 202, workingDays, 3, exercises, 5, 60, restDays, 2);
	NutritionSpecialist specialist("2114", "Faris hijazi", 35, 5, "best nuitrtion specialist award 2024", "07720582027");
	int numExercises;

	switch (userType) {
	case CLIENT:
		do {
			cout << "Gym Management System\n";
			cout << "Hello " << username << " How Was Your Day" << endl;
			cout << "1. Access Schedule\n";
			cout << "2. Access Diet Plan\n";
			cout << "3. Go To Marketplace\n";
			cout << "4. access Schedule \n";
			cout << "5. Update Information\n";
			cout<<  "5. logout\n"; 
			cout << "6. exit\n";
			cout << "Enter your choice: ";
			cin >> choice;
			switch (choice) {
			case 1:
				system("cls");
				schedule.displaySchedule();
				system("cls");
				break;
			case 2:
				loggedIn = false;
				system("cls");
				client.accessDiet(); 
				break;
			case 3 :
				system("cls");
				client.marketplace(); 
				client.buy();
				client.printBill();
			case 4 :
				system("cls");
				client.accessSchedule(schedule);
			case 5 : 
				cout<<"Enter Your ID: ";
				cin>>client.id;
				cout<<"Enter Your Name: ";
				cin>>client.username;
				cout<<"Enter your  Age" ; 
				cin>>client.age; 
				cout << "Enter your  Phone Number";
				cin>> client.phoneNumber ; 
				cout<<"Enter your Trainer Id";
				cin >> client.TrainerId;
			
			default:
				cout << "Invalid choice. Try again.\n";
			}
		} while (choice != 6 && loggedIn);
		break;
	case TRAINER:

		do {
			cout << "Gym Management System\n";
			cout << "Hello " << username << " How Was Your Day" << endl;
			cout << "1. Create a Schedule" << endl;
			cout << "2. Logout\n";
			cout << "Enter your choice: ";

			cin >> choice;

			switch (choice) {
			case 1:
				system("cls");

				int trainerID, clientID, numWorkingDays, numRestDays, duration;


				cout << "Enter trainer ID: ";
				cin >> trainerID;
				cout << "Enter client ID: ";
				cin >> clientID;


				cout << "Enter number of working days (1-7): ";
				cin >> numWorkingDays;
				Day workingDays[7];
				for (int i = 0; i < numWorkingDays; ++i) {
					int day;
					cout << "Enter working day " << i + 1 << " (0 for Sunday, 6 for Saturday): ";
					cin >> day;
					workingDays[i] = static_cast<Day>(day);
				}


				cout << "Enter number of exercises (up to 5): ";
				
				cin >> numExercises;
				for (int i = 0; i < numExercises; ++i) {
					cout << "Enter exercise " << i + 1 << ": ";
					getline(cin, exercises[i]);
				}


				cout << "Enter duration in minutes: ";
				cin >> duration;


				cout << "Enter number of rest days (1-7): ";
				cin >> numRestDays;
				Day restDays[7];
				for (int i = 0; i < numRestDays; ++i) {
					int day;
					cout << "Enter rest day " << i + 1 << " (0 for Sunday, 6 for Saturday): ";
					cin >> day;
					restDays[i] = static_cast<Day>(day);
				}


				schedule = Schedule(trainerID, clientID, workingDays, numWorkingDays, exercises, numExercises, duration, restDays, numRestDays);


				schedule.displaySchedule();

				system("cls");
				break;

			case 2:
				loggedIn = false;
				system("cls");
				break;

			}
		} while (choice != 3 && loggedIn);
		break;
		case NUTRITION_SPECIALIST:
		do {
			cout << "Gym Management System\n";
			cout << "Hello " << username << " How Was Your Day" << endl;
			cout << "1. Create a Diet Plan\n";
			cout << "2. Display Clients' Diet Plans\n";
			cout << "3. Communicate with a Client\n";
			cout << "4. Logout\n";
			cout << "5. Exit\n";
			cout << "Enter your choice: ";
			cin >> choice;
			switch (choice) {
			case 1:
				specialist.Goal();
				//specialist.createNutritionPlan(string clientName, string goal, string dietaryRestrictions);
				break;
			case 2:
				//specialist.displayClientPlan();

				system("cls");
				break;
			case 3:
				cout << "Enter the message you want to send to the client: ";
				cin >> message;
				//specialist.communicateWithClient(message);

				system("cls");
				break;
			case 4:
				system("cls");
				break;
			default:
				cout << "Invalid choice. Try again.\n";
			}
		} while (choice != 5);
		break;
	case ADMIN:
		do {
			cout << "Gym Management System\n";
			cout << "1. Display All Users\n";
			cout << "2. Show Encrypted Data\n";
			cout << "3. Back\n";
			cout << "Enter your choice: ";

			cin >> choice;
			system("cls");
			switch (choice) {
			case 1:
				displayUsers();
				break;
			case 2:
				storePassword(table, "0");
				storePassword(table, "1");
				storePassword(table, "2");
                
				displayTable(table);
				break;
			case 3:
				cout << "Going Back...\n";
				break;
			default:
				cout << "Invalid choice. Try again.\n";
			}
		} while (choice != 5);
		break;
	}
}

bool loginMenu() {
	string username, password;
	cout << "Enter username: ";
	cin >> username;
	system("cls");
	cout << "Enter password: ";
	cin >> password;
	system("cls");
	cout << "1. Client\n";
	cout << "2. Trainer\n";
	cout << "3. Nutrition Specialist\n";
	cout << "4. Admin\n";
	cout << "Enter your choice: ";
	int accountType;
	cin >> accountType;
	system("cls");
	//cout << clients[username];
	switch (accountType) {
	case 1:
		if (true) {
			cout << "Login successful!\n";
			showUserMenu(username, CLIENT);
			return true;
		}
		else {
			cout << "Invalid username or password. Try again.\n";
			string x;
			cout << "Enter anything to get back to main menu:";
			cin >> x;
		}
		break;
	case 2:
		if (true) {
			cout << "Login successful!\n";
			showUserMenu(username, TRAINER);
			return true;
		}
		else {
			cout << "Invalid username or password. Try again.\n";
			string x;
			cout << "Enter anything to get back to main menu:";
			cin >> x;
		}
		break;
	case 3:
		if (true) {
			cout << "Login successful!\n";
			showUserMenu(username, NUTRITION_SPECIALIST);
			return true;
		}
		else {
			cout << "Invalid username or password. Try again.\n";
			string x;
			cout << "Enter anything to get back to main menu:";
			cin >> x;
		}
		break;
	case 4:
		if (username == "admin" && password == "admin") {
			showUserMenu(username, ADMIN);
			cout << "Login successful!\n";
			return true;
		}
		else {
			cout << "Invalid username or password. Try again.\n";
			string x;
			cout << "Enter anything to get back to main menu:";
			cin >> x;
		}
		break;
	default:
		cout << "Invalid username or password. Try again.\n";
		return false;
		
	}
	
}

void showMainMenu() {
	cout << "Gym Management System\n";
	cout << "1. Login\n";
	cout << "2. Register\n";
	cout << "3. Exit\n";
	cout << "Enter your choice: ";
}

bool registerMenu() {
	string username, password;
	int id;
	cout << "Enter a new username: ";
	cin >> username;
	system("cls");
	cout << "Enter a new password: ";
	cin >> password;
	system("cls");
	cout << "Enter a new ID: ";
	cin >> id;
	system("cls");
	cout << "Which Type of Account You Want To Create\n";
	cout << "1. Client\n";
	cout << "2. Trainer\n";
	cout << "3. Nutrition Specialist\n";
	cout << "Enter your choice: ";
	int accountType;
	cin >> accountType;
	system("cls");
	cout << "Registration successful!.\n";
	switch (accountType) {
		case 1:
			cout << "Client account created.\n";
			showUserMenu(username, CLIENT);
			break;
			
		case 2:
			cout << "Trainer account created.\n";
			showUserMenu(username, TRAINER);
			break;
		case 3:
			cout << "Nutrition Specialist account created.\n";
			showUserMenu(username, NUTRITION_SPECIALIST);
			break;
		default:
			cout << "Invalid choice. Account not created.\n";
			return false;
	}
	return true;
}


int main() {
	int choice;
    do {
		showMainMenu();
        cin >> choice;
		system("cls");
        switch (choice) {
			case 1:
				loginMenu();
				break;
			case 2: registerMenu(); loggedIn = true; break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3 && !loggedIn);

    return 0;
}
