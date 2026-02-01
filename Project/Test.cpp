#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <chrono>
#include <thread>

using namespace std;

// ============ COLOR FUNCTIONS ============
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void resetColor()
{
    setColor(7); // Light gray (default)
}
// Color definitions
#define COLOR_BLACK 0
#define COLOR_DARK_BLUE 1
#define COLOR_DARK_GREEN 2
#define COLOR_DARK_CYAN 3
#define COLOR_DARK_RED 4
#define COLOR_DARK_MAGENTA 5
#define COLOR_DARK_YELLOW 6
#define COLOR_LIGHT_GRAY 7
#define COLOR_DARK_GRAY 8
#define COLOR_BLUE 9
#define COLOR_GREEN 10
#define COLOR_CYAN 11
#define COLOR_RED 12
#define COLOR_MAGENTA 13
#define COLOR_YELLOW 14
#define COLOR_WHITE 15

// ============ FORWARD DECLARATIONS ============
void printDeveloperInfo();
void LoadingMain();
int getValidatedInteger(const std::string &prompt);
string getname(const string &prompt);
void Loading();
string getID();
void ExitProgram(map<string, int> &classes, const string name, const string ID, const int year, const int semester);
int getValidYear();
int getValidSemester();
void saveStudentToCSV(const string &ID, const string &name, int semester, int year, const map<string, int> &classes);
bool studentExistsInCSV(const string &ID);
bool loadStudentFromCSV(const string &ID, string &names, int &semester, int &year, map<string, int> &classes);
void viewAllStudentsFromCSV();
void recalculateGroupSlotsFromCSV(map<int, map<string, int>> &courseamt);

// ============ REGISTER CLASS DECLARATION ============

class Register
{
public:
    map<string, int> classes = {
        {"Programming", 0},
        {"Physics 1", 0},
        {"Mathematics 2", 0},
        {"Writing and Research Skills", 0}};
    bool canExit = false;

private:
    map<int, map<string, int>> courseamt = {
        {1, {{"Programming", 15}, {"Physics 1", 15}, {"Mathematics 2", 15}, {"Writing and Research Skills", 15}}},
        {2, {{"Programming", 15}, {"Physics 1", 15}, {"Mathematics 2", 15}, {"Writing and Research Skills", 15}}},
        {3, {{"Programming", 15}, {"Physics 1", 15}, {"Mathematics 2", 15}, {"Writing and Research Skills", 15}}},
        {4, {{"Programming", 15}, {"Physics 1", 15}, {"Mathematics 2", 15}, {"Writing and Research Skills", 15}}}};
    int groupchoice;
    int course;
    bool registered = false;

public:
    Register();
    bool hasRegistrations();
    int GroupRegistrationModule();
    int CourseChoosing(int group);
    int GroupRecordModule(const string &name, int semester, int year, string ID);
};

// ============ MAIN FUNCTION ============

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
            if (studentExistsInCSV(ID))
            {
                break;
            }
            else
            {
                setColor(COLOR_RED);
                cout << " ID has not been registered yet\n";
                resetColor();
                Login = false;
                break;
            }
        }

        while (Registers)
        {
            setColor(COLOR_YELLOW);
            name = getname("Enter your name: ");
            ID = getID();
            if (studentExistsInCSV(ID))
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

        if (studentExistsInCSV(ID))
        {
            break;
        }
        if (Registers)
        {
            break;
        }
    }

    if (studentExistsInCSV(ID))
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
        if (loadStudentFromCSV(ID, names, semester, year, page.classes))
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

    while (true)
    {
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
            system("cls");
            while (choice != 0)
            {
                choice = page.GroupRegistrationModule();
                choice = page.CourseChoosing(choice);
            }
            break;
        case 2:
            while (page.GroupRecordModule(name, semester, year, ID) != 0)
                ;
            break;
        case 3:
            system("cls");
            viewAllStudentsFromCSV();
            setColor(COLOR_YELLOW);
            cout << "\nPress Enter to continue...";
            resetColor();
            cin.ignore();
            cin.get();
            system("cls");
            LoadingMain();
            break;
        case 0:
            setColor(COLOR_YELLOW);
            cout << "\nExit program? (Y/N): ";
            resetColor();
            ExitProgram(page.classes, name, ID, year, semester);
            return 0;
        default:
            system("cls");
            setColor(COLOR_RED);
            cout << "X Invalid choice!\n";
            resetColor();
            Sleep(1000);
        }

        if (page.canExit)
        {
            printDeveloperInfo();
            break;
        }
    }
    return 0;
}

