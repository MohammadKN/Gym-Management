#include <iostream>
#include <string>

using namespace std;

struct User {
	int id;
	string name;
	int age;
	string membershipType;
};

struct Node {
	User item;
	Node* next;
};

struct LinkedList {
	Node* head;

	LinkedList() {
		head = NULL;
	}

	bool isEmpty() {
		return head == NULL;
	}

	void display() {
		Node* current = head;
		while (current != NULL) {
			cout << "ID: " << current->item.id
				<< ", Name: " << current->item.name
				<< ", Age: " << current->item.age
				<< ", Membership: " << current->item.membershipType
				<< " -> ";
			current = current->next;
		}
		cout << "NULL" << endl;
	}

	void insertAtFirst(User val) {
		Node* temp = new Node;
		temp->item = val;
		temp->next = head;
		head = temp;
	}

	void insertAtLast(User val) {
		Node* temp = new Node;
		temp->item = val;

		if (head == NULL) {
			head = temp;
			temp->next = NULL;
			return;
		}

		Node* last = head;
		while (last->next != NULL) {
			last = last->next;
		}

		last->next = temp;
		temp->next = NULL;
	}

	void deleteAtFirst() {
		if (head == NULL) return;
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	void deleteAtLast() {
		if (head == NULL) return;

		Node* prev = NULL;
		Node* last = head;

		while (last->next != NULL) {
			prev = last;
			last = last->next;
		}

		if (prev == NULL) {
			delete head;
			head = NULL;
		}
		else {
			prev->next = NULL;
			delete last;
		}
	}

	void deleteNode(int id) {
		if (head == NULL) return;

		if (head->item.id == id) {
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}

		Node* temp = head->next;
		Node* prev = head;

		while (temp != NULL && temp->item.id != id) {
			prev = temp;
			temp = temp->next;
		}

		if (temp == NULL) return;

		prev->next = temp->next;
		delete temp;
	}
};
