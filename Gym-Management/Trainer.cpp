#include "Trainer.h"


Trainer::Trainer() : ID(0), Age(0), experience(0) {}


Trainer::Trainer(int id, const string& name, int age, int exp, const string& ach, const string& phone, const Schedule& schedule)
    : ID(id), fullName(name), Age(age), experience(exp), achievements(ach), phoneNumber(phone), trainerSchedule(schedule) {
}


void Trainer::setTrainerDetails(int id, const string& name, int age, int exp, const string& ach, const string& phone) {
    ID = id;
    fullName = name;
    Age = age;
    experience = exp;
    achievements = ach;
    phoneNumber = phone;
}


void Trainer::setTrainerSchedule(const Schedule& schedule) {
    trainerSchedule = schedule;
}


Schedule Trainer::getTrainerSchedule() const {
    return trainerSchedule;
}


void Trainer::displayTrainerDetails() const {
    cout << "Trainer ID: " << ID << endl;
    cout << "Name: " << fullName << endl;
    cout << "Age: " << Age << endl;
    cout << "Experience: " << experience << " years" << endl;
    cout << "Achievements: " << achievements << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Schedule: " << endl;
    trainerSchedule.displaySchedule(); 
}


int Trainer::getTrainerID() const {
    return ID;
}