// ============ REGISTER CLASS IMPLEMENTATION ============

Register::Register()
{
    recalculateGroupSlotsFromCSV(courseamt);
}

bool Register::hasRegistrations()
{
    for (const auto &cls : classes)
    {
        if (cls.second != 0)
            return true;
    }
    return false;
}

int Register::GroupRegistrationModule()
{
    setColor(COLOR_CYAN);
    cout << "+============================================================+\n";
    cout << "|";
    setColor(COLOR_YELLOW);
    cout << left;
    cout << setw(60) << "GROUP REGISTRATION MODULE";
    cout << right;
    setColor(COLOR_CYAN);
    cout << "|\n";
    cout << "+============================================================+\n";
    cout << "|" << setw(62) << "|\n";
    cout << "|  ";
    setColor(COLOR_GREEN);
    cout << left << setw(58) << "1 - 1E1";
    setColor(COLOR_CYAN);
    cout << "|\n";
    cout << "|  ";
    setColor(COLOR_GREEN);
    cout << left << setw(58) << "2 - 1E2";
    setColor(COLOR_CYAN);
    cout << "|\n";
    cout << "|  ";
    setColor(COLOR_GREEN);
    cout << left << setw(58) << "3 - 1E3";
    setColor(COLOR_CYAN);
    cout << "|\n";
    cout << "|  ";
    setColor(COLOR_GREEN);
    cout << left << setw(58) << "4 - 1E4";
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
    groupchoice = getValidatedInteger("\nGroup Selection: ");
    resetColor();

    if (groupchoice >= 1 && groupchoice <= 4)
    {
        setColor(COLOR_GREEN);
        cout << "> You have chosen Group ";
        setColor(COLOR_CYAN);
        cout << "1E" << groupchoice;
        resetColor();
        cout << "\n";
    }
    else if (groupchoice != 0)
    {
        system("cls");
        setColor(COLOR_RED);
        cout << "X Invalid choice\n";
        resetColor();
        Sleep(1000);
        return GroupRegistrationModule();
    }
    else
    {
        system("cls");
        return 0;
    }
    return groupchoice;
}

