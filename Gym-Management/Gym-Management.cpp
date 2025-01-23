#include <iostream>
#include <fstream>
#include <map>
#include "TreeNode.h"
#include "Market.h"

using namespace std;

#define MAX  10

int userCount = 0;
User users[10];
User emptyUser = { 0,"",0, ""};

int hashFunction(int id) {
	return id % MAX;
}

void storeID(int idtable[], int id) {
	int hashv = hashFunction(id);
	while (idtable[hashv] != 0) {
		hashv = (hashv + 1) % MAX;
	}
}

void displayTable(int table[]) {
	cout << "Index | Password\n";
	cout << "-----------------\n";
	for (int i = 0; i < userCount; i++) {
		if (table[i] != 0)
			cout << "  " << i << "   | " << table[i] << "\n";
	}
}

int lsearch(int target) {
	for (int i = 0; i < userCount; i++) {
		if (users[i].id == target) {
			cout << target << " is in the array." << endl;
			return i;
		}
	}
	cout << target << " is not in the array." << endl;
	return -1;
}

int bSearch(int bottom, int top, int mid, int bTarget) {

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
		cout << "Target not found\n";
		return -1;
	}
}
void bubbleSortUsersById() {
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

void manageUsers(LinkedList& l, TreeNode*& root) {
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
		root = insertNode(root, id);
		users[userCount++] = newUser;
		
		cout << "User added successfully.\n";
	}
	else if (x == 2) {
		cout << "Enter User ID To Remove: ";
		int id;
		cin >> id;
		l.deleteNode(id);
		int index = lsearch(id);
		if (index == -1) {
			cout << "ID Not Found\n";
		}
		users[index] = emptyUser;
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

void binarySearchTree(TreeNode*& root) {
	cout<<"1. Search for User by ID\n";
	cout<<"2. Display Users In Different Orders\n";
	int input;
	cin >> input;
	if (input == 1) {
		cout<<"Enter User ID to search: ";
		int id;
		cin >> id;
		int result = searchNode(root, id);
	
		if (result != -1) {
			cout << "ID " << id << " found." << endl;
		}
		else {
			cout << "ID " << id << " not found." << endl;
		}
	}
	else if (input == 2) {
		
    	displayIds(root);
	}

}

void binarySearch() {
	bubbleSortUsersById();
	int mid = int((userCount -1)/2);
	cout<<"Enter the id you want to search for:";
	int id;
	cin >> id;

	int results = bSearch(0,userCount,mid,id);
	if(results >= 0)
		cout<<"ID found at index "<<results<<endl;
	
		
}
void hashUsers() {
	cout << "Here is the Encrypted Users Data:";
	int ids[5];
	for (int i = 0; i < userCount; i++) {
		ids[i] = users[i].id;
	}
	for (int i = 0; i < userCount; i++)
		storeID(ids, i);
	displayTable(ids);
}

int mainMenu() {
	cout << "\nGym Management System\n";
	cout << "1. Manage users \n";
	cout << "2. Machine Queues\n";
	cout << "3. Marketplace\n";
	cout << "4. Manage members by ID in Different Orders\n";
	cout << "5. Binary Search\n";
	cout << "6. View Encrypted Users IDs\n";
	cout << "7. Exit\n";
	int x;
	cin >> x;
	return x;
}
int main() {
	LinkedList linkedList;
	Queue q;
	Stack s;
	TreeNode* root = nullptr;

	int choice = 0;
    do {
		choice = mainMenu();
		
		system("cls"); 
        switch (choice) {
			case 1: manageUsers(linkedList,root); break;
			case 2: machinesQueue(q); break;
			case 3: enterMarketplace(s); break;
			case 4: binarySearchTree(root); break;
			case 5: binarySearch(); break;
			case 6: hashUsers(); break;
			case 7: cout << "Exit."; break;
            default: cout << "Invalid choice. Try again.\n";
        }
		
    } while (choice!=7);

    return 0;
}