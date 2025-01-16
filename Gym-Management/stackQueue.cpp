class Queue {
private:
    linkedList list;
public:
    Queue(int headVal) : list(headVal) {}

    void enqueue(int val) {
        list.insertAtLast(val);
    }

    bool isEmpty() {
        return list.isEmpty();
    }

    void dequeue() {
        if (!list.isEmpty()) {
            list.deleteAtFirst();
        }
        else {
            cout << "Queue is empty." << endl;
        }
    }

    void display() {
        list.display();
    }
};

class Stack {
private:
    linkedList list;
public:
    Stack(int headVal) : list(headVal) {}

    void push(int val) {
        list.insertAtFirst(val);
    }

    bool isEmpty() {
        return list.isEmpty();
    }

    void pop() {
        if (!list.isEmpty()) {
            list.deleteAtFirst();
        }
        else {
            cout << "Stack is empty." << endl;
        }
    }

    void display() {
        list.display();
    }
};