int Register::CourseChoosing(int group)
{
    system("cls");
    while (true)
    {
        if (group == 0)
        {
            LoadingMain();
            system("cls");
            return 0;
        }

        // Print header with border
        setColor(COLOR_CYAN);
        cout << "+==================================================================================================+\n";
        cout << "|";
        setColor(COLOR_YELLOW);
        cout << right;
        cout << setw(49) << ("COURSE SELECTION - GROUP 1E" + to_string(group)) << setw(51);
        setColor(COLOR_CYAN);
        cout << "|\n";
        cout << "+==================================================================================================+\n";

        // Column headers
        setColor(COLOR_CYAN);
        cout << "| ";
        setColor(COLOR_WHITE);
        cout << left << setw(5) << "No.";
        setColor(COLOR_MAGENTA);
        cout << setw(37) << "Course Name";
        setColor(COLOR_YELLOW);
        cout << setw(20) << "Slots Available";
        setColor(COLOR_GREEN);
        cout << setw(35) << "Registration Status";
        setColor(COLOR_CYAN);
        cout << "|\n";
        cout << "+==================================================================================================+\n";

        // Course 1 - Programming
        setColor(COLOR_CYAN);
        cout << "| ";
        setColor(COLOR_WHITE);
        cout << left << setw(5) << "1";
        setColor(COLOR_MAGENTA);
        cout << setw(37) << "Programming";

        int slots = courseamt[group]["Programming"];
        if (slots > 5)
            setColor(COLOR_GREEN);
        else if (slots > 0)
            setColor(COLOR_YELLOW);
        else
            setColor(COLOR_RED);
        cout << setw(20) << (to_string(slots) + " slots");

        if (classes["Programming"] != 0)
        {
            setColor(COLOR_GREEN);
            cout << setw(35) << ("Registered for 1E" + to_string(classes["Programming"]));
        }
        else if (slots == 0)
        {
            setColor(COLOR_RED);
            cout << setw(35) << "No slots available";
        }
        else
        {
            setColor(COLOR_DARK_GRAY);
            cout << setw(35) << "Not registered";
        }
        setColor(COLOR_CYAN);
        cout << "|\n";

        // Course 2 - Physics 1
        setColor(COLOR_CYAN);
        cout << "| ";
        setColor(COLOR_WHITE);
        cout << left << setw(5) << "2";
        setColor(COLOR_MAGENTA);
        cout << setw(37) << "Physics 1";

        slots = courseamt[group]["Physics 1"];
        if (slots > 5)
            setColor(COLOR_GREEN);
        else if (slots > 0)
            setColor(COLOR_YELLOW);
        else
            setColor(COLOR_RED);
        cout << setw(20) << (to_string(slots) + " slots");

        if (classes["Physics 1"] != 0)
        {
            setColor(COLOR_GREEN);
            cout << setw(35) << ("Registered for 1E" + to_string(classes["Physics 1"]));
        }
        else if (slots == 0)
        {
            setColor(COLOR_RED);
            cout << setw(35) << "No slots available";
        }
        else
        {
            setColor(COLOR_DARK_GRAY);
            cout << setw(35) << "Not registered";
        }
        setColor(COLOR_CYAN);
        cout << "|\n";

        // Course 3 - Mathematics 2
        setColor(COLOR_CYAN);
        cout << "| ";
        setColor(COLOR_WHITE);
        cout << left << setw(5) << "3";
        setColor(COLOR_MAGENTA);
        cout << setw(37) << "Mathematics 2";

        slots = courseamt[group]["Mathematics 2"];
        if (slots > 5)
            setColor(COLOR_GREEN);
        else if (slots > 0)
            setColor(COLOR_YELLOW);
        else
            setColor(COLOR_RED);
        cout << setw(20) << (to_string(slots) + " slots");

        if (classes["Mathematics 2"] != 0)
        {
            setColor(COLOR_GREEN);
            cout << setw(35) << ("Registered for 1E" + to_string(classes["Mathematics 2"]));
        }
        else if (slots == 0)
        {
            setColor(COLOR_RED);
            cout << setw(35) << "No slots available";
        }
        else
        {
            setColor(COLOR_DARK_GRAY);
            cout << setw(35) << "Not registered";
        }
        setColor(COLOR_CYAN);
        cout << "|\n";

        // Course 4 - Writing and Research Skills
        setColor(COLOR_CYAN);
        cout << "| ";
        setColor(COLOR_WHITE);
        cout << left << setw(5) << "4";
        setColor(COLOR_MAGENTA);
        cout << setw(37) << "Writing and Research Skills";

        slots = courseamt[group]["Writing and Research Skills"];
        if (slots > 5)
            setColor(COLOR_GREEN);
        else if (slots > 0)
            setColor(COLOR_YELLOW);
        else
            setColor(COLOR_RED);
        cout << setw(20) << (to_string(slots) + " slots");

        if (classes["Writing and Research Skills"] != 0)
        {
            setColor(COLOR_GREEN);
            cout << setw(35) << ("Registered for 1E" + to_string(classes["Writing and Research Skills"]));
        }
        else if (slots == 0)
        {
            setColor(COLOR_RED);
            cout << setw(35) << "No slots available";
        }
        else
        {
            setColor(COLOR_DARK_GRAY);
            cout << setw(35) << "Not registered";
        }
        setColor(COLOR_CYAN);
        cout << "|\n";

        cout << "+==================================================================================================+\n";
        cout << "| ";
        setColor(COLOR_WHITE);
        cout << left << setw(5) << "5";
        setColor(COLOR_MAGENTA);
        cout << setw(92) << "Select ALL the units above (only if you have not chosen individual unit)";
        setColor(COLOR_CYAN);
        cout << "|\n";
        cout << "| ";
        setColor(COLOR_RED);
        cout << left << setw(97) << "0    Exit to Main Page";
        setColor(COLOR_CYAN);
        cout << "|\n";
        cout << "+==================================================================================================+\n";
        cout << right;
        resetColor();

        setColor(COLOR_YELLOW);
        course = getValidatedInteger("Choice: ");
        resetColor();

        string selectedClass;
        if (course == 0)
        {
            LoadingMain();
            system("cls");
            return course;
        }
        switch (course)
        {
        case 1:
            selectedClass = "Programming";
            break;
        case 2:
            selectedClass = "Physics 1";
            break;
        case 3:
            selectedClass = "Mathematics 2";
            break;
        case 4:
            selectedClass = "Writing and Research Skills";
            break;
        case 5:
        {
            bool canRegAll = true;
            vector<string> reasons;

            for (const auto &cls : classes)
            {
                if (cls.second != 0)
                {
                    canRegAll = false;
                    reasons.push_back("Already registered for " + cls.first + " in 1E" + to_string(cls.second));
                }
            }

            for (const auto &cls : classes)
            {
                if (courseamt[group][cls.first] == 0)
                {
                    canRegAll = false;
                    reasons.push_back("No slots for " + cls.first + " in 1E" + to_string(group));
                }
            }

            if (canRegAll)
            {
                for (auto &cll : classes)
                {
                    classes[cll.first] = group;
                    courseamt[group][cll.first]--;
                }
                registered = true;
                system("cls");
                setColor(COLOR_GREEN);
                cout << "> Successfully registered ALL units in ";
                setColor(COLOR_CYAN);
                cout << "1E" << group;
                setColor(COLOR_GREEN);
                cout << "!\n";
                resetColor();
                Loading();
            }
            else
            {
                system("cls");
                setColor(COLOR_RED);
                cout << "X Cannot register all units:\n";
                resetColor();
                for (const auto &r : reasons)
                {
                    setColor(COLOR_YELLOW);
                    cout << "  - " << r << "\n";
                    resetColor();
                }
                Sleep(2000);
            }
            break;
        }
        default:
            system("cls");
            setColor(COLOR_RED);
            cout << "X Invalid choice\n";
            resetColor();
            Sleep(1000);
        }

        if (!selectedClass.empty())
        {
            if (courseamt[group][selectedClass] == 0 && course >= 1 && course <= 4)
            {
                setColor(COLOR_RED);
                cout << "X Sorry, no slots available for ";
                setColor(COLOR_CYAN);
                cout << "1E" << group;
                setColor(COLOR_RED);
                cout << " - " << selectedClass << "\n";
                resetColor();
                Sleep(2000);
            }
            else if (classes[selectedClass] != 0 && course >= 1 && course <= 4)
            {
                system("cls");
                setColor(COLOR_YELLOW);
                cout << "! You already registered for ";
                setColor(COLOR_CYAN);
                cout << selectedClass;
                setColor(COLOR_YELLOW);
                cout << " in ";
                setColor(COLOR_CYAN);
                cout << "1E" << classes[selectedClass];
                resetColor();
                cout << "\n";
                Sleep(2000);
            }
            else if (course >= 1 && course <= 4)
            {
                system("cls");
                courseamt[group][selectedClass]--;
                classes[selectedClass] = group;
                setColor(COLOR_GREEN);
                cout << "> You have successfully registered ";
                setColor(COLOR_CYAN);
                cout << "1E" << group;
                setColor(COLOR_GREEN);
                cout << " for ";
                setColor(COLOR_CYAN);
                cout << selectedClass;
                setColor(COLOR_GREEN);
                cout << "!\n";
                resetColor();
                registered = true;
                Loading();
                return 1;
            }
        }
    }
}

