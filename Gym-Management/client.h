#include <iostream>
#include "Schedule.h"
#include"Message.h"
using namespace std;

// Struct for the market items
struct market {
    float price;
    string item;
    char size;
};

// Client class
class client {
private:
    int id;
    string fullname;
    int TrainerId;
    int age;
    string phoneNumber;  // Changed phoneNumber to string
    market cart[10]; // Fixed-size array for storing purchased items
    int cartSize; // Counter for items in the cart

public:
    // Constructor
    client(int id, string fullname, int age, string phoneNumber , int TrainerId) {
        this->id = id;
        this->fullname = fullname;
        this->age = age;
        this->phoneNumber = phoneNumber;
        this->TrainerId = TrainerId; 

        cartSize = 0; // Initialize cart size to 0
    }

    // Marketplace method to display menu
    void marketplace();

    // Buy method to allow users to purchase multiple items
    void buy();
    // Function to print the final bill with tax
    void printBill();
    // Placeholder for other functions
    void authenticate() { cout << "Authentication feature coming soon!\n"; }
    void accessDietSupplement() { cout << "Diet Supplement feature coming soon!\n"; }
    void accessSchedules() { cout << "Schedules feature coming soon!\n"; }
    void communicate() { cout << "Communication feature coming soon!\n"; }
    void accessSchedule(Schedule schedule);
    void receiveMessage(Message message);
};
