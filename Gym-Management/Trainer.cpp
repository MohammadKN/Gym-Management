#include "Trainer.h"
#include<iostream>
using namespace std;

void Trainer::setTrainerDetails(int id, string name, int age, int exp, string ach, string phone)
{
    ID = id;
    fullName = name;
    Age = age;
    experience = exp;
    achievements = ach;
    phoneNumber = phone;
}

void Trainer::displayTrainerDetails()
{
    cout << "Trainer ID: " << ID << endl;
    cout << "Name: " << fullName << endl;
    cout << "Age: " << Age << endl;
    cout << "Experience: " << experience << " years" << endl;
    cout << "Achievements: " << achievements << endl;
    cout << "Phone Number: " << phoneNumber << endl;
}
void Trainer::createTrainingSchedule(Schedule schedule)
{
    cout << "Training schedule created for Client ID: " << schedule.getClientID() << endl;
    schedule.displaySchedule();
}

void Trainer::sendMessage(Message message) 
{
    cout << "Message sent to Client ID: " << message.getClientID() << endl;
    message.displayMessage();
}