int Register::GroupRecordModule(const string &name, int semester, int year, string ID)
{
    if (registered || hasRegistrations())
    {
        system("cls");
        setColor(COLOR_CYAN);
        cout << "+============================================================+\n";
        cout << "|";
        setColor(COLOR_YELLOW);
        cout << left;
        cout << setw(60) << "GROUPING RECORD";
        cout << right;
        setColor(COLOR_CYAN);
        cout << "|\n";
        cout << "+============================================================+\n";
        cout << "|" << setw(62) << "|\n";
        cout << "|  ";
        setColor(COLOR_WHITE);
        cout << "Student: ";
        setColor(COLOR_CYAN);
        cout << left << setw(49) << name;
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
        cout << "Trimester: ";
        setColor(COLOR_CYAN);
        cout << left << setw(47) << (to_string(semester) + "F-" + to_string(year));
        setColor(COLOR_CYAN);
        cout << right;
        cout << "|\n";
        cout << "|" << setw(62) << "|\n";
        cout << "+============================================================+\n";
        cout << "|  ";
        setColor(COLOR_WHITE);
        cout << left << setw(35) << "Unit";
        cout << left << setw(23) << "Group";
        setColor(COLOR_CYAN);
        cout << "|\n";
        cout << "+============================================================+\n";

        for (const auto &cls : classes)
        {
            if (cls.second != 0)
            {
                setColor(COLOR_CYAN);
                cout << "|  ";
                setColor(COLOR_MAGENTA);
                cout << left << setw(35) << cls.first;
                setColor(COLOR_GREEN);
                cout << left << setw(23) << ("1E" + to_string(cls.second));
                setColor(COLOR_CYAN);
                cout << "|\n";
            }
        }
        setColor(COLOR_CYAN);
        cout << "+============================================================+\n";
        resetColor();

        char choice;
        while (true)
        {
            setColor(COLOR_YELLOW);
            cout << "\nPrint record to file? (Y/N): ";
            resetColor();
            cin >> ws >> choice;
            choice = toupper(choice);

            if (choice == 'Y')
            {
                ofstream file("Record.txt");
                file << "+============================================================+\n";
                file << "|";
                file << left;
                file << setw(60) << "GROUPING RECORD";
                file << right;
                file << "|\n";
                file << "+============================================================+\n";
                file << "|" << setw(62) << "|\n";
                file << "|  ";
                file << "Student: ";
                file << left << setw(49) << name;
                file << "|\n";
                file << "|  ";
                file << "ID: ";
                file << left << setw(54) << ID;
                file << "|\n";
                file << "|  ";
                file << "Trimester: ";
                file << left << setw(47) << (to_string(semester) + "F-" + to_string(year));
                file << right;
                file << "|\n";
                file << "|" << setw(62) << "|\n";
                file << "+============================================================+\n";
                file << "|  ";
                file << left << setw(35) << "Unit";
                file << left << setw(23) << "Group";
                file << "|\n";
                file << "+============================================================+\n";

                for (const auto &cls : classes)
                {
                    if (cls.second != 0)
                    {
                        file << "|  ";
                        file << left << setw(35) << cls.first;
                        file << left << setw(23) << ("1E" + to_string(cls.second));
                        file << "|\n";
                    }
                }
                file << "+============================================================+\n";
                resetColor();

                file.close();
                system("start Record.txt");
                saveStudentToCSV(ID, name, semester, year, classes);
                canExit = true;
                return 0;
            }
            else if (choice == 'N')
            {
                system("cls");
                LoadingMain();
                return 0;
            }
            else
            {
                setColor(COLOR_RED);
                cout << "X Invalid input! Please enter Y or N.\n";
                resetColor();
            }
        }
    }
    else
    {
        system("cls");
        setColor(COLOR_RED);
        cout << "X You have not registered yet!\n";
        resetColor();
        Sleep(1500);
        return 0;
    }
}

