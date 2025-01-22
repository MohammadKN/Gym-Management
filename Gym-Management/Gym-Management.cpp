#include <iostream>
#include <fstream>
#include <map>
#include "TreeNode.h"
#include "Market.h"

using namespace std;


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

int mainMenu() {
	cout << "Gym Management System\n";
	cout << "1. Manage users \n";
	cout << "2. Machine Queues\n";
	cout << "3. Marketplace\n";
	cout << "4. Manage members by ID in Different Orders\n";
	cout << "5. Binary Search\n";
	cout << "6. Map Members to IDs\n";
	cout << "7. Exit\n";
	int x;
	cin >> x;
	return x;
}
void manageUsers(LinkedList& l) {
	cout << "1. Add User\n";
	cout << "2. Remove User By ID\n";
	cout << "3. Display Users\n";
	cout << "Enter Your Choice: \n";
	int x;
	cin >> x;
	if (x == 1) {
		int id = 0;
		string name = "";
		int age = 0;
		string membershipType = "Normal";

		cout << "Enter User ID: ";
		cin >> id;
		cout << "Enter User Name: ";
		cin >> name;
		cout << "Enter User Age: ";
		cin >> age;
		cout << "Enter Membership Type: ";
		cin >> membershipType;

		User newUser = { id, name, age, membershipType };
		
		l.insertAtLast(newUser);

		cout << "User added successfully.\n";
	}
	else if (x == 2) {
		cout << "Enter User ID To Remove: ";
		int id;
		cin >> id;
		l.deleteNode(id);
	}
	else if (x == 3) {
		l.display();
	}
}
void machinesQueue(Queue& q) {
	cout << "1. Add Machine to repairment Queue\n";
	cout << "2. display repairment Queue\n";
	cout << "3. Repair a machine\n";
	int input;
	cin >> input;
	if (input == 1) {
		Machine m;
		cout << "Enter Machine ID: ";
		cin >> m.id;
		cout << "Enter Name: ";
		cin >> m.name;
		q.enqueue(m);
		cout << "Machine Enqueued!" << endl;
	}
	else if (input == 2) {
		q.display();
	}
	else if (input == 3) {
		q.dequeue();
	}
}
void enterMarketplace(Stack& s) {
	cout << "1. Add Item To Cart\n";
	cout << "2. Undo Last Added Item\n";
	cout << "3. My Cart\n";
	int input = 0;
	cin >> input;
	if (input == 1) {
		marketplace(s);
	}
	else if (input == 2) {
		s.pop();
	}
	else if (input == 3) {
		s.display();
	}
}
int main() {
	LinkedList linkedList;
	Queue q;
	Stack s;
	int choice = 0;
    do {
		choice = mainMenu();
		int usersCount = 0;
		User* users = new User[usersCount];
		
		system("cls"); 
        switch (choice) {
			case 1: manageUsers(linkedList); break;
			case 2: machinesQueue(q); break;
			case 3: enterMarketplace(s); break;
			case 4: bubbleSortUsersById(users,usersCount); break;
			/*case 4: binarySearch(); break;
			case 5: hashUsers(); break;*/
			case 7: cout << "Exit."; break;
            default: cout << "Invalid choice. Try again.\n";
        }
		
    } while (choice!=7);

    return 0;
}