#include <iostream>
#include <string>
#include "stackQueue.cpp"
using namespace std;

enum Day {
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};



struct Schedule {
    int trainerID;
    int clientID;
    string trainingType;
    string exercises[5];
    int duration;
    Day restDays[7];
    Day workingDays[7];
};


struct MarketItem {
    double price;
    string item;
    char size;
};



void printBill(Stack& stk);
void buy(Stack& stk);
void marketplace(Stack& stk) {
    cout << "Welcome to the Market!\n";

    MarketItem menu[3][3] = {
        {{4.99, "Chicken", 'S'}, {6.99, "Chicken", 'M'}, {8.99, "Chicken", 'L'}},
        {{3.99, "Fish", 'S'}, {5.99, "Fish", 'M'}, {7.99, "Fish", 'L'}},
        {{2.49, "Milkshake", 'S'}, {3.49, "Milkshake", 'M'}, {4.49, "Milkshake", 'L'}}
    };

    cout << "\nMenu:\n";
    for (int i = 0; i < 3; i++) {
        cout << menu[i][0].item << " Options:\n";
        for (int j = 0; j < 3; j++) {
            cout << "  Size: " << menu[i][j].size
                << " - Price: $" << menu[i][j].price << endl;
        }
        cout << endl;
    }
    buy(stk);
}

void buy(Stack& stk) {
    string name;
    char size;
    float price = 0;
    char choice = '.';

    do {

        cout << "Enter the name of the meal you want to buy: ";
        cin >> name;
        cout << "Enter the size (S/M/L): ";
        cin >> size;

        for (char& c : name) c = tolower(c);
        size = toupper(size);

        if (name == "chicken") {
            if (size == 'L') price = 8.99;
            else if (size == 'M') price = 6.99;
            else price = 4.99;
        }
        else if (name == "fish") {
            if (size == 'L') price = 7.99;
            else if (size == 'M') price = 5.99;
            else price = 3.99;
        }
        else if (name == "milkshake") {
            if (size == 'L') price = 4.49;
            else if (size == 'M') price = 3.49;
            else price = 2.49;
        }
        else {
            cout << "Invalid item name! Please try again.\n";
            continue;
        }
        CartItem item = { price,name,size };
        stk.push(item);
        

        cout << "Added " << name << " (Size: " << size << ") to your cart for $" << price << endl;
        cout << "Would you like to buy another item? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

}

void printBill(Stack& stk) {
    if (stk.isEmpty()) {
        cout << "Your cart is empty. No items to bill.\n";
        return;
    }

    float total = 0;
    float taxRate = 0.16;
    float taxAmount = 0;

    cout << "\n********** BILL **********\n";
    cout << "Item\t\tSize\tPrice\n";
    cout << "-----------------------------\n";

    total = stk.display();

    taxAmount = total * taxRate;
    total += taxAmount;

    cout << "-----------------------------\n";
    cout << "Subtotal: \t\t$" << total - taxAmount << endl;
    cout << "Tax (16%): \t\t$" << taxAmount << endl;
    cout << "Total Amount: \t\t$" << total << endl;
    cout << "*****************************\n";
}