// ============ CSV DATABASE FUNCTIONS ============

void saveStudentToCSV(const string &ID, const string &name, int semester, int year,
                      const map<string, int> &classes)
{
    ifstream infile("students.csv");
    vector<string> lines;
    bool hasHeader = false;
    if (infile.is_open())
    {
        string line;
        if (getline(infile, line))
        {
            lines.push_back(line);
            hasHeader = true;
        }

        while (getline(infile, line))
        {
            size_t pos = line.find(',');
            string storedID = line.substr(0, pos);
            if (storedID != ID)
            {
                lines.push_back(line);
            }
        }
        infile.close();
    }

    ofstream outfile("students.csv");
    if (outfile.is_open())
    {
        if (!hasHeader)
        {
            outfile << "ID,Name,Semester,Year,Programming,Physics1,Mathematics2,WritingResearch\n";
        }
        else
        {
            for (const auto &line : lines)
            {
                outfile << line << "\n";
            }
        }

        outfile << ID << "," << name << "," << semester << "," << year << ",";
        outfile << classes.at("Programming") << ",";
        outfile << classes.at("Physics 1") << ",";
        outfile << classes.at("Mathematics 2") << ",";
        outfile << classes.at("Writing and Research Skills") << "\n";
        outfile.close();
    }
}

bool studentExistsInCSV(const string &ID)
{
    ifstream file("students.csv");
    if (file.is_open())
    {
        string line;
        getline(file, line);
        while (getline(file, line))
        {
            stringstream ss(line);
            string id;
            getline(ss, id, ',');
            if (id == ID)
            {
                file.close();
                return true;
            }
        }
        file.close();
    }
    return false;
}

