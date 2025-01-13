#include "Message.h"
#include <iostream>
using namespace std;

Message::Message(string date, string text, int trainerID, int clientID)
{
    this->date = date;
    this->text = text;
    this->trainerID = trainerID;
    this->clientID = clientID;
}

void Message::displayMessage()
{
    cout << "Date: " << date << endl;
    cout << "Message: " << text << endl;
    cout << "Trainer ID: " << trainerID << endl;
    cout << "Client ID: " << clientID << endl;
}

int Message::getTrainerID() 
{
    return trainerID;
}

int Message::getClientID()
{
    return clientID;
}
