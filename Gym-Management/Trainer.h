#pragma once
#include <string>
#include "Message.h"
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

public:
    void setTrainerDetails(int id, string name, int age, int exp, string ach, string phone);
    void displayTrainerDetails();
    void createTrainingSchedule(Schedule schedule);
    void sendMessage(Message message);
};