bool loadStudentFromCSV(const string &ID, string &names, int &semester, int &year,
                        map<string, int> &classes)
{
    ifstream file("students.csv");
    if (file.is_open())
    {
        string line;
        getline(file, line);
        while (getline(file, line))
        {
            stringstream ss(line);
            string id, n, sem, yr, prog, phys, math, writ;
            getline(ss, id, ',');
            if (id == ID)
            {
                getline(ss, n, ',');
                names = n;
                getline(ss, sem, ',');
                getline(ss, yr, ',');
                getline(ss, prog, ',');
                getline(ss, phys, ',');
                getline(ss, math, ',');
                getline(ss, writ, ',');

                semester = stoi(sem);
                year = stoi(yr);
                classes["Programming"] = stoi(prog);
                classes["Physics 1"] = stoi(phys);
                classes["Mathematics 2"] = stoi(math);
                classes["Writing and Research Skills"] = stoi(writ);
                file.close();
                return true;
            }
        }
        file.close();
    }
    return false;
}

void viewAllStudentsFromCSV()
{
    ifstream file("students.csv");
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
        while (getline(file, line))
        {
            stringstream ss(line);
            string id, name, sem, yr, prog, phys, math, writ;

            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, sem, ',');
            getline(ss, yr, ',');
            getline(ss, prog, ',');
            getline(ss, phys, ',');
            getline(ss, math, ',');
            getline(ss, writ, ',');

            count++;
            setColor(COLOR_CYAN);
            cout << "|" << setw(72) << "|\n";
            cout << "|  ";
            setColor(COLOR_WHITE);
            string studentInfo = "[" + to_string(count) + "] ID: " + id + " | Name: " + name + " | Semester: " + sem + "F-" + yr;
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
        }
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
        resetColor();
        file.close();
    }
    else
    {
        setColor(COLOR_RED);
        cout << "X No student database found.\n";
        resetColor();
    }
}

void recalculateGroupSlotsFromCSV(map<int, map<string, int>> &courseamt)
{
    for (int g = 1; g <= 4; g++)
    {
        courseamt[g]["Programming"] = 15;
        courseamt[g]["Physics 1"] = 15;
        courseamt[g]["Mathematics 2"] = 15;
        courseamt[g]["Writing and Research Skills"] = 15;
    }

    ifstream file("students.csv");
    if (file.is_open())
    {
        string line;
        getline(file, line);

        while (getline(file, line))
        {
            stringstream ss(line);
            string id, name, sem, yr, prog, phys, math, writ;

            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, sem, ',');
            getline(ss, yr, ',');
            getline(ss, prog, ',');
            getline(ss, phys, ',');
            getline(ss, math, ',');
            getline(ss, writ, ',');

            int pg = 0, phg = 0, mg = 0, wg = 0;
            pg = stoi(prog);
            phg = stoi(phys);
            mg = stoi(math);
            wg = stoi(writ);

            if (pg > 0 && pg <= 4)
                courseamt[pg]["Programming"]--;
            if (phg > 0 && phg <= 4)
                courseamt[phg]["Physics 1"]--;
            if (mg > 0 && mg <= 4)
                courseamt[mg]["Mathematics 2"]--;
            if (wg > 0 && wg <= 4)
                courseamt[wg]["Writing and Research Skills"]--;
        }
        file.close();
    }
}

// ============ UTILITY FUNCTIONS ============

int getValidatedInteger(const std::string &prompt)
{
    std::string temp;
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin >> ws, temp);
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
        bool valid = true;
        setColor(COLOR_YELLOW);
        cout << prompt;
        getline(cin, temp);
        if (temp.empty())
        {
            setColor(COLOR_RED);
            cout << "ERROR: Name cannot be empty!\n";
            resetColor();
            continue;
        }
        for (char c : temp)
        {
            if (isdigit(c))
            {
                setColor(COLOR_RED);
                cout << "ERROR: Name cannot contain numbers!\n";
                resetColor();
                valid = false;
                break;
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

void ExitProgram(map<string, int> &classes, const string name, const string ID, const int year, const int semester)
{
    char ans;
    while (true)
    {
        setColor(COLOR_YELLOW);
        cout << "Your choice: ";
        resetColor();
        cin >> ans;
        ans = toupper(ans);
        if (ans == 'Y')
        {
            saveStudentToCSV(ID, name, semester, year, classes);
            printDeveloperInfo();
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
        if (yr >= 1900 && yr <= 2100)
            return yr;
        setColor(COLOR_RED);
        cout << "Invalid year!\n";
        resetColor();
    }
}