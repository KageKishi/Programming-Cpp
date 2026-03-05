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
#include "json.hpp"
// Forward declarations and lightweight color defines to avoid including .cpp files
void setColor(int color);
void resetColor();
#ifndef COLOR_LIGHT_GRAY
#define COLOR_LIGHT_GRAY 7
#define COLOR_DARK_GRAY 8
#define COLOR_GREEN 10
#define COLOR_CYAN 11
#define COLOR_RED 12
#define COLOR_MAGENTA 13
#define COLOR_YELLOW 14
#define COLOR_WHITE 15
#endif
using namespace std;
using json = nlohmann::json;
bool StudentExist(const string &ID);
void LoadJson(json &arr)
{
    ifstream READ("Register.json");
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
void SaveToJSON(const string &ID, const string &name, int semester, int year,
                const map<string, int> &classes)
{
    if(StudentExist(ID)) //To update existing student data instead of creating new entry
    {
        json arr;
        json current;
        arr = json::array();
        LoadJson(arr);
        for (auto &student : arr)
        {
            if (student["ID"] == ID)
            {
                student["name"] = name;
                student["semester"] = semester;
                student["year"] = year;
                student["Programming"] = classes.at("Programming");
                student["Physics 1"] = classes.at("Physics 1");
                student["Mathematics 2"] = classes.at("Mathematics 2");
                student["Writing and Research Skills"] = classes.at("Writing and Research Skills");
                break;
            }
        }
        ofstream Write("Register.json");
        Write << arr.dump(6);
        Write.close();
    }
    if (!StudentExist(ID)) //To add new student data 
    {
        json arr;
        json current;
        arr = json::array();
        LoadJson(arr);
        current["ID"] = ID;
        current["name"] = name;
        current["semester"] = semester;
        current["year"] = year;
        current["Programming"] = classes.at("Programming");
        current["Physics 1"] = classes.at("Physics 1");
        current["Mathematics 2"] = classes.at("Mathematics 2");
        current["Writing and Research Skills"] = classes.at("Writing and Research Skills");
        arr.push_back(current);
        ofstream Write("Register.json");
        Write << arr.dump(6);
        Write.close();
    }
}
void RecalculateGroupSlots(map<int, map<string, int>> &courseamt)
{
    json arr;
    json current;
    arr = json::array();
    LoadJson(arr);
    for (const auto &classes : arr)
    {
        if (classes["Programming"] != 0)
        {
            courseamt[classes["Programming"]]["Programming"]--;
        }
        if (classes["Physics 1"] != 0)
        {
            courseamt[classes["Physics 1"]]["Physics 1"]--;
        }
        if (classes["Mathematics 2"] != 0)
        {
            courseamt[classes["Mathematics 2"]]["Mathematics 2"]--;
        }
        if (classes["Writing and Research Skills"] != 0)
        {
            courseamt[classes["Writing and Research Skills"]]["Writing and Research Skills"]--;
        }
    }
}
bool StudentExist(const string &ID)
{
    json arr;
    json current;
    arr = json::array();
    LoadJson(arr);
    for (const auto &classes : arr)
    {
        if (classes["ID"] == ID)
        {
            return true;
        }
    }
    return false;
}
bool LoadExistingStudent(const string &searchID, string &names, int &semester, int &year,
                         map<string, int> &classes)
{
    json arr;
    json current;
    arr = json::array();
    LoadJson(arr);
    for (const auto &student : arr)
    {
        if (student["ID"] == searchID)
        {
            names = student.value("name", "");
            semester = student.value("semester", 0);
            year = student.value("year", 0);
            classes["Programming"] = student.value("Programming", 0);
            classes["Physics 1"] = student.value("Physics 1", 0);
            classes["Mathematics 2"] = student.value("Mathematics 2", 0);
            classes["Writing and Research Skills"] = student.value("Writing and Research Skills", 0);
            break;
        }
    }
    for (const auto &student : arr)
    {
        if (student["ID"] == searchID)
            return true;
    }
    return false;
}
void ViewAllStudent()
{
    string id, name, sem, yr, prog, phys, math, writ;
    json arr;
    json current;
    arr = json::array();
    LoadJson(arr);
    ifstream file("Register.json");
    if (file.is_open())
    {
        setColor(COLOR_CYAN);
        cout << "+======================================================================+\n";
        cout << "|";
        setColor(COLOR_YELLOW);
        cout << left;
        cout << setw(70) << "ALL REGISTERED STUDENTS";
        cout << right;
        setColor(COLOR_CYAN);
        cout << "|\n";
        cout << "+======================================================================+\n";
        resetColor();

        string line;
        getline(file, line);
        int count = 0;
        for (const auto &student : arr)
        {
            name = student.value("name", "");
            id = student.value("ID", "");
            sem = to_string(student.value("semester", 0));
            yr = to_string(student.value("year", 0));
            prog = to_string(student.value("Programming", 0));
            phys = to_string(student.value("Physics 1", 0));
            math = to_string(student.value("Mathematics 2", 0));
            writ = to_string(student.value("Writing and Research Skills", 0));
            setColor(COLOR_CYAN);
            cout << "|" << setw(72) << "|\n";
            cout << "|  ";
            setColor(COLOR_WHITE);
            string studentInfo = "[" + to_string(count + 1) + "] ID: " + id + " | Name: " + name + " | Semester: " + sem + "F-" + yr;
            cout << left << setw(68) << studentInfo;
            setColor(COLOR_CYAN);
            cout << right;
            cout << "|\n";
            if (prog != "0")
            {
                setColor(COLOR_CYAN);
                cout << "|  ";
                setColor(COLOR_GREEN);
                cout << left << setw(68) << ("> Programming: 1E" + prog);
                setColor(COLOR_CYAN);
                cout << right;
                cout << "|\n";
            }
            if (phys != "0")
            {
                setColor(COLOR_CYAN);
                cout << "|  ";
                setColor(COLOR_GREEN);
                cout << left << setw(68) << ("> Physics 1: 1E" + phys);
                setColor(COLOR_CYAN);
                cout << right;
                cout << "|\n";
            }
            if (math != "0")
            {
                setColor(COLOR_CYAN);
                cout << "|  ";
                setColor(COLOR_GREEN);
                cout << left << setw(68) << ("> Mathematics 2: 1E" + math);
                setColor(COLOR_CYAN);
                cout << right;
                cout << "|\n";
            }
            if (writ != "0")
            {
                setColor(COLOR_CYAN);
                cout << "|  ";
                setColor(COLOR_GREEN);
                cout << left << setw(68) << ("> Writing and Research Skills: 1E" + writ);
                setColor(COLOR_CYAN);
                cout << right;
                cout << "|\n";
            }
            count++;
        }
        file.close();
        cout << right;
        setColor(COLOR_CYAN);
        cout << "|" << setw(72) << "|\n";
        cout << "+======================================================================+\n";
        cout << "|  ";
        setColor(COLOR_YELLOW);
        cout << left << setw(68) << ("Total Students: " + to_string(count));
        setColor(COLOR_CYAN);
        cout << "|\n";
        cout << "+======================================================================+\n";
    }
    else
    {
        setColor(COLOR_RED);
        cout << "X No student database found.\n";
        resetColor();
    }
}