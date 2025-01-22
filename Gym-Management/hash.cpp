#include <iostream>
#include <string>
#define MAX 100 

using namespace std;

int Hash(const string password) {
    int hashv = 0;
    for (char ch : password) {
        hashv += ch; 
    }
    return hashv % MAX;
}

void storePassword(string passtable[], const string password) {
    int hashv = Hash(password);

    while (passtable[hashv] != "") { 
        hashv = (hashv + 1) % MAX;
    }
    passtable[hashv] = password; 
}

void displayTable(string table[]) {
    cout << "Index | Password\n";
    cout << "-----------------\n";
    for (int i = 0; i < MAX; i++) {
        if (table[i] != "")
            cout << "  " << i << "   | " << table[i] << "\n";
    }
}

