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


    NutritionSpecialist(string id, string fullName, int age, int experience, string achievements, string phoneNumber)
        : id(id), fullName(fullName), age(age), experience(experience), achievements(achievements), phoneNumber(phoneNumber) {}


    void createNutritionPlan() {
        //prototype
    }

    void communicateWithTrainer() {
        //prototype
    }


    void displayDetails() {
        cout << "Nutrition Specialist Details:" << endl;
        cout << "ID: " << id << endl;
        cout << "Full Name: " << fullName << endl;
        cout << "Age: " << age << endl;
        cout << "Experience: " << experience << " years" << endl;
        cout << "Achievements: " << achievements << endl;
        cout << "Phone Number: " << phoneNumber << endl;
    }
};


int main() {

    NutritionSpecialist specialist(
        "NS101", "Dr. Faris Hijazi", 35, 10, "Awarded Best Nutritionist 2023", "123-456-7890");



    specialist.displayDetails();


    specialist.createNutritionPlan();
    specialist.communicateWithTrainer();

    return 0;
}
