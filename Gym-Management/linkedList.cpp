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
    DNode* dHead;
public:
    LinkedList(int headVal) {
        head = new Node;
        dHead = new DNode;
        dHead->item = headVal;
        head->item = headVal;
        head->next = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->item << " -> ";
            current = current->next;
        }
        cout << endl;
    }

    void displayD() {
        if (dHead == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        DNode* current = dHead;
        while (current != nullptr) {
            cout << current->item;
            if (current->next != nullptr) {
                cout << " <-> ";
            }
            current = current->next;
        }
        cout << endl;
    }

    Node* search(int val) {
        Node* temp = head;
        while (temp != nullptr && val != temp->item) {
            if (temp->item == val) {
                return temp;
            } else {
                temp = temp->next;
            }
        }
        return nullptr;
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

        while (last->next != nullptr) {
            last = last->next;
        }

        last->next = temp;
        temp->next = nullptr;
    }

    void insert(int val) {
        Node* temp = new Node;
        temp->item = val;
        Node* current = head;
        while (current != nullptr && current->next->item < val) {
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
        while (last->next != nullptr) {
            prev = last;
            last = last->next;
        }
        delete last;
        prev->next = nullptr;
    }

    void deleteNode(int val) {
        Node* temp = head->next;
        Node* prev = head;
        while (temp->next != nullptr && temp->item != val) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
    }

    void insertAtFirstD(int val) {
        DNode* temp = new DNode;
        temp->item = val;
        temp->next = dHead;
        dHead = temp;
        dHead->prev = nullptr;
    }

    void insertAtLastD(int val) {
        DNode* temp = new DNode;
        DNode* last = dHead;
        temp->item = val;

        while (last->next != nullptr) {
            last = last->next;
        }

        last->next = temp;
        temp->prev = last;
        temp->next = nullptr;
    }

    void insertD(int val) {
        DNode* temp = new DNode;
        temp->item = val;
        DNode* current = dHead;
        while (current != nullptr && current->next->item < val) {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
        temp->prev = current;
        temp->next->prev = temp;
    }

    void deleteAtFirstD() {
        DNode* temp = dHead;
        dHead = dHead->next;
        dHead->prev = nullptr;
        delete temp;
    }

    void deleteAtLastD() {
        DNode* prev = dHead;
        DNode* last = dHead->next;
        while (last->next != nullptr) {
            prev = last;
            last = last->next;
        }
        delete last;
        prev->next = nullptr;
    }

    void deleteNodeD(int val) {
        DNode* temp = dHead->next;
        DNode* prev = dHead;
        while (temp->next != nullptr && temp->item != val) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        temp->next->prev = prev;
        delete temp;
    }
};
