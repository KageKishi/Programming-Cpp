/*1. Your program will be able to limit each group (i.e. 1E1, 1E2 etc.) to a maximum size of 15 students
for EACH unit. If the user attempts to chose a group which has already reached the maximum, your
program will ask the user to choose another group.*/
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;
void printDeveloperInfo();
void LoadingMain();
int getValidatedInteger(const std::string &prompt);
string getname(const string &prompt);
void Loading();
string getID();
void ExitProgram();
int getValidYear();
int getValidSemester();
class Register
{
private:
    map<string, int> classes = {
        {"Programming", 0},
        {"Physics 1", 0},
        {"Mathematics 2", 0},
        {"Writing and Research Skills", 0}};
    map<int, map<string, int>> courseamt = {
        {1, {{"Programming", 0}, {"Physics 1", 15}, {"Mathematics 2", 15}, {"Writing and Research Skills", 15}}},
        {2, {{"Programming", 15}, {"Physics 1", 15}, {"Mathematics 2", 15}, {"Writing and Research Skills", 15}}},
        {3, {{"Programming", 15}, {"Physics 1", 15}, {"Mathematics 2", 15}, {"Writing and Research Skills", 15}}},
        {4, {{"Programming", 15}, {"Physics 1", 15}, {"Mathematics 2", 15}, {"Writing and Research Skills", 15}}}};
    int groupchoice;
    int course;
    bool registered = false;
public:
    bool canExit = false;
    int GroupRegistrationModule()
    {
        cout << "\nWelcome to Group Registration Module\n";
        cout << "1 - 1E1\n";
        cout << "2 - 1E2\n";
        cout << "3 - 1E3\n";
        cout << "4 - 1E4\n";
        cout << "0 - Exit\n";
        groupchoice = getValidatedInteger("\nGroup Selection: ");
        if (groupchoice >= 1 && groupchoice <= 4)
        {
            cout << "You have chosen Group 1E" << groupchoice << "\n";
        }
        else if (groupchoice != 0)
        {
            system("cls");
            cout << "Invalid choice\n";
            return GroupRegistrationModule();
        }
        else
        {
            system("cls");
            return 0;
        }
        return groupchoice;
    }
    int CourseChoosing(int group)
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
            cout << "\nSelect a unit:\n";
            cout << "1 - Programming" << " (" << courseamt[group]["Programming"] << " slots availble)\n";
            cout << "2 - Physics 1" << " (" << courseamt[group]["Physics 1"] << " slots availble)\n";
            cout << "3 - Mathematics 2" << " (" << courseamt[group]["Mathematics 2"] << " slots availble)\n";
            cout << "4 - Writing and Research Skills" << " (" << courseamt[group]["Writing and Research Skills"] << " slots availble)\n";
            cout << "5 - Select ALL the units above (only if you have not chosen individual unit)\n";
            cout << "0 - Exit to Main Page\n";
            course = getValidatedInteger("Choice: ");
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
                if (classes["Programming"] == 0 && classes["Mathematics 2"] == 0 && classes["Physics 1"] == 0 && classes["Writing and Research Skills"] == 0 && courseamt[group]["Programming"] != 0 && courseamt[group]["Mathematics 2"] != 0 && courseamt[group]["Physics 1"] != 0 && courseamt[group]["Writing and Research Skills"] != 0)
                {
                    for (const auto &cll : classes)
                    {
                        if (courseamt[group][cll.first] != 0)
                        {
                            classes[cll.first] = group;
                            courseamt[group][cll.first]--;
                        }
                    }
                    registered = true;
                }
                else
                {
                    system("cls");
                    for (const auto &cls : classes)
                    {
                        if (cls.second != 0)
                        {
                            cout << "Sorry, you have previously registered into 1E"
                                 << cls.second << " for " << cls.first << "!\n";
                        }
                        if (courseamt[group][cls.first] == 0)
                        {
                            cout << "Sorry, no available slot for group 1E" << group << " for " << cls.first << endl;
                        }
                    }
                }
                break;
            default:
                system("cls");
                cout << "Invalid choice\n";
            }
            if (!selectedClass.empty())
            {
                if (courseamt[group][selectedClass] == 0 && course >= 1 && course <= 4)
                {
                    cout << "Sorry, no available slots for group 1E" << group << " for " << selectedClass << endl;
                }
                else if (classes[selectedClass] != 0)
                {
                    system("cls");
                    cout << "Sorry, you have previously registered into 1E" << classes[selectedClass]
                         << " for "
                         << selectedClass << "\n";
                }
                else if (course >= 1 && course <= 4)
                {
                    system("cls");
                    courseamt[group][selectedClass]--;
                    classes[selectedClass] = group;
                    cout << "You have sucessfully registered into 1E" << group
                         << " for " << selectedClass << "\n";
                    registered = true;
                    Loading();
                    return 1;
                }
            }
        }
    }
    int GroupRecordModule(const string &name, int semester, int year, string ID)
    {
        if (registered)
        {
            system("cls");
            cout << "Welcome to Grouping Record Module, " << name << "\n\n";
            cout << "Here are your registered groupings:\n\n";
            cout << "Trimester: " << semester << "F-" << year << endl;
            cout << "Student Name: " << name << endl;
            cout << "Student ID: " << ID << endl
                 << endl;
            cout << left;
            cout << setw(30) << "Unit"
                 << setw(8) << "Grouping"
                 << endl;
            cout << string(38, '=') << endl;
            for (const auto &cls : classes)
            {
                if (cls.second != 0)
                {
                    cout << setw(30) << cls.first
                         << setw(8) << ("1E" + to_string(cls.second))
                         << endl;
                }
            }
            cout << string(38, '=') << endl;
            cout << right;
            char choice;
            ofstream file("Record.txt");
            while (true)
            {
                cout << "Would you like to print your grouping record (Y/N)? ";
                cin >> ws >> choice;
                choice = toupper(choice);
                if (choice == 'Y')
                {
                    file << "Printing your grouping record...\n";
                    file << "Welcome to Grouping Record Module, " << name << "\n\n";
                    file << "Here are your registered groupings:\n\n";
                    file << "Trimester: " << semester << "F-" << year << endl;
                    file << "Student Name: " << name << endl;
                    file << "Student ID: " << ID << endl
                         << endl;
                    file << left;
                    file << setw(30) << "Unit"
                         << setw(8) << "Grouping"
                         << endl;
                    file << string(38, '=') << endl;
                    for (const auto &cls : classes)
                    {
                        if (cls.second != 0)
                        {
                            file << setw(30) << cls.first
                                 << setw(8) << ("1E" + to_string(cls.second))
                                 << endl;
                        }
                    }
                    file << string(38, '=') << endl;
                    file.close();
                    system("start Record.txt");
                    system("cls");
                    canExit = true;
                    return 0;
                }
                else if (choice == 'N')
                {
                    system("cls");
                    LoadingMain();
                    return 0;
                }
            }
        }
        else
        {
            system("cls");
            cout << "You have not registered in menu 1 above yet\n";
            return 0;
        }
    }
};
int main()
{
    int choice;
    Register page;
    string name;
    string ID;
    int semester, year;
    name = getname("Enter your name: ");
    ID = getID();
    system("cls");
    cout << "\nWelcome to our Grouping Registration App, " << name << " (ID: " << ID << ")!\n";
    cout << "Loading Main Page";
    for (int i = 0; i < 3; i++)
    {
        cout << " . ";
        Sleep(500);
    }
    system("cls");
    semester = getValidSemester();
    year = getValidYear();
    cout << "\nThank you for your input. You are registering for Trimester " << semester << "F-" << year << "!\n\n";
    LoadingMain();
    while (true)
    {
        choice = getValidatedInteger("\nGroup Registration Main Page\n1 - Register for grouping\n2 - View/Print grouping record\n0 - Exit program\n\nYour choice: ");
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
        {
            while (true)
            {
                if (page.GroupRecordModule(name, semester, year, ID) == 0)
                {
                    break;
                }
            }
            break;
        }
        case 0:
        {
            cout << "You are attempting to Exit the program.\n\n";
            cout << "Are you sure you want to exit the program, " << name << "(ID " << ID << ") Y/N?\n\n";
            ExitProgram();
            return 0;
        }
        break;
        default:
        {
            system("cls");
            cout << "Sorry, please select option 0 to 2 only!\n";
            break;
        }
        }
        if (page.canExit)
        {
            printDeveloperInfo();
            break;
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
        std::getline(std::cin >> ws, temp);
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
            return value;
        }
        catch (...)
        {
            std::cout << "Error: Please enter a valid choice.\n";
            system("cls");
        }
    }
}
string getname(const string &prompt)
{
    string temp;

    while (true)
    {
        bool ValidName = true;
        cout << prompt;
        getline(cin, temp);
        if (temp.empty())
        {
            system("cls");
            cout << "ERROR: Your name value cannot be blank/empty!\n";
            continue;
        }
        for (char c : temp)
        {
            if (isdigit(c))
            {
                cout << "ERROR: Name cannot contain numbers!\n";
                ValidName = false;
                break;
            }
        }
        if (ValidName)
            return temp;
    }
}
void Loading()
{
    cout << "Loading Group Registration Module";
    for (int i = 0; i < 3; i++)
    {
        cout << " . ";
        Sleep(500);
    }
    system("cls");
}
void LoadingMain()
{
    cout << "Loading Group Registration Main Page";
    for (int i = 0; i < 3; i++)
    {
        cout << " . ";
        Sleep(500);
    }
    system("cls");
}
void printDeveloperInfo()
{
    cout << "\n";
    cout << string(114, '=') << endl;
    cout << " |￣￣￣\\ |￣￣￣|  \\          // |￣￣￣|  |         /￣￣￣\\     |￣￣￣| |￣￣￣    /￣￣￣| \n";
    cout << " |      | |           \\       //  |         |        |        |    |      | |         |      |  \n";
    cout << " |      | |￣￣￣|      \\    //   |￣￣￣|   |        |        |    |-----|  |￣￣￣   |-----/   \n";
    cout << " |      | |             \\  //     |         |        |        |    |        |         |   \\    \n";
    cout << " |_____/  |______|       \\//      |______|  |_____|   \\_____/     |        |_______  |    \\   \n";
    cout << "\n";
    cout << "  _____   |\\   |  |￣￣￣|   /￣￣￣\\ n";
    cout << "    |     | \\  |  |         |       |    \n";
    cout << "    |     |  \\ |  |￣￣￣|  |        |     \n";
    cout << "    |     |   \\|  |         |       |   \n";
    cout << "  __|__   |     |  |         \\_____/    \n";
    cout << string(114, '=') << endl
         << endl;
    cout << "Group 1E1-A:\n";
    cout << "1. Roy Roy (7000423210)\n";
    cout << "2. Pu3 Pu3 (7000424242)\n";
    cout << "3. Don Don (7000411441)\n";
    cout << "4. Hii Hii (7000410001)\n\n";
    cout << "Team Member Task/Job Description\n";
    cout << "-------------------------------------------------------------\n";
    cout << "Roy Roy : Design flowchart and Main Page\n";
    cout << "Pu3 Pu3 : Design and Develop Grouping Selection Module\n";
    cout << "Don Don : Integration of Main Page and other Modules\n";
    cout << "Hii Hii : Debugging of Errors in all parts and program exit\n\n";
    cout << "Thank you for using our program.\n";
}
string getID()
{
    string ID;
    while (true)
    {
        ID = to_string(getValidatedInteger("\nEnter your ID: "));
        if (ID.empty())
        {
            cout << "ERROR: Your ID value cannot be blank/empty!\n";
            continue;
        }
        else if (ID.length() != 9)
        {
            cout << "ERROR: Your ID value must be 9-digit long!\n";
            continue;
        }
        else if (ID.substr(0, 4) != "7000")
        {
            cout << "ERROR: Your ID value must be in 7000XXXXX format!\n";
            continue;
        }
        else
        {
            return ID;
        }
    }
}
void ExitProgram()
{
    char ans;
    while (true)
    {
        if (ans == 'N')
        {
            break;
        }
        cout << "Your choice: ";
        cin >> ans;
        ans = toupper(ans);
        switch (ans)
        {
        case 'Y':
        {
            printDeveloperInfo();
            ans = 'N';
            break;
        }
        case 'N':
        {
            cout << "Returning to Main Page";
            for (int i = 0; i < 3; i++)
            {
                Sleep(500);
                cout << " . ";
            }
            system("cls");
            break;
        }
        default:
        {
            cout << "Invalid Choice\n";
            break;
        }
        }
    }
}
int getValidSemester()
{
    while (true)
    {
        int semester = getValidatedInteger("Enter Semester (e.g., 1,2 or 3): ");
        if (semester > 3 || semester < 0)
        {
            cout << "That Semester doesnt exist\n";
            continue;
        }
        else
            return semester;
    }
}
int getValidYear()
{
    while (true)
    {
        int year = getValidatedInteger("\nEnter Year (e.g. 2024): ");
        if (year > 2100 || year < 1900)
        {
            cout << "This year is invalid\n";
            continue;
        }
        else
            return year;
    }
}