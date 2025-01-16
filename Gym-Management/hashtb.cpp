// hash.cpp
#include <iostream>
#include "hashr.h"
using namespace std;

void initializeTable(int table[]) {
    for (int i = 0; i < MAX; i++) {
        table[i] = EMPTY;
    }
}

void hashings(int table[], int id) {
    int hashv = id % MAX;
    while (table[hashv] != EMPTY) {
        hashv = (hashv + 1) % MAX;
    }
    table[hashv] = id;
}

void displays(int table[]) {
    cout << "Index | Value\n";
    cout << "----------------\n";
    for (int i = 0; i < MAX; i++) {
        if (table[i] == EMPTY)
            cout << "  " << i << "   |  EMPTY\n";
        else
            cout << "  " << i << "   |   " << table[i] << "\n";
    }
}
