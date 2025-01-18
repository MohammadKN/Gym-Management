#include "NutritionSpecialist.h"
#include <iostream>

using namespace std;

NutritionSpecialist::NutritionSpecialist(string id, string fullName, int age, int experience, string achievements, string phoneNumber) {
	this->id = id;
	this->fullName = fullName;
	this->age = age;
	this->experience = experience;
	this->achievements = achievements;
	this->phoneNumber = phoneNumber;
}

void NutritionSpecialist::createNutritionPlan(string clientName, string goal, string dietaryRestrictions) {
	this->clientName = clientName;

	system("cls");
	cout << "\nCreating a Nutrition Plan for " << clientName << "...\n";
	cout << "Goal: " << goal << endl;
	cout << "Dietary Restrictions: " << dietaryRestrictions << endl;
	cout << "The plan will include a diet focusing on achieving the goal while respecting the dietary restrictions." << endl;
	dietPlan = "Goal: " + goal + "\nDietary Restrictions: " + dietaryRestrictions;

}
void NutritionSpecialist::displayClientPlan() {
	system("cls");
	cout << "\nClient Plan for: " << clientName << endl;
	cout << dietPlan << endl;
}
void NutritionSpecialist::displayDetails() {
	system("cls");
	cout << "Nutrition Specialist Details:" << endl;
	cout << "ID: " << id << endl;
	cout << "Full Name: " << fullName << endl;
	cout << "Age: " << age << endl;
	cout << "Experience: " << experience << " years" << endl;
	cout << "Achievements: " << achievements << endl;
	cout << "Phone Number: " << phoneNumber << endl;
}

void NutritionSpecialist::Goal() {
	string clientName, goal, dietaryRestrictions;

	cout << "Enter client's name: ";
	cin >> clientName;

	cout << "Enter goal (e.g., Weight loss, Muscle gain, etc.): ";
	cin >> goal;

	cout << "Enter any dietary restrictions (if any): ";
	cin >> dietaryRestrictions;
}; 