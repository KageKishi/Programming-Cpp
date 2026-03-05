/* 4. Multi deletion
Write a program to allow user to infinitely input student into a table and delete many at once.
You can suggest Attributes (id, name, age, etc.)*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include "json.hpp"
#include <string>
#include <iomanip>
using namespace std;
using json = nlohmann::json;
int getValidatedInteger(const std::string &prompt);
class Menu
{
private:
    json arr;
    json current;
    int choice;
    int ID, SearchedID;
    string Name;
    int Age;
    char yn;

public:
    Menu()
    {
        choice = 0;
        arr = json::array();
        ifstream READ("Student.json");
        if (READ && READ.peek() != EOF)
        {
            try
            {
                READ >> arr;
            }
            catch (...)
            {
                arr = json::array();
            }
        }
        if (READ.is_open())
            READ.close();
    }
    int MenuScreen()
    {
        cout << "====Menu===";
        cout << "\n1. Add new students";
        cout << "\n2. Delete multiple students";
        cout << "\n3. Quit\n";
        do
        {
            choice = getValidatedInteger("Choose an option: ");
        } while (choice < 0 || choice > 3);
        return choice;
    }
    void AddStudent()
    {
        while (true)
        {
            cout << "\n\nStudent #" << arr.size() + 1 << ": ";
            cout << endl;
            ID = getValidatedInteger("Id: ");
            cout << "Name: ";
            getline(cin, Name);
            Age = getValidatedInteger("Age: ");
            ofstream Students("Student.json");
            current["ID"] = ID;
            current["Name"] = Name;
            current["Age"] = Age;
            arr.push_back(current);
            Students << arr.dump(5);
            Students.close();
            do
            {
                cout << "Do you want to add more (y/n)?: ";
                cin >> yn;
                yn = tolower(yn);
                cin.ignore(1, '\n');
                if (yn == 'y')
                {
                    continue;
                }
                else if (yn == 'n')
                {
                    break;
                }
            } while (yn != 'y' && yn != 'n');
            if (yn == 'n')
            {
                break;
            }
        }
    }
    void DeleteStudent()
    {
        viewAllStudent();
        cout << endl;
        cout << "===DELETION===\n";
        size_t oldsize = arr.size();
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
                ofstream Students("Student.json");
                Students << arr.dump(5);
                Students.close();
                cout << "Student with ID " << SearchedID << " was deleted\n";
            }
            do
            {
                cout << "Do you want to delete more (y/n)?: ";
                cin >> yn;
                yn = tolower(yn);
                cin.ignore(1, '\n');
                if (yn == 'y')
                {
                    continue;
                }
                else if (yn == 'n')
                {
                    break;
                }
            } while (yn != 'y' && yn != 'n');
            if (yn == 'n')
            {
                break;
            }
        }
    }
    void viewAllStudent()
    {
        cout << left;
        cout << string(38, '=') << endl;
        cout << "|" << setw(3) << "No" << " | " << setw(10) << "ID" << " | " << setw(10) << "Name" << " | " << setw(3) << "Age" << " |\n";
        int number = 1;
        cout << string(38, '=') << endl;
        for (const auto &Student : arr)
        {
            cout << "|" << setw(3) << number
                 << " | " << setw(10) << Student["ID"].get<int>()
                 << " | " << setw(10) << Student["Name"].get<std::string>()
                 << " | " << setw(3) << Student["Age"].get<int>()
                 << " |\n";
            cout << string(38, '=') << endl;
            number++;
        }
        cout << right;
    }
};
int main()
{
    Menu StudentList;
    int choice;
    while (choice != 3)
    {
        choice = StudentList.MenuScreen();
        switch (choice)
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
