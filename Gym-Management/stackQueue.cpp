#include <iostream>
#include "linkedlist.cpp"

using namespace std;

struct Machine {
    string name;
    int id;
};

struct CartItem {
    double price;
    string item;
    char size;
};

struct QNode {
    Machine item;
    QNode* next;
};
struct SNode {
    CartItem item;
    SNode* next;
};
struct Stack {
    SNode* top;
    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(CartItem val) {
        SNode* temp = new SNode;
        temp->item = val;
        temp->next = top;
        top = temp;
    }

    CartItem pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return CartItem();
        }
        CartItem item = top->item;
        displayTop();
        SNode* temp = top;
        top = top->next;
        delete temp;
        return item;
    }
    void displayTop() {
        cout << "Popped: " << top->item.item << "\t\t" << top->item.size << "\t$" << top->item.price << endl;
    }

    float display() {
        SNode* current = top;
        float total = 0;
        while (current != NULL) {
            cout << current->item.item << "\t\t" << current->item.size << "\t$" << current->item.price << endl;
            total += current->item.price;
            current = current->next;
        }
        return total;
    }
};

struct Queue {
    QNode* front;
    QNode* rear;

    Queue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(Machine val) {
        QNode* temp = new QNode;
        temp->item = val;
        temp->next = NULL;

        if (rear == NULL) {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        QNode* temp = front;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    void display() {
        QNode* current = front;
        while (current != NULL) {
            cout << "ID: " << current->item.id
                << ", name: " << current->item.name
                << " -> ";
            current = current->next;
        }
        cout << "null" << endl;
    }
};

