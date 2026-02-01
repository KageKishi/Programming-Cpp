#include <iostream>
#include <string>
using namespace std;
int getValidatedInteger(const std::string &prompt);
int main()
{
    struct StudentData
    {
        string name;
        int date;
        string month;
        int year;
    };
    string count[2] ={"first","second"};
    StudentData Student[2];
    for (int i = 0; i < 2; i++)
    {
        cout << "Enter the " << count[i] << " student birthday details: \n";
        cout << "Enter nickname: ";
        getline(cin >> ws, Student[i].name);
        do
        {
            Student[i].date = getValidatedInteger("Enter day :");
        } while (Student[i].date > 30);
        cout << "Enter month: ";
        getline(cin >> ws, Student[i].month);
        do
        {
            Student[i].year = getValidatedInteger("Enter year: ");
        } while (Student[i].year > 2026 || Student[i].year < 1900);
        cout << endl;
    }
    cout << "Data Entered: \n";
    for (int i = 0; i < 2; i++)
    {
        cout << Student[i].name << " - " << Student[i].date << "/" << Student[i].month << "/" << Student[i].year << endl;
    }
    return 0;
}
int getValidatedInteger(const std::string &prompt)
{
    std::string temp;
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, temp);
        try
        {
            for (char c : temp)
            {
                if (!isdigit(c))
                {
                    throw std::invalid_argument("Invalid character");
                }
            }
            int value = std::stoi(temp);
            if (value > 0)
            {
                return value;
            }
        }
        catch (...)
        {
            std::cout << "Error: Please enter a valid integer.\n";
        }
    }
}
