#include "Schedule.h"
#include <iostream>

using namespace std;

Schedule::Schedule(int trainerID, int clientID, Day workingDays[], int numWorkingDays,
    string exercises[], int numExercises, int duration,
    Day restDays[], int numRestDays)
    : trainerID(trainerID), clientID(clientID), duration(duration) {
    for (int i = 0; i < numWorkingDays; ++i) {
        this->workingDays[i] = workingDays[i];
    }

    for (int i = 0; i < numRestDays; ++i) {
        this->restDays[i] = restDays[i];
    }

    for (int i = 0; i < numExercises; ++i) {
        this->exercises[i] = exercises[i];
    }
};


void Schedule::displaySchedule() const {
    cout << "Trainer ID: " << trainerID << endl;
    cout << "Client ID: " << clientID << endl;

    cout << "Working Days: ";
    for (const auto& day : workingDays) {
        cout << day << " ";
    }
    cout << endl;

    cout << "Exercises: ";
    for (const auto& exercise : exercises) {
        if (!exercise.empty())
            cout << exercise << " ";
    }
    cout << endl;

    cout << "Duration: " << duration << " minutes" << endl;

    cout << "Rest Days: ";
    for (const auto& day : restDays) {
        cout << day << " ";
    }
    cout << endl;

    cout << "Enter anything to get back: ";
    string x;
    cin >> x;
}

int Schedule::getTrainerID() {
    return trainerID;
}

int Schedule::getClientID() {
    return clientID;
}

