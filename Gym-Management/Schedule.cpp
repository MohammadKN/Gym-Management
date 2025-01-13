#include "Schedule.h"
#include <iostream>
using namespace std;

Schedule::Schedule(int trainerID, int clientID, int days, string trainingType, string exercises, int duration, int restDays)
{
    this->trainerID = trainerID;
    this->clientID = clientID;
    this->days = days;
    this->training_type = trainingType;
    this->exercises = exercises;
    this->duration = duration;
    this->rest_days = rest_days;
}

void Schedule::displaySchedule() 
{
    cout << "Trainer ID: " << trainerID << endl;
    cout << "Client ID: " << clientID << endl;
    cout << "Days: " << days << endl;
    cout << "Training Type: " << training_type << endl;
    cout << "Exercises: " << exercises << endl;
    cout << "Duration: " << duration << " minutes" << endl;
    cout << "Rest Days: " << rest_days << endl;
}

int Schedule::getTrainerID()
{
    return trainerID;
}

int Schedule::getClientID()
{
    return clientID;
}