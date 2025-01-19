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

Schedule Schedule::createSchedule() {
    int trainerID, clientID, numWorkingDays, numRestDays, numExercises, duration;
    Day workingDays[7], restDays[7];
    string exercises[5];

    cout << "Enter Trainer ID: ";
    cin >> trainerID;
    cout << "Enter Client ID: ";
    cin >> clientID;

    cout << "Enter number of working days: ";
    cin >> numWorkingDays;
    cout << "Enter working days (0 for Sunday, 1 for Monday, ..., 6 for Saturday): ";
    for (int i = 0; i < numWorkingDays; ++i) {
        int day;
        cin >> day;
        workingDays[i] = static_cast<Day>(day);
    }

    cout << "Enter number of rest days: ";
    cin >> numRestDays;
    cout << "Enter rest days (0 for Sunday, 1 for Monday, ..., 6 for Saturday): ";
    for (int i = 0; i < numRestDays; ++i) {
        int day;
        cin >> day;
        restDays[i] = static_cast<Day>(day);
    }

    cout << "Enter number of exercises: ";
    cin >> numExercises;
    cout << "Enter exercises: ";
    for (int i = 0; i < numExercises; ++i) {
        cin >> exercises[i];
    }

    cout << "Enter duration (in minutes): ";
    cin >> duration;

    return Schedule(trainerID, clientID, workingDays, numWorkingDays, exercises, numExercises, duration, restDays, numRestDays);
}

int Schedule::getTrainerID() {
    return trainerID;
}

int Schedule::getClientID() {
    return clientID;
}
