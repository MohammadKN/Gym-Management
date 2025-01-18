#include <iostream>
#include <fstream>
#include <map>
#include "trainer.h"
#include "nutritionSpecialist.h"
#include "Schedule.h"
#include "hash.h"
#include "Trainer.h"
#include "client.h"
#include "linkedlist.cpp"
#include "searchTree.cpp"
#include "stackQueue.cpp"
#include "graphs.cpp"

using namespace std;

LinkedList clientsID,clientsPassword;

enum UserType { CLIENT, TRAINER, NUTRITION_SPECIALIST, ADMIN };
struct User {
	string username;
	string password;
	int id;
	UserType accountType;
};

bool loggedIn = false;
User* activeUser;


Client client;
Trainer trainer;


void displayUsers(User*& users, int& userCount) {
	cout << "Clients:\n";
	for (int i = 0; i < userCount; ++i) {
		users[i].accountType == CLIENT ? cout << i << ". " << users[i].username << endl : cout << "No Clients\n";
	}
	cout << "Trainers:\n";
	for (int i = 0; i < userCount; ++i) {
		users[i].accountType == TRAINER ? cout << i << ". " << users[i].username << endl : cout << "No Trainers\n";
	}
	cout << "Nutrition Specialists:\n";
	for (int i = 0; i < userCount; ++i) {
		users[i].accountType == NUTRITION_SPECIALIST ? cout << i << ". " << users[i].username << endl : cout << "No Nutrition Specialists\n";
	}
}
void showUserMenu(User* users, int& userCount) {
	int choice;

	Day workingDays[] = { Monday, Wednesday, Friday };
	Day restDays[] = { Sunday, Tuesday };
	

	string message;

	IDBinarySearchTree trainerTree;
	bool loggedIn = true;
	string table[MAX];
	string exercises[5] = { "Push-ups", "Squats", "Plank", "Lunges", "Pull-ups" };
	Schedule schedule(101, 202, workingDays, 3, exercises, 5, 60, restDays, 2);
	NutritionSpecialist specialist("2114", "Faris hijazi", 35, 5, "best nuitrtion specialist award 2024", "07720582027");

	switch (activeUser->accountType) {
	case CLIENT:
		do {
			cout << "Gym Management System\n";
			cout << "Hello " << activeUser->username << " How Was Your Day" << endl;
			cout << "1. Access Schedule\n";
			cout << "2. Access Diet Plan\n";
			cout << "3. Go To Marketplace\n";
			cout << "4. Access Schedule \n";
			cout << "5. Update Information\n";
			cout<<  "6. Logout\n"; 
			cout << "7. Exit\n";
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
			case 6:
				loggedIn = false;
				system("cls");
				break;
			default:
				cout << "Invalid choice. Try again.\n";
			}
		} while (choice != 7 && loggedIn);
		break;
	case TRAINER: {

		do {
			cout << "Gym Management System\n";
			cout << "Hello " << activeUser->username << ", How Was Your Day?" << endl;
			cout << "1. Add a Trainer" << endl;
			cout << "2. Search for a Trainer by ID" << endl;
			cout << "3. Display All Trainers" << endl;
			cout << "4. Logout\n";
			cout << "5. Exit\n";
			cout << "Enter your choice: ";
			cin >> choice;

			switch (choice) {
			case 2: {
				system("cls");
				int searchID;
				cout << "Enter Trainer ID to search: ";
				cin >> searchID;

				Trainer* foundTrainer = trainerTree.searchTrainer(searchID);
				if (foundTrainer) {
					cout << "Trainer Found:\n";
					foundTrainer->displayTrainerDetails();
				}
				else {
					cout << "Trainer not found with ID: " << searchID << endl;
				}
				break;
			}
			case 3:
				system("cls");
				trainerTree.displayTrainers(); 
				break;

			case 4:
				loggedIn = false; 
				system("cls");
				break;

			default:
				cout << "Invalid choice, try again!" << endl;
			}
		} while (choice != 5 && loggedIn);

		break;
	}
	case NUTRITION_SPECIALIST:


		do {
			cout << "Gym Management System\n";
			cout << "Hello " << activeUser->username << " How Was Your Day" << endl;
			cout << "1. Create a Diet Plan\n";
			cout << "2. Display Clients' Diet Plans\n";
			cout << "3. Logout\n";
			cout << "4. Exit\n";
			cout << "Enter your choice: ";
			cin >> choice;
			switch (choice) {
			case 1: {
				string clientName, goal, dietaryRestrictions;

				cout << "Enter client's name: ";
				cin >> clientName;

				cout << "Enter goal: ";
				cin.ignore();
				getline(cin, goal);
				cout << "Enter dietary restrictions: ";
				cin >> dietaryRestrictions;

				specialist.createNutritionPlan(clientName, goal, dietaryRestrictions);
				break;
			}

			case 2:
				specialist.displayClientPlan();
				break;

			case 3:
				loggedIn = false;
				break;

			default:
				cout << "Invalid choice. Try again.\n";
			}
		} while (choice != 4 && loggedIn);
		break;
	case ADMIN:
		do {
			cout << "Gym Management System\n";
			cout << "1. Display All Users\n";
			cout << "2. Show Encrypted Data\n";
			cout << "3. Add Trainer\n";
			cout << "3. Back\n";
			cout << "Enter your choice: ";

			cin >> choice;
			system("cls");
			switch (choice) {
			case 1:
				displayUsers(users, userCount);
				break;
			case 2:
				storePassword(table, "0");
				storePassword(table, "1");
				storePassword(table, "2");
                
				displayTable(table);
				break;
			case 3: {
				system("cls");
				int trainerID, age, experience;
				string name, achievements, phone;

				cout << "Enter Trainer ID: ";
				cin >> trainerID;
				cout << "Enter Full Name: ";
				cin.ignore();
				getline(cin, name);
				cout << "Enter Age: ";
				cin >> age;
				cout << "Enter Years of Experience: ";
				cin >> experience;
				cout << "Enter Achievements: ";
				cin.ignore();
				getline(cin, achievements);
				cout << "Enter Phone Number: ";
				cin >> phone;


				Trainer* newTrainer = new Trainer(trainerID, name, age, experience, achievements, phone, Schedule());
				trainerTree.insertTrainer(newTrainer);

				cout << "Trainer added successfully!\n";
				break;
			}
			case 4:
				cout << "Going Back...\n";
				break;
			default:
				cout << "Invalid choice. Try again.\n";
			}
		} while (choice != 5);
		break;
	}
}

