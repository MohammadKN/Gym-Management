#include "Client.h"


void Client::accessDiet()
{
    NutritionSpecialist NS("NS1", "John Doe", 30, 5, "Best Nutritionist Award","");
	cout << "Accessing schedule created by Nutrition Specialist: " ; 
	NS.displayClientPlan() ;

}
void Client::accessSchedule(Schedule schedule)
{
    cout << "Accessing schedule created by Trainer ID: " << schedule.getTrainerID() << endl;
    schedule.displaySchedule();
}
void Client::marketplace()
    {
        cout << "Welcome to the Market!\n";

        // 2D Array: Rows = Meals, Columns = Different Sizes
        market menu[3][3] = {
            { {4.99, "Chicken", 'S'}, {6.99, "Chicken", 'M'}, {8.99, "Chicken", 'L'} },
            { {3.99, "Fish", 'S'}, {5.99, "Fish", 'M'}, {7.99, "Fish", 'L'} },
            { {2.49, "Milkshake", 'S'}, {3.49, "Milkshake", 'M'}, {4.49, "Milkshake", 'L'} }
        };

        // Displaying the menu
        cout << "\nMenu:\n";
        for (int i = 0; i < 3; i++) {
            cout << menu[i][0].item << " Options:\n"; // Print the meal name once
            for (int j = 0; j < 3; j++) {
                cout << "  Size: " << menu[i][j].size
                    << " - Price: $" << menu[i][j].price << endl;
            }
            cout << endl;
        }
    } 
void Client::buy() {
    string name;
    char size;
    float price = 0;
    char choice;

    do {
        if (cartSize >= 10) {
            cout << "Cart is full! You can't add more items.\n";
            break;
        }

        cout << "Enter the name of the meal you want to buy: ";
        cin >> name;
        cout << "Enter the size (S/M/L): ";
        cin >> size;

        // Convert input to lowercase for case insensitivity
        for (char& c : name) c = tolower(c);
        size = toupper(size);

        // Find the price
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

        // Add item to cart
        cart[cartSize] = { price, name, size };
        cartSize++; // Increase cart size

        cout << "Added " << name << " (Size: " << size << ") to your cart for $" << price << endl;
        cout << "Would you like to buy another item? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    printBill(); // Call billing function after shopping
}
void Client::printBill() {
    if (cartSize == 0) {
        cout << "Your cart is empty. No items to bill.\n";
        return;
    }

    float total = 0;
    float taxRate = 0.16;  // Tax rate (16%)
    float taxAmount = 0;

    cout << "\n********** BILL **********\n";
    cout << "Item\t\tSize\tPrice\n";
    cout << "-----------------------------\n";

    for (int i = 0; i < cartSize; i++) {
        cout << cart[i].item << "\t\t" << cart[i].size << "\t$" << cart[i].price << endl;
        total += cart[i].price;
    }

    // Calculate tax
    taxAmount = total * taxRate;
    total += taxAmount;  // Add tax to total amount

    cout << "-----------------------------\n";
    cout << "Subtotal: \t\t$" << total - taxAmount << endl;  // Subtotal without tax
    cout << "Tax (16%): \t\t$" << taxAmount << endl;
    cout << "Total Amount: \t\t$" << total << endl;
    cout << "*****************************\n";
}