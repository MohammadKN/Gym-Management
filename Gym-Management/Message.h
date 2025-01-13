#pragma once
#include <iostream>
#include <string>
using namespace std;

class Message {
private:
    string date;
    string text;
    int trainerID;
    int clientID;

public:
    Message(string date, string text, int trainerID, int clientID);
    void displayMessage();
    int getTrainerID();
    int getClientID();
};