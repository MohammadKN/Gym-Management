#pragma once
#include <iostream>
using namespace std;

class Schedule {
private:
    int trainerID;
    int clientID;
    int days;
    string training_type;
    string exercises;
    int duration;
    int rest_days;

public:
    Schedule(int trainerID, int clientID, int days, string training_type, string exercises, int duration, int rest_days);
    void displaySchedule();
    int getTrainerID();
    int getClientID();
};