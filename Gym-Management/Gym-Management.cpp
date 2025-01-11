#include <iostream>
#include "linkedList.cpp"

using namespace std;

int main() {
	linkedList l(6);
	l.displayD();
	l.insertAtFirstD(5);
	l.displayD();
	l.insertAtFirstD(4);
	l.displayD();
	l.insertAtFirstD(3);
	l.displayD();
	l.insertAtFirstD(2);
	l.displayD();
	l.insertAtFirstD(1);
	l.displayD();
	l.insertAtLastD(8);
	l.displayD();
	l.insertD(7);
	l.displayD();
	l.deleteAtFirstD();
	l.displayD();
	l.deleteAtLastD();
	l.displayD();
	l.deleteNodeD(5);
	l.displayD();
	l.insertD(5);
	l.displayD();
	return 0;
}