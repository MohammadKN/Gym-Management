#include <iostream>
using namespace std;

#define MAX 10
#define EMPTY -1  // Mark empty slots

void initializeTable(int table[]) {
    for (int i = 0; i < MAX; i++) {
        table[i] = EMPTY;  // Initialize all slots as empty
    }
}

void hashing(int table[], int id) {
    int hashv = id % MAX;

    // Linear probing for collision resolution
    while (table[hashv] != EMPTY)
    {
        hashv = (hashv + 1) % MAX;
    }

    table[hashv] = id;  // Store ID in the available slot
}

void display(int table[]) {
    cout << "Index | Value\n";
    cout << "----------------\n";
    for (int i = 0; i < MAX; i++) {
        if (table[i] == EMPTY)
            cout << "  " << i << "   |  EMPTY\n";
        else
            cout << "  " << i << "   |   " << table[i] << "\n";
    }
}