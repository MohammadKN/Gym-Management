#include <iostream>
#include <string>
using namespace std;

struct NutritionSpecialist {
    string id;
    string fullName;
    int age;
    int experience;
    string achievements;
    string phoneNumber;
    string clientName;
    string dietPlan;
};

NutritionSpecialist createNutritionSpecialist(string id, string fullName, int age, int experience, string achievements, string phoneNumber) {
    NutritionSpecialist ns;
    ns.id = id;
    ns.fullName = fullName;
    ns.age = age;
    ns.experience = experience;
    ns.achievements = achievements;
    ns.phoneNumber = phoneNumber;
    return ns;
}

void createNutritionPlan(NutritionSpecialist& ns, string clientName, string goal, string dietaryRestrictions) {
    ns.clientName = clientName;

    cout << "\nCreating a Nutrition Plan for " << clientName << "...\n";
    cout << "Goal: " << goal << endl;
    cout << "Dietary Restrictions: " << dietaryRestrictions << endl;
    cout << "The plan will include a diet focusing on achieving the goal while respecting the dietary restrictions." << endl;

    ns.dietPlan = "Goal: " + goal + "\nDietary Restrictions: " + dietaryRestrictions;
}

void displayClientPlan(const NutritionSpecialist& ns) {
    cout << "\nClient Plan for: " << ns.clientName << endl;
    cout << ns.dietPlan << endl;
}

void displayNutritionSpecialistDetails(const NutritionSpecialist& ns) {
    cout << "Nutrition Specialist Details:" << endl;
    cout << "ID: " << ns.id << endl;
    cout << "Full Name: " << ns.fullName << endl;
    cout << "Age: " << ns.age << endl;
    cout << "Experience: " << ns.experience << " years" << endl;
    cout << "Achievements: " << ns.achievements << endl;
    cout << "Phone Number: " << ns.phoneNumber << endl;
}

void inputGoal(NutritionSpecialist& ns) {
    string clientName, goal, dietaryRestrictions;

    cout << "Enter client's name: ";
    cin >> clientName;

    cout << "Enter goal (e.g., Weight loss, Muscle gain, etc.): ";
    cin >> goal;

    cout << "Enter any dietary restrictions (if any): ";
    cin >> dietaryRestrictions;

    createNutritionPlan(ns, clientName, goal, dietaryRestrictions);
}
