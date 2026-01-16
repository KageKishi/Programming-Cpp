/*5. The Exit selection menu is the only way that allows the user to stop/exit the program. Your program
should not stop or exit at any point of the program execution or module, and continue running even
when the user did not enter valid responses to your question/instruction.*/
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;
void printDeveloperInfo();
int getValidatedInteger(const std::string &prompt);
string getname(const string &prompt);
void Loading();
class Register
{
private:
    map<string, int> classes = {
        {"Programming", 0},
        {"Physics 1", 0},
        {"Mathematics 2", 0},
        {"Writing and Research Skills", 0}};
    int groupchoice;
    int course;

public:
    int grouppage()
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
            return grouppage();
        }
        else
        {
            system("cls");
            return 0;
        }
        return groupchoice;
    }

    int choosegroup(int group)
    {
        system("cls");
        while (true)
        {
            if (group == 0)
            {
                Loading();
                system("cls");
                return 0;
            }
            cout << "\nSelect a unit:\n";
            cout << "1 - Programming\n";
            cout << "2 - Physics 1\n";
            cout << "3 - Mathematics 2\n";
            cout << "4 - Writing and Research Skills\n";
            cout << "5 - Select ALL the units above (only if you have not chosen individual unit)\n";
            cout << "0 - Exit to Main Page\n";
            course = getValidatedInteger("Choice: ");
            string selectedClass;
            if (course == 0)
            {
                Loading();
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
                if (classes["Programming"] == 0 && classes["Mathematics 2"] == 0 && classes["Physics 1"] == 0 && classes["Writing and Research Skills"] == 0)
                {
                    for (const auto &cll : classes)
                    {
                        classes[cll.first] = group;
                    }
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
                    }
                }
                break;
            default:
                system("cls");
                cout << "Invalid choice\n";
            }

            if (classes[selectedClass] != 0)
            {
                system("cls");
                cout << "Sorry, you have previously registered into 1E" << classes[selectedClass]
                     << " for "
                     << selectedClass << "\n";
            }
            else if (!(course >= 5 || course <= 0))
            {
                system("cls");
                classes[selectedClass] = group;
                cout << "You have sucessfully registered into 1E" << group
                     << " for " << selectedClass << "\n";
            }
        }
    }
    int grouprecord(const string &name, int semester, int year, string ID)
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
                return 0;
            }
            else if (choice == 'N')
            {
                system("cls");
                return 0;
            }
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
            break;
        }
        system("cls");
    }
    cout << "\nWelcome to our Grouping Registration App, " << name << " (ID: " << ID << ")!\n";
    cout << "Loading Main Page";
    for (int i = 0; i < 3; i++)
    {
        cout << " . ";
        Sleep(500);
    }
    system("cls");
    semester = getValidatedInteger("Enter Semester (e.g., 1,2 or 3): ");
    year = getValidatedInteger("\nEnter Year (e.g. 2024): ");
    cout << "\nThank you for your input. You are registering for Trimester " << semester << "F-" << year << "!\n\n";
    Loading();
    while (true)
    {
        choice = getValidatedInteger("\nGroup Registration Main Page\n1 - Register for grouping\n2 - View/Print grouping record\n0 - Exit program\n\nYour choice: ");
        switch (choice)
        {
        case 1:
            system("cls");
            choice = page.grouppage();
            choice = page.choosegroup(choice);
            break;
        case 2:
        {
            while (page.grouprecord(name, semester, year, ID) != 0)
                ;
            break;
        }
        case 0:
            cout << "You are attempting to Exit the program.\n\n";
            cout << "Are you sure you want to exit the program, " << name << "(ID " << ID << ") Y/N?\n\n";
            while (true)
            {
                cout << "Your choice: ";
                char YesOrNo;
                cin >> YesOrNo;
                YesOrNo = toupper(YesOrNo);
                switch (YesOrNo)
                {
                case 'Y':
                    printDeveloperInfo();
                    return 0;
                    break;
                case 'N':
                    cout << "Returning to Main Page";
                    for (int i = 0; i < 3; i++)
                    {
                        Sleep(500);
                        cout << " . ";
                    }
                    system("cls");
                    break;
                }
            }
            break;
        default:
            system("cls");
            cout << "Sorry, please select option 0 to 2 only!\n";
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
        cout << prompt;
        getline(cin, temp);
        if (temp.empty())
        {
            system("cls");
            cout << "ERROR: Your name value cannot be blank/empty!\n";
            continue;
        }
        else
        {
            return temp;
        }
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
void printDeveloperInfo()
{
    cout << "\n";
     cout << string(114, '=') << endl;
    cout << " |￣￣￣\\ |￣￣￣|  \\          // |￣￣￣|  |         /￣￣￣\\     |￣￣￣| |￣￣￣    /￣￣￣| \n";
    cout << " |      | |           \\       //  |         |        |        |    |     |  |         |      |    \n";
    cout << " |      | |￣￣￣|      \\    //   |￣￣￣|   |        |        |    |-----|  |￣￣￣   |-----/    \n";
    cout << " |      | |             \\  //     |         |        |        |    |        |         |   \\     \n";
    cout << " |_____/  |______|       \\//      |______|  |_____|   \\_____/     |        |_______  |    \\    \n";
    cout << "\n";
    cout << "  _____   |\\   |  |￣￣￣|   /￣￣￣\\ n"; 
    cout << "    |     | \\  |  |         |       |    \n";
    cout << "    |     |  \\ |  |￣￣￣|  |        |     \n";
    cout << "    |     |   \\|  |         |       |   \n";
    cout << "  __|__   |     |  |         \\_____/    \n";
    cout << string(114, '=') << endl << endl;
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