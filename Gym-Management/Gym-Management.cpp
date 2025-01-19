#include <iostream>
#include <fstream>
#include <map>
#include "trainer.h"
#include "nutritionSpecialist.h"
#include "Schedule.h"
#include "hash.h"
#include "Trainer.h"
#include "client.h"
#include "User.h"
#include "searchTree.cpp"
#include "stackQueue.cpp"

using namespace std;

LinkedList linkedListUsers;
Stack stackUsers;
Queue queueUsers;
IDBinarySearchTree bstUsers;
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
	string exercises[5] = { "Push-ups", "Squats", "Plank", "Lunges", "Pull-ups" };
	Schedule schedule;
	NutritionSpecialist specialist;

	switch (activeUser->accountType) {
	case CLIENT:
		do {
			system("cls");
			cout << "Gym Management System\n";
			cout << "Hello " << activeUser->username << " How Was Your Day" << endl;
			cout << "1. Access Schedule\n";
			cout << "2. Access Diet Plan\n";
			cout << "3. Go To Marketplace\n";
			cout << "4. Update Information\n";
			cout<<  "5. Logout\n"; 
			cout << "6. Exit\n";
			cout << "Enter your choice: ";
			cin >> choice;
			switch (choice) {
			case 1:
				system("cls");
				if (schedule.getClientID()) {
					schedule.displaySchedule();
				}
				else {
					cout << "No schedule found...\n";
				}
				system("cls");
				break;
			case 2:
				system("cls");
				client.accessDiet(); 
				break;
			case 3 :
				system("cls");
				client.marketplace(); 
				client.buy();
				client.printBill();
				break;
			case 4 : 
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
				break;
			case 5:
				system("cls");
				break;
			default:
				cout << "Invalid choice. Try again.\n";
			}
		} while (choice != 5);
		break;
	case TRAINER: {

		do {
			system("cls");
			cout << "Gym Management System\n";
			cout << "Hello " << activeUser->username << ", How Was Your Day?" << endl;
			cout << "1. Create Schedule\n";
			cout << "2. Search for a Trainer by ID" << endl;
			cout << "3. Logout\n";
			cout << "Enter your choice: ";
			cin >> choice;

			switch (choice) {
			case 1: {
				system("cls");
				break;
			}
			case 2: {
				system("cls");
				int searchID;
				cout << "Enter User ID to search: ";
				cin >> searchID;

				int* foundUser = bstUsers.searchId(&searchID);
				if (foundUser) {
					cout << "User Found:\n";
					cout<<*foundUser;
				}
				else {
					cout << "User not found with ID: " << searchID << endl;
				}
			}
			case 3: {
				system("cls");
				int searchID;
				cout << "Enter User ID to search: ";
				cin >> searchID;

				int* foundUser = bstUsers.searchId(&searchID);
				if (foundUser) {
					cout << "User Found:\n";
					cout<<foundUser<<endl;
				}
				else {
					cout << "User not found with ID: " << searchID << endl;
				}
				break;
			}
			case 5:
				return;
				system("cls");
				break;

			default:
				cout << "Invalid choice, try again!" << endl;
			}
		} while (choice != 5);

		break;
	}
	case NUTRITION_SPECIALIST:


		do {
			system("cls");
			cout << "Gym Management System\n";
			cout << "Hello " << activeUser->username << " How Was Your Day" << endl;
			cout << "1. Create a Diet Plan\n";
			cout << "2. Display Clients' Diet Plans\n";
			cout << "3. Logout\n";
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
				break;

			default:
				cout << "Invalid choice. Try again.\n";
			}
		} while (choice != 3);
		break;
	}
};
bool lsearch(User arr[], int size, int target) {
	for (int i = 0; i < size; i++) {
		if (arr[i].id == target) {
			cout << target << " is in the array." << endl;
			return true;
		}
	}
	cout << target << " is not in the array." << endl;
	return false;
}

