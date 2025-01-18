#include <iostream>
#include "linkedList.cpp"
#include "Gym-Management.cpp"

using namespace std;

bool search(Node* head, int target) {

	Node* current = head;
	while (current != NULL) {
		if (current->item == target) {
			cout << target << "is in linked list";
			return true;
			break;
		}
		else {
			cout << target << "is not in linked list";

		}
		current = current->next;
	}
	return false;
}

int bSearch(int bottom, int top, int mid, int bTarget, User* users[],int const userCount) {

	int* arr = new int[userCount];

	bool found = 0;
	for (int i = 0; i < userCount; i++) {
		arr[i] = users[i]->id; 
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
