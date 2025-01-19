#include <iostream>
#include "linkedList.cpp"
#include "Gym-Management.cpp"

using namespace std;

void sortUsersById(User* users[], int userCount) {
    for (int i = 0; i < userCount - 1; i++) {
        for (int j = 0; j < userCount - i - 1; j++) {
            if (users[j]->id > users[j + 1]->id) {
                
                User* temp = users[j];
                users[j] = users[j + 1];
                users[j + 1] = temp;
            }
        }
    }
}
