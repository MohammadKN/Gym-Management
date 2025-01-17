#pragma once
#include <iostream>
#include <string>

using namespace std;

class NutritionSpecialist {
public:

    string id;
    string fullName;
    int age;
    int experience;
    string achievements;
    string phoneNumber;
    string clientName;
    string dietPlan;


    NutritionSpecialist(string id, string fullName, int age, int experience, string achievements, string phoneNumber);


    void createNutritionPlan(string clientName, string goal, string dietaryRestrictions);

    void displayClientPlan();

    void displayDetails();

    void Goal();


};