bool loginMenu(User* users, int userCount) {
	string username, password;
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;

	cout << "1. Client\n";
	cout << "2. Trainer\n";
	cout << "3. Nutrition Specialist\n";
	cout << "4. Admin\n";
	cout << "Enter your choice: ";
	int accountType;
	cin >> accountType;


	switch (accountType) {
	case 1:
		cout << "Client account created.\n";
		for (int i = 0; i < userCount; ++i) {
			if (users[i].username == username && users[i].password == password) {
				if (users[i].accountType == CLIENT) {
					activeUser = &users[i]; 
					cout << "Login successful!\n";
					showUserMenu(&users[i], userCount);
					return true;
				}
			}
		}
		showUserMenu(users, userCount);
		break;

	case 2:
		cout << "Trainer account created.\n";
		for (int i = 0; i < userCount; ++i) {
			if (users[i].username == username && users[i].password == password) {
				if (users[i].accountType == TRAINER) {
					activeUser = &users[i];
					cout << "Login successful!\n";
					showUserMenu(&users[i], userCount);
					return true;
				}
			}
		}
		showUserMenu(users, userCount);
		break;
	case 3:
		cout << "Nutrition Specialist account created.\n";
		for (int i = 0; i < userCount; ++i) {
			if (users[i].username == username && users[i].password == password) {
				if (users[i].accountType == NUTRITION_SPECIALIST) {
					activeUser = &users[i];
					cout << "Login successful!\n";
					showUserMenu(&users[i], userCount);
					return true;
				}
			}
		}
		showUserMenu(users, userCount);
		break;
	default:
		cout << "Invalid choice. Account not created.\n";
		return false;
	}
	cout << "Invalid username or password. Try again.\n";
	return false;
}

void showMainMenu() {
	cout << "Gym Management System\n";
	cout << "1. Login\n";
	cout << "2. Register\n";
	cout << "3. Exit\n";
	cout << "Enter your choice: ";
}

bool registerMenu(User*& users, int& userCount) {
	string username, password;
	int id;
	cout << "Enter a new username: ";
	cin >> username;
	cout << "Enter a new password: ";
	cin >> password;
	
	cout << "Enter a new ID: ";
	cin >> id; //while (clientsID.search(id) != nullptr);
	cout << "Which Type of Account You Want To Create\n";
	cout << "1. Client\n";
	cout << "2. Trainer\n";
	cout << "3. Nutrition Specialist\n";
	cout << "Enter your choice: ";
	int accountType;
	cin >> accountType;

	User* newUsers = new User[userCount + 1];
	for (int i = 0; i < userCount; ++i) {
		newUsers[i] = users[i];
	}
	system("cls");
	cout << "Registration successful!.\n";

	switch (accountType) {
	case 1:
		cout << "Client account created.\n";
		
		clientsID.insertAtLast(id);
		newUsers[userCount] = { username, password, id, CLIENT };
		activeUser = &newUsers[userCount];
		delete[] users;
		users = newUsers;
		userCount++;
		showUserMenu(users, userCount);
		return false;
		break;

	case 2:
		cout << "Trainer account created.\n";
		newUsers[userCount] = { username, password, id, TRAINER };
		activeUser = &newUsers[userCount];
		delete[] users;
		users = newUsers;
		userCount++;
		showUserMenu(users, userCount);
		return false;
		break;
	case 3:
		cout << "Nutrition Specialist account created.\n";
		newUsers[userCount] = { username, password, id, NUTRITION_SPECIALIST };
		activeUser = &newUsers[userCount];
		delete[] users;
		users = newUsers;
		userCount++;
		showUserMenu(users, userCount);
		return false;
		break;
	default:
		cout << "Invalid choice. Account not created.\n";
		return false;
	}
	loggedIn = true;
}
int main() {
	int choice;
	int userCount = 0;
	User* users = new User[userCount + 1];
    do {
		showMainMenu();
        cin >> choice;
		system("cls");
        switch (choice) {
			case 1:
				loginMenu(users, userCount);
				break;
			case 2: registerMenu(users,userCount); loggedIn = true; break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3 && !loggedIn);

    return 0;
}
