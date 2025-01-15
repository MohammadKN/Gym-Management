#include "Message.h"
#include <iostream>
using namespace std;

Message::Message(string date, string text, int trainerID, int clientID)
{
    this->date = date;
    this->text = text;
    this->to = to;
    this->from = from;

}

void Message::displayMessage()
{
    cout << "Date: " << date << endl;
    cout << "Message: " << text << endl;
    cout << "to: " << to << endl;
    cout << "from: " << from << endl;
}

int Message::send() 
{
    return to;
}

int Message::checkMessages()
{
    return from;
}
