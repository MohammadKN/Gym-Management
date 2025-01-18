#pragma once

#include <iostream>

using namespace std;

struct Node {
	int item;
	Node* next;
};
struct DNode {
	int item;
	DNode* next;
	DNode* prev;
};
class LinkedList {
private:

	Node* head;
	DNode* Dhead;
public:
	LinkedList(int headVal) {
		head = new Node;
		Dhead = new DNode;
		Dhead->item = headVal;
		head->item = headVal;
		head->next = NULL;
	}
	LinkedList() {
		head = new Node;
		Dhead = new DNode;
		Dhead->item = 0;
		head->item = 0;
		head->next = nullptr;
	}
	bool isEmpty() {
		if (head == NULL)
			return true;
		else
			return false;
	}
	void display() {
		Node* current = head;

		while (current != NULL) {
			cout << current->item << " -> ";
			current = current->next;
		}
		cout << endl;
	}
	void displayD() {
		if (Dhead == NULL) {
			cout << "The list is empty." << endl;
			return;  // Return early if the list is empty.
		}

		DNode* current = Dhead;
		while (current != NULL) {
			cout << current->item;
			if (current->next != NULL) {
				cout << " <-> ";  // Use <-> for doubly linked list display
			}
			current = current->next;
		}
		cout << endl;
	}
	Node* search(int val) {
		Node* temp = head;
		while (temp != NULL && val != temp->item) {
			if (temp->item == val) {
				return temp;
			}
			else {
				temp = temp->next;
			}
		}
	}
	void insertAtFirst(int val) {
		Node* temp = new Node;
		temp->item = val;
		temp->next = head;
		head = temp;
	}
	void insertAtLast(int val) {
		Node* temp = new Node;
		Node* last = head;
		temp->item = val;

		while (last->next != NULL) {
			last = last->next;
		}

		last->next = temp;
		temp->next = NULL;
	}
	void insert(int val) {
		Node* temp = new Node;
		temp->item = val;
		Node* current = head;
		while (current != NULL && current->next->item < val) {
			current = current->next;
		}
		temp->next = current->next;
		current->next = temp;

	}
	void deleteAtFirst() {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	void deleteAtLast() {
		Node* prev = head;
		Node* last = head->next;
		while (last->next != NULL) {
			prev = last;
			last = last->next;
		}
		delete last;
		prev->next = NULL;
	}
	void deleteNode(int val) {
		Node* temp = head->next;
		Node* prev = head;
		while (temp->next != NULL && temp->item != val) {
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		delete temp;
	}
	void insertAtFirstD(int val) {
		DNode* temp = new DNode;
		temp->item = val;
		temp->next = Dhead;
		Dhead = temp;
		Dhead->prev = NULL;
	}
	void insertAtLastD(int val) {
		DNode* temp = new DNode;
		DNode* last = Dhead;
		temp->item = val;

		while (last->next != NULL) {
			last = last->next;
		}

		last->next = temp;
		temp->prev = last;
		temp->next = NULL;
	}
	void insertD(int val) {
		DNode* temp = new DNode;
		temp->item = val;
		DNode* current = Dhead;
		while (current != NULL && current->next->item < val) {
			current = current->next;
		}
		temp->next = current->next;
		current->next = temp;
		temp->prev = current;
		temp->next->prev = temp;

	}
	void deleteAtFirstD() {
		DNode* temp = Dhead;
		Dhead = Dhead->next;
		Dhead->prev = NULL;
		delete temp;
	}
	void deleteAtLastD() {
		DNode* prev = Dhead;
		DNode* last = Dhead->next;
		while (last->next != NULL) {
			prev = last;
			last = last->next;
		}
		delete last;
		prev->next = NULL;
	}
	void deleteNodeD(int val) {
		DNode* temp = Dhead->next;
		DNode* prev = Dhead;
		while (temp->next != NULL && temp->item != val) {
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		temp->next->prev = prev;
		delete temp;
	}
};

