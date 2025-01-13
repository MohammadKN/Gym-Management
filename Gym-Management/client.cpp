#include "client.h"

void client::receiveMessage(Message message)
{
    cout << "Message received from Trainer ID: " << message.getTrainerID() << endl;
    message.displayMessage();
}

void client::accessSchedule(Schedule schedule)
{
    cout << "Accessing schedule created by Trainer ID: " << schedule.getTrainerID() << endl;
    schedule.displaySchedule();
}
