#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <chrono>
#include <thread>
#include <string>
#include <stdexcept>
#include <cctype>
#include <conio.h>
#include "json.hpp"
#include "color.cpp"
#include "database.cpp"
#include "Utility.cpp"
#include "Class.cpp"
using namespace std;
int main()
{
    int choice;
    Register page;
    string name, names, ID;
    int semester, year;
    int ans;
    bool Registers;
    bool Login;
    while (true)
    {
        system("cls");
        Registers = false;
        Login = false;

        system("cls");
        setColor(COLOR_CYAN);
        cout << "+============================================================+\n";
        cout << "|";
        setColor(COLOR_YELLOW);
        cout << "STUDENT REGISTRATION SYSTEM" << setw(35);
        setColor(COLOR_CYAN);
        cout << "|\n";
        cout << "+============================================================+\n";
        cout << "|" << setw(62) << "|\n";
        cout << "|  ";
        setColor(COLOR_GREEN);
        cout << left << setw(58) << "1. Register";
        setColor(COLOR_CYAN);
        cout << "|\n";
        cout << "|  ";
        setColor(COLOR_GREEN);
        cout << left << setw(58) << "2. Login";
        setColor(COLOR_CYAN);
        cout << "|\n";
        cout << right;
        cout << "|" << setw(62) << "|\n";
        cout << "+============================================================+\n";
        resetColor();

        setColor(COLOR_YELLOW);
        ans = getValidatedInteger("Your Choice: ");
        resetColor();

        if (ans == 1)
        {
            Registers = true;
        }
        else if (ans == 2)
        {
            Login = true;
        }
        else
        {
            system("cls");
            setColor(COLOR_RED);
            cout << "\nX Invalid Choice!\n";
            resetColor();
            Sleep(1000);
            continue;
        }

        while (Login)
        {
            ID = getID();
            if (StudentExist(ID))
            {
                break;
            }
            else
            {
                setColor(COLOR_RED);
                cout << " ID has not been registered yet\n";
                resetColor();
                Sleep(1500);
                Login = false;
                break;
            }
        }

        while (Registers)
        {
            setColor(COLOR_YELLOW);
            name = getname("Enter your name: ");
            ID = getID();
            if (StudentExist(ID))
            {
                setColor(COLOR_RED);
                cout << " This ID is already registered\n";
                Sleep(1500);
                resetColor();
                system("pause");
                break;
            }
            system("cls");
            setColor(COLOR_GREEN);
            cout << "\n> Welcome, ";
            setColor(COLOR_CYAN);
            cout << name;
            setColor(COLOR_GREEN);
            cout << " (ID: ";
            setColor(COLOR_CYAN);
            cout << ID;
            setColor(COLOR_GREEN);
            cout << ")!\n";
            resetColor();

            setColor(COLOR_YELLOW);
            cout << "Loading";
            for (int i = 0; i < 3; i++)
            {
                cout << " . ";
                Sleep(500);
            }
            resetColor();

            system("cls");
            semester = getValidSemester();
            year = getValidYear();

            setColor(COLOR_GREEN);
            cout << "\n> Registering for Trimester ";
            setColor(COLOR_CYAN);
            cout << semester << "F-" << year;
            setColor(COLOR_GREEN);
            cout << "!\n";
            resetColor();
            break;
        }
        if (StudentExist(ID) && Login)
        {
            break;
        }
        if (!StudentExist(ID) && Login)
        {
            continue;
        }
        if (!StudentExist(ID) && Registers)
        {
            system("cls");
            setColor(COLOR_GREEN);
            cout << "\n> Registration successful for ";
            setColor(COLOR_CYAN);
            cout << name;
            setColor(COLOR_GREEN);
            cout << " (ID: ";
            setColor(COLOR_CYAN);
            cout << ID;
            setColor(COLOR_GREEN);
            cout << ") for Trimester ";
            setColor(COLOR_CYAN);
            cout << semester << "F-" << year;
            setColor(COLOR_GREEN);
            cout << "!\n";
            resetColor();
            Sleep(3000);
            break;
        }
        if (StudentExist(ID) && Registers)
        {
            continue;
        }
    }

    if (StudentExist(ID))
    {
        system("cls");
        setColor(COLOR_GREEN);
        cout << "> Welcome back! Loading your data";
        for (int i = 0; i < 3; i++)
        {
            setColor(COLOR_YELLOW);
            cout << " . ";
            Sleep(500);
        }
        resetColor();

        system("cls");
        if (LoadExistingStudent(ID, names, semester, year, page.classes))
        {
            name = names;
            setColor(COLOR_CYAN);
            cout << "+============================================================+\n";
            cout << "|";
            setColor(COLOR_YELLOW);
            cout << left;
            cout << setw(60) << "YOUR INFORMATION" << setw(0);
            cout << right;
            setColor(COLOR_CYAN);
            cout << "|\n";
            cout << "+============================================================+\n";
            cout << "|" << setw(62) << "|\n";
            cout << "|  ";
            setColor(COLOR_WHITE);
            cout << "Name: ";
            setColor(COLOR_CYAN);
            cout << left << setw(52) << name;
            setColor(COLOR_CYAN);
            cout << "|\n";
            cout << "|  ";
            setColor(COLOR_WHITE);
            cout << "ID: ";
            setColor(COLOR_CYAN);
            cout << left << setw(54) << ID;
            setColor(COLOR_CYAN);
            cout << "|\n";
            cout << "|  ";
            setColor(COLOR_WHITE);
            cout << "Semester: ";
            setColor(COLOR_CYAN);
            cout << left << setw(48) << (to_string(semester) + "F-" + to_string(year));
            setColor(COLOR_CYAN);
            cout << "|\n";
            cout << right;
            cout << "|" << setw(62) << "|\n";
            cout << "+============================================================+\n";

            bool hasCourses = false;
            for (const auto &cls : page.classes)
            {
                if (cls.second != 0)
                {
                    setColor(COLOR_CYAN);
                    cout << "|  ";
                    setColor(COLOR_GREEN);
                    string info = "> " + cls.first + ": 1E" + to_string(cls.second);
                    cout << left << setw(58) << info;
                    setColor(COLOR_CYAN);
                    cout << "|\n";
                    hasCourses = true;
                }
            }
            if (!hasCourses)
            {
                setColor(COLOR_CYAN);
                cout << "|  ";
                setColor(COLOR_YELLOW);
                cout << left << setw(56) << "No courses registered yet.";
                setColor(COLOR_CYAN);
                cout << "|\n";
            }

            setColor(COLOR_CYAN);
            cout << right;
            cout << "|" << setw(62) << "|\n";
            cout << "+============================================================+\n";
            resetColor();

            setColor(COLOR_YELLOW);
            cout << "\nPress Enter to continue... ";
            resetColor();
            cin.ignore();
            cin.get();
            system("cls");
        }
    }

    LoadingMain();
    SaveToJSON(ID, name, semester, year, page.classes);
    while (true)
    {
        system("cls");
        setColor(COLOR_CYAN);
        cout << "+============================================================+\n";
        cout << "|";
        setColor(COLOR_YELLOW);
        cout << left;
        cout << setw(60) << "GROUP REGISTRATION MAIN MENU" << setw(0);
        setColor(COLOR_CYAN);
        cout << "|\n";
        cout << right;
        cout << "+============================================================+\n";
        cout << "|" << setw(62) << "|\n";
        cout << "|  ";
        setColor(COLOR_GREEN);
        cout << left << setw(58) << "1 - Register for grouping";
        setColor(COLOR_CYAN);
        cout << "|\n";
        cout << "|  ";
        setColor(COLOR_GREEN);
        cout << left << setw(58) << "2 - View/Print record";
        setColor(COLOR_CYAN);
        cout << "|\n";
        cout << "|  ";
        setColor(COLOR_GREEN);
        cout << left << setw(58) << "3 - View all students";
        setColor(COLOR_CYAN);
        cout << "|\n";
        cout << "|  ";
        setColor(COLOR_GREEN);
        cout << left << setw(58) << "4 - Delete student record";
        setColor(COLOR_CYAN);
        cout << "|\n";
        cout << "|  ";
        setColor(COLOR_RED);
        cout << left << setw(58) << "0 - Exit";
        setColor(COLOR_CYAN);
        cout << "|\n";
        cout << right;
        cout << "|" << setw(62) << "|\n";
        cout << "+============================================================+\n";
        resetColor();

        setColor(COLOR_YELLOW);
        choice = getValidatedInteger("\nChoice: ");
        resetColor();

        switch (choice)
        {
        case 1:
        {
            system("cls");
            while (choice != 0)
            {
                choice = page.GroupRegistrationModule();
                choice = page.CourseChoosing(choice);
            }
            break;
        }
        case 2:
            while (page.GroupRecordModule(name, semester, year, ID) != 0)
                ;
            break;
        case 3:
        {
            system("cls");
            ViewAllStudent();
            setColor(COLOR_YELLOW);
            cout << "\nPress Enter to continue...";
            resetColor();
            string trash;
            getline(cin, trash);
            system("cls");
            LoadingMain();
            break;
        }
        case 4:
        {
            string DeleteID;
            ViewAllStudent();
            while (DeleteID != "0")
            {
                setColor(COLOR_YELLOW);
                cout << "Enter the ID of the student to delete or 0 to exit\n";
                setColor(COLOR_CYAN);
                getline(cin, DeleteID);
                if (DeleteID == "0")
                {
                    system("cls");
                    LoadingMain();
                    break;
                }
                if (!StudentExist(DeleteID))
                {
                    setColor(COLOR_RED);
                    cout << "ID not found! Please enter a valid ID or 0 to exit.\n";
                    resetColor();
                }
                if (StudentExist(DeleteID) && DeleteID == ID)
                {
                    setColor(COLOR_RED);
                    cout << "You cannot delete your own record while logged in!\n";
                    resetColor();
                    Sleep(2000);
                }
                else if (StudentExist(DeleteID))
                {
                    system("cls");
                    DeleteStudent(DeleteID);
                    ViewAllStudent();
                }
            }
            system("cls");
            setColor(COLOR_YELLOW);
            LoadingMain();
            break;
        }
        case 0:
        {
            setColor(COLOR_YELLOW);
            cout << "\nAre you sure you want to exit the program, " << name << " ID(" << ID << ") Y/N?: \n";
            resetColor();
            char leave = ExitProgram(page.classes, name, ID, year, semester);
            if (leave == 'Y')
            {
                return 0;
            }
            break;
        }
        default:
            system("cls");
            setColor(COLOR_RED);
            cout << "X Invalid choice!\n";
            resetColor();
            Sleep(1000);
        }
    }
    return 0;
}