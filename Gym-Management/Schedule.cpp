#include "Schedule.h"
#include <iostream>
using namespace std;

Schedule::Schedule(int trainerID, int clientID, int days, string trainingType, string exercises, int duration, int restDays)
{
    this->trainerID = trainerID;
    this->clientID = clientID;
    this->days = days;
    this->trainingType = trainingType;
    this->exercises = exercises;
    this->duration = duration;
    this->restDays = restDays;
}

void Schedule::displaySchedule() 
{
    cout << "Trainer ID: " << trainerID << endl;
    cout << "Client ID: " << clientID << endl;
    cout << "Days: " << days << endl;
    cout << "Training Type: " << trainingType << endl;
    cout << "Exercises: " << exercises << endl;
    cout << "Duration: " << duration << " minutes" << endl;
    cout << "Rest Days: " << restDays << endl;
    cout << "Enter anything to get Back"<<endl;
    string x;
	cin >> x;

}

int Schedule::getTrainerID()
{
    return trainerID;
}

int Schedule::getClientID()
{
    return clientID;
}