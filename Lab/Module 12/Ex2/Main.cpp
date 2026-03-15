#include <iostream>
using namespace std;
class BirthDate
{
public:
    BirthDate()
    {
        // also useless
    }
    void Display(char name[], int day, char month[], int year)
    {
        cout << "Hello, " << name << endl;
        cout << "You were born on: " << day << "/" << month << "/" << year << endl;
    }
};
int main()
{
    char name[50], month[20];
    BirthDate Birth;
    int day, year;
    cout << "Please enter your birth details below:" << endl;
    cout << "Enter name: ";
    cin.getline(name, 50);
    cout << "Enter day of birth: ";
    cin >> day;
    cout << "Enter month of birth: ";
    cin >> month;
    cout << "Enter year of birth: ";
    cin >> year;
    cout << endl;
    Birth.Display(name, day, month, year);
    return 0;
}