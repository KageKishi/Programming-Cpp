/*1. Your program will request for the user’s name and ID, which will be used in various parts of the
program. */
#include <iostream>
using namespace std;
string getname(const string &prompt);
string getValidatedInteger(const string &prompt);
int main()
{
    string name;
    string ID;
    name = getname("Enter your name: ");
    while (true)
    {
        ID = getValidatedInteger("Enter your ID: ");
        if (ID.empty())
        {
            cout << "ERROR: Your ID value cannot be blank/empty!\n";
            continue;
        }
        else if (ID.length() < 9 || ID.length() > 9)
        {
            cout << "ERROR: Your ID value must be 9-digit long!\n";
            continue;
        }else if(ID.substr(0,4) != "7000"){
            cout << "ERROR: Your ID value must be in 7000XXXXX format!\n";
            continue;
        }
        else
        {
            break;
        }
    }
    cout << "Welcome to our Grouping Registration App, " << name << " (ID: " << ID << ")!\n";
    cout << "Loading Main Page. . .\n";
    return 0;
}
string getname(const string &prompt)
{
    string temp;
    while (true)
    {
        cout << prompt;
        getline(cin , temp);
        if (temp.empty())
        {
            cout << "ERROR: Your name value cannot be blank/empty!\n";
            continue;
        }
        else
        {
            return temp;
        }
    }
}
string getValidatedInteger(const std::string &prompt)
{
    std::string temp;
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin , temp);
        try
        {
            for (char c : temp)
            {
                if (!isdigit(c))
                {
                    throw std::invalid_argument("Invalid character");
                }
            }
            return temp;
        }
        catch (...)
        {
            std::cout << "ERROR: Your ID value must be numeric value only\n";
        }
    }
}
