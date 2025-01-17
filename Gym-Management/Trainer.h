#pragma once
#include<iostream>
#include <string>
#include "Schedule.h"
using namespace std;
class Trainer {
private:
    int ID;
    string fullName;
    int Age;
    int experience;
    string achievements;
    string phoneNumber;
    Schedule trainerSchedule; 

public:
    Trainer();
    Trainer(int id, const string& name, int age, int exp, const string& ach, const string& phone, const Schedule& schedule);

    void setTrainerDetails(int id, const string& name, int age, int exp, const string& ach, const string& phone);
    void setTrainerSchedule(const Schedule& schedule);
    Schedule getTrainerSchedule() const;

    void displayTrainerDetails() const;
    int getTrainerID();
};
