#include <iostream>
#include "Schedule.h"
#include "Trainer.h"
#include"NutritionSpecialist.h" 

using namespace std;


struct market {
    float price;
    string item;
    char size;
};

class Client {
public:
    int id;
    string username;
    int TrainerId;
    int age;
    string phoneNumber;
    market cart[10]; 
    int cartSize; 


	
    Client(int id, string username, int age, string phoneNumber , int c) {
        this->id = id;
        this->username = username;
        this->age = age;
        this->phoneNumber = phoneNumber;
        this->TrainerId = TrainerId; 

        cartSize = 0; 
    }
	Client() {
		id = 0;
		username = "";
		age = 0;
		phoneNumber = "";
		TrainerId = 0;
		cartSize = 0;
	}
    
    void marketplace();

    
    void buy();
    void printBill();
    void accessDiet();
    void accessSchedule(Schedule schedule);
};
