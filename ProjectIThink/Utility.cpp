
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <chrono>
#include <thread>
#include <windows.h>
#include <sstream>
#include <stdexcept>
#include <cctype>

using namespace std;
// Forward declarations for symbols defined in other translation units
void resetColor();
void setColor(int color);
void SaveToJSON(const string &ID, const string &name, int semester, int year,
                const map<string, int> &classes);
// Ensure color macros exist when not provided elsewhere
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
int getValidatedInteger(const std::string &prompt)
{
    std::string temp;
    while (true)
    {
        setColor(COLOR_YELLOW);
        std::cout << prompt;
        setColor(COLOR_CYAN);
        std::getline(std::cin >> ws, temp);
        resetColor();
        try
        {
            for (char c : temp)
            {
                if (!isdigit(c))
                    throw std::invalid_argument("Invalid");
            }
            return std::stoi(temp);
        }
        catch (...)
        {
            setColor(COLOR_RED);
            std::cout << "Error: Enter valid number.\n";
            resetColor();
        }
    }
}

string getname(const string &prompt)
{
    string temp;
    while (true)
    {
        bool SpaceSeen = false;
        bool valid = true;
        setColor(COLOR_YELLOW);
        cout << prompt;
        setColor(COLOR_CYAN);
        getline(cin, temp);
        if (isspace(temp[0]))
        {
            cout << "Your name cant start with space\n";
            continue;
        }
        resetColor();
        if (temp.empty())
        {
            setColor(COLOR_RED);
            cout << "ERROR: Name cannot be empty!\n";
            resetColor();
            continue;
        }
        for (char c : temp)
        {
            if (isdigit(c) || (!isalpha(c) && !isspace(c)) || (isspace(c) && SpaceSeen))
            {
                setColor(COLOR_RED);
                cout << "ERROR: Name can only be Alphabets and 1 space to seperate First and Last name!\n";
                resetColor();
                valid = false;
                break;
            }
            if (isspace(c))
            {
                SpaceSeen = true;
            }
        }
        if (valid)
        {
            resetColor();
            return temp;
        }
    }
}

void Loading()
{
    setColor(COLOR_YELLOW);
    cout << "Loading";
    for (int i = 0; i < 3; i++)
    {
        cout << " . ";
        Sleep(500);
    }
    resetColor();
    system("cls");
}

void LoadingMain()
{
    setColor(COLOR_YELLOW);
    cout << "Loading Main Menu";
    for (int i = 0; i < 3; i++)
    {
        cout << " . ";
        Sleep(500);
    }
    resetColor();
    system("cls");
}

// Get console width
int getConsoleWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

// Print a string centered with a given color
void printCenteredLine(const string &lines, int color)
{
    int width = getConsoleWidth();
    int padding = max(0, (width - (int)lines.size()) / 2);
    cout << string(padding, ' ');
    setColor(color);
    cout << lines << "\n";
}

// Main function
void printDeveloperInfo()
{
    system("chcp 65001 > nul");

    vector<string> asciiArt = {
        "+==================================================================================================+",
        "|                                                                                                  |",
        "|    ######### #########  ##     ## #########  ##        #######  ######   #########  ######       |",
        "|    ##     ## ##          ##   ##  ##         ##       ##     ## ##   ##  ##         ##   ##      |",
        "|    ##     ## #######     ##   ##  #######    ##       ##     ## ######   #######    ######       |",
        "|    ##     ## ##           ## ##   ##         ##       ##     ## ##       ##         ##   ##      |",
        "|    ######### #########     ###    #########  ########  #######  ##       #########  ##    ##     |",
        "|                                                                                                  |",
        "|                        ####  ##   ## #########  #######                                          |",
        "|                         ##   ###  ## ##        ##     ##                                         |",
        "|                         ##   ## # ## #######   ##     ##                                         |",
        "|                         ##   ##  ### ##        ##     ##                                         |",
        "|                        ####  ##   ## ##         #######                                          |",
        "|                                                                                                  |",
        "+==================================================================================================+"};

    vector<string> memberInfo = {
        "Group 4-B:",
        "1. Lor Hengleap (p20250030)",
        "2. Tim Romnea (p20250033)",
        "3. Mony Viseth Setha (p20250017)",
        "4. Huon Lina (p20250050)",
        "",
        "Task Distribution:",
        string(70, '-'),
        "Lor Hengleap : Source Code",
        "Tim Romnea: FlowChart",
        "Mony Viseth Setha : FlowChart",
        "Huon Lina : FlowChart",
        "",
        "Thank you for using our program!",
        string(70, '=')};

    // Colors to cycle through (bright console colors)
    vector<int> colors = {9, 11, 10, 14, 13, 12, 15};

    int colorIndex = 0;

    while (true)
    {
        system("cls");

        // Print ASCII art
        for (auto &lines : asciiArt)
        {
            printCenteredLine(lines, colors[colorIndex % colors.size()]);
        }

        cout << "\n";

        // Print member info
        for (auto &lines : memberInfo)
        {
            printCenteredLine(lines, colors[colorIndex % colors.size()]);
        }

        colorIndex++;                                      // move to next color
        this_thread::sleep_for(chrono::milliseconds(500)); // slower color change
        if (colorIndex >= 50)
        {
            break;
        }
    }

    system("chcp 437 > nul");
}

string getID()
{
    string ID;
    while (true)
    {
        setColor(COLOR_YELLOW);
        ID = to_string(getValidatedInteger("\nEnter your ID: "));
        resetColor();
        if (ID.length() != 9)
        {
            setColor(COLOR_RED);
            cout << "ERROR: ID must be 9 digits!\n";
            resetColor();
            continue;
        }
        else if (ID.substr(0, 4) != "7000")
        {
            setColor(COLOR_RED);
            cout << "ERROR: ID must start with 7000!\n";
            resetColor();
            continue;
        }
        else
            return ID;
    }
}

char ExitProgram(map<string, int> &classes, const string name, const string ID, const int year, const int semester)
{
    char ans;
    while (true)
    {
        setColor(COLOR_YELLOW);
        cout << "Your choice: ";
        setColor(COLOR_CYAN);
        cin >> ans;
        ans = toupper(ans);
        if (ans == 'Y')
        {
            SaveToJSON(ID, name, semester, year, classes);
            printDeveloperInfo();
            return 'Y';
            break;
        }
        else if (ans == 'N')
        {
            setColor(COLOR_YELLOW);
            cout << "Returning to Main Menu";
            for (int i = 0; i < 3; i++)
            {
                Sleep(500);
                cout << " . ";
            }
            resetColor();
            return 'N';
            system("cls");
            break;
        }
        else
        {
            setColor(COLOR_RED);
            cout << "Invalid! Enter Y or N: ";
            resetColor();
        }
    }
}

int getValidSemester()
{
    while (true)
    {
        setColor(COLOR_YELLOW);
        int sem = getValidatedInteger("Enter Semester (1, 2, or 3): ");
        resetColor();
        if (sem >= 1 && sem <= 3)
            return sem;
        setColor(COLOR_RED);
        cout << "Invalid semester!\n";
        resetColor();
    }
}

int getValidYear()
{
    while (true)
    {
        setColor(COLOR_YELLOW);
        int yr = getValidatedInteger("\nEnter Year (e.g. 2024): ");
        resetColor();
        if (yr <= 2030 && yr >= 2020)
            return yr;
        setColor(COLOR_RED);
        cout << "Invalid year!\n";
        resetColor();
    }
}