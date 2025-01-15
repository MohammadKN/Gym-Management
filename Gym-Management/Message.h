#pragma once
#include <iostream>
#include <string>
using namespace std;

class Message {
private:
    string date;
    string text;
    int from;
    int to;

public:
    Message(string date, string text, int from, int to);
    void displayMessage();
    int send();
    int checkMessages();
};