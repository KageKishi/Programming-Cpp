/* 4. Multi deletion
Write a program to allow user to infinitely input student into a table and delete many at once.
You can suggest Attributes (id, name, age, etc.)*/
#include <iostream>
#include <fstream>
#include "json.hpp"
#include <string>
using namespace std;
using json = nlohmann::json;
int getValidatedInteger(const std::string &prompt);
class Menu
{
private:
    json arr;
    json current;
    int choice;
    int studentamount = 1;
    int ID, SearchedID;
    string Name;
    int Age;
    char yn;

public:
    Menu()
    {
        json arr = arr.array();
        ifstream READ("Student.json");
        READ >> arr;
        READ.close();
        for (const int amount : arr["Number"])
        {
            studentamount++;
        }
    }
    int MenuScreen()
    {
        cout << "====Menu===";
        cout << "\n1. Add new students";
        cout << "\n2. Delete multiple students";
        cout << "\n3. Quit\n";
        while (choice < 0 || choice > 3)
            choice = getValidatedInteger("Choose an option: ");
        return choice;
    }
    void AddStudent()
    {
        cout << "\n\nStudent #" << studentamount << ": ";
        cout << endl;
        ID = getValidatedInteger("Id: ");
        cout << "Name: ";
        getline(cin, Name);
        Age = getValidatedInteger("Age: ");
        ofstream Students("Student.json");
        current["Number"] = studentamount;
        current["ID"] = ID;
        current["Name"] = Name;
        current["Age"] = Age;
        arr.push_back(current);
        Students << arr.dump(5);
        Students.close();
    }
    void DeleteStudent()
    {

        cout << "===DELETION===\n";
        int oldsize = arr.size();
        while (true)
        {
            SearchedID = getValidatedInteger("Input StudentID: ");
            arr.erase(
                std::remove_if(arr.begin(), arr.end(),
                               [this](const json &Student)
                               {
                                   return Student["ID"] == this->SearchedID;
                               }),
                arr.end());
            if (oldsize == arr.size())
            {
                cout << "Student with ID " << SearchedID << " not found\n";
            }
            else
            {
                cout << "Student with ID " << SearchedID << " was deleted\n";
            }
            cout << "Do you want to delete more (y/n)?: ";
            cin >> yn;
            yn = tolower(yn);
            cin.ignore(1, '\n');
            if (yn == 'y')
            {
                continue;
            }
            else
            {
                break;
            }
        }
    }
};
int main()
{
    Menu StudentList;
    switch (StudentList.MenuScreen())
    {
    case 1:
    {
        StudentList.AddStudent();
        break;
    }
    case 2:
    {
        StudentList.DeleteStudent();
        break;
    }
    case 3:
    {
        return 0;
        break;
    }
    default:
    {
        cout << "LEL";
        break;
    }
    }
    return 67;
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
