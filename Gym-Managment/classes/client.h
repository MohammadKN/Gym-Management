#include <iostream>
using namespace std;

class client
{
private:
    int id;
    string fullname;
    int age;
    int phoneNumber;
public:
    client(int id, string fullname, int age, int phoneNumber)
    {
        this->id = id;
        this->fullname = fullname;
        this->age = age;
        this->phoneNumber = phoneNumber;
    };
    void marketplace();
    void authenticate();
    void accessDietSupplement();
    void accessSchedules();
    void communicate();

};

