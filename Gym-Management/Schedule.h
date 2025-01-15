#pragma once
#include <iostream>
using namespace std;

class Schedule {
private:
    int trainerID;
    int clientID;
    int days;
    string trainingType;
    string exercises;
    int duration;
    int restDays;

public:
    Schedule(int trainerID, int clientID, int days, string trainingType, string exercises, int duration, int restDays);
    void displaySchedule();
    int getTrainerID();
    int getClientID();
};