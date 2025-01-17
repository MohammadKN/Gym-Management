#pragma once
#include <iostream>
#include <string>
using namespace std;

enum Day {
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

class Schedule {
private:
    int trainerID;
    int clientID;
    string trainingType;  
    string exercises[5];  
    int duration;         
    Day restDays[7];      
    Day workingDays[7];   

public:
    Schedule() {};
    Schedule(int trainerID, int clientID, Day workingDays[], int numWorkingDays, 
             string exercises[], int numExercises, int duration, 
             Day restDays[], int numRestDays);

    void displaySchedule() const;

    int getTrainerID();
    int getClientID();

};