int bSearch(int bottom, int top, int mid, int bTarget, User users[], int const userCount) {

	int* arr = new int[userCount];

	bool found = 0;
	for (int i = 0; i < userCount; i++) {
		arr[i] = users[i].id;
	}
	while (found == 0 && bottom <= top) {
		mid = (top + bottom) / 2;
		if (bTarget == arr[mid]) {
			found = 1;
			return mid;
		}
		else {
			if (bTarget < arr[mid]) {
				top = mid - 1;
			}
			else {
				bottom = mid + 1;
			}

		}

	}

	if (!found) {
		cout << "Target not found";
	}
}
void bubbleSortUsersById(User users[], int userCount) {
	for (int i = 0; i < userCount - 1; i++) {
		for (int j = 0; j < userCount - i - 1; j++) {
			if (users[j].id > users[j + 1].id) {

				User temp = users[j];
				users[j] = users[j + 1];
				users[j + 1] = temp;
			}
		}
	}
}
void showDataStructureMenu(User*& users, int& userCount) {
	int choice;

	int ID;
	string username, password;
	UserType type = CLIENT;
	User dsUsers[5];
	int searchID;
	int foundID;
	int count = 0;
	int subMenuChoice1 = 0;
	int subMenuChoice2 = 0;
	int subMenuChoice3 = 0;
	int subMenuChoice4 = 0;
	int subMenuChoice5 = 0;
	do {
		cout << "Which Data Structure You Want To Display\n";
		cout << "0. Add User\n";
		cout << "1. Linked List\n";
		cout << "2. Stack\n";
		cout << "3. Queue\n";
		cout << "4. Binary Search Tree\n";
		cout << "5. Array\n";
		cout << "6. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		int accountType = -1;
		switch (choice) {
		case 0: {
			system("cls");
			cout << "Enter User ID: ";
			cin >> ID;
			cout << "Enter Username: ";
			cin >> username;
			cout << "Enter Password: ";
			cin >> password;
			cout << "Enter Account Type: \n";
			cout << "1. Client\n";
			cout << "2. Trainer\n";
			cout << "3. Nutrition Specialist\n";
			cin >> accountType;
			switch (accountType) {
			case 1:
				type = CLIENT;
				cout << "Client  Added.\n";
				break;
			case 2:
				type = TRAINER;
				cout << "Trainer Added.\n";
				break;
			case 3:
				type = NUTRITION_SPECIALIST;
				cout << "Nutrition Specialist Added.\n";
				break;
			default:
				cout << "Invalid choice. Account not created.\n";
			}
			users[userCount] = User(username, password, ID, type);

			linkedListUsers.insertAtLast(users[userCount].id);
			stackUsers.push(users[userCount].id);
			queueUsers.enqueue(users[userCount].id);
			bstUsers.insertId(&users[userCount].id);
			userCount++;

			cout << "User added successfully!\n";
			break;
		}
		case 1: {
			system("cls");
			cout << "1. Display Linked List\n";
			cout << "2. Insert at Beginning\n";
			cout << "3. Insert at Last\n";
			cout << "4. Insert at Position\n";
			cout << "5. Delete at Beginning\n";
			cout << "6. Delete at Last\n";
			cout << "7. Delete at Position\n";
			cout << "8. Search\n";
			cout << "9. Update\n";
			cin >> subMenuChoice1;

			switch (subMenuChoice1) {

			case 1:
				system("cls");
				cout << "The IDs in Linked List\n";
				linkedListUsers.display();
				break;
			case 2:
				system("cls");
				cout << "Enter User ID to insert at beginning: ";
				cin >> ID;
				linkedListUsers.insertAtFirst(ID);
				break;
			case 3:
				system("cls");
				cout << "Enter User ID to insert at last: ";
				cin >> ID;
				linkedListUsers.insertAtLast(ID);
				break;
			case 4:
				system("cls");
				int position;
				cout << "Enter User ID to insert: ";
				cin >> ID;
				cout << "Enter position: ";
				cin >> position;
				linkedListUsers.insert(ID);
				break;
			case 5:
				system("cls");
				linkedListUsers.deleteAtFirst();
				break;
				cout << "The IDs in Linked List\n";
				linkedListUsers.display();
				break;
			}
		}
		case 2: {
			system("cls");
			cout << "1. Display Stack\n";
			cout << "2. Push\n";
			cout << "3. Pop\n";
			cout << "Enter your choice: ";
			cin >> subMenuChoice2;
			switch (subMenuChoice2) {
			case 1:
				system("cls");
				cout << "The IDs in Stack\n";
				stackUsers.display();
				break;
			case 2:
				system("cls");
				cout << "Enter User ID to push: ";
				cin >> ID;
				stackUsers.push(ID);
				break;
			case 3:
				system("cls");
				stackUsers.pop();
				break;
			}
			break;
		}
		case 3: {
			system("cls");
			cout << "1. Display Queue\n";
			cout << "2. Enqueue\n";
			cout << "3. Dequeue\n";
			cout << "Enter your choice: ";
			cin >> subMenuChoice3;
			switch (subMenuChoice3) {
			case 1:
				system("cls");
				cout << "The IDs in Queue\n";
				queueUsers.display();
				break;
			case 2:
				system("cls");
				cout << "Enter User ID to enqueue: ";
				cin >> ID;
				queueUsers.enqueue(ID);
				break;
			case 3:
				system("cls");
				queueUsers.dequeue();
				break;
			}
			break;
		}
		case 4: {
			system("cls");
			cout << "1. Display Binary Search Tree\n";
			cout << "2. Insert\n";
			cout << "3. Search\n";
			cout << "Enter your choice: ";
			cin >> subMenuChoice4;
			switch (subMenuChoice4) {
			case 1:
				system("cls");
				cout << "The IDs in Binary Search Tree\n";
				bstUsers.displayIds();
				break;
			case 2:
				system("cls");
				cout << "Enter User ID to insert: ";
				cin >> ID;
				bstUsers.insertId(&ID);
				break;
			case 3:
				system("cls");
				cout << "Enter User ID to search: ";
				cin >> ID;
				int* foundId = bstUsers.searchId(&ID);
				if (foundId) {
					cout << "User found with ID: " << *foundId << endl;
				}
				else {
					cout << "User not found with ID: " << ID << endl;
				}
				break;
			}
			break;
		}
		case 5: {
			system("cls");
			cout << "1. Bubble Sort\n";
			cout << "2. Binary Search\n";
			cout << "3. Linear Search\n";
			cout << "4. Display\n";
			cout << "Enter your choice: ";
			cin >> subMenuChoice5;
			switch (subMenuChoice5) {
			case 1:
				system("cls");
				bubbleSortUsersById(dsUsers, userCount);
				cout << "Users sorted by ID\n";
				break;
			case 2:
				system("cls");
				cout << "Enter User ID to search: ";
				cin >> searchID;
				foundID = bSearch(0, users->id, users->id / 2, searchID, users, userCount);
				if (foundID) {
					cout << "User found with ID: " << foundID << endl;
				}
				else {
					cout << "User not found with ID: " << searchID << endl;
				}
				break;
			case 3:
				system("cls");
				cout << "Enter User ID to search: ";
				cin >> searchID;
				foundID = lsearch(dsUsers, userCount, searchID);
				if (foundID) {
					cout << "User found with ID: " << foundID << endl;
				}
				else {
					cout << "User not found with ID: " << searchID << endl;
				}
				break;
			case 4:
				system("cls");
				displayUsers(users, userCount);
				break;
			}
			break;
		}
		}
	} while (choice != 6);
}


void showMainMenu() {
	cout << "Gym Management System\n";
	cout << "1. Try Data Structures\n";
	cout << "2. Add User\n";
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

	switch (accountType) {
	case 1:
		cout << "Client account created.\n";
		
		linkedListUsers.insertAtLast(id);
		newUsers[userCount] = User(username, password, id, CLIENT);
		activeUser = &newUsers[userCount];
		delete[] users;
		users = newUsers;
		userCount++;
		showUserMenu(users, userCount);
		break;

	case 2:
		cout << "Trainer account created.\n";
		newUsers[userCount] = User(username, password, id, TRAINER);
		activeUser = &newUsers[userCount];
		delete[] users;
		users = newUsers;
		userCount++;
		showUserMenu(users, userCount);
		break;
	case 3:
		cout << "Nutrition Specialist account created.\n";
		newUsers[userCount] = User(username, password, id, CLIENT);
		activeUser = &newUsers[userCount];
		delete[] users;
		users = newUsers;
		userCount++;
		showUserMenu(users, userCount);
		break;
	default:
		cout << "Invalid choice. Account not created.\n";
		return false;
	}

	cout << "Logout Successfull\n";
	
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
			case 1: showDataStructureMenu(users, userCount); break;
			case 2: registerMenu(users,userCount); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice!=3);

    return 0;
}