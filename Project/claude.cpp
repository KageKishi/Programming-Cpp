
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

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
    bool Registers = false;
    bool Login = false;
    
    while (true)
    {
        ans = getValidatedInteger("1.Register\n2.Login\nYour Choice: ");
        if (ans == 1)
        {
            Registers = true;
            break;
        }
        else if (ans == 2)
        {
            Login = true;
            break;
        }
        else
        {
            system("cls");
            cout << "\nInvalid Choice!\n";
            continue;
        }
    }
    
    if (Login)
    {
        ID = getID();
    }
    
    while (Registers)
    {
        name = getname("Enter your name: ");
        ID = getID();
        if (studentExistsInCSV(ID))
        {
            cout << "This ID is already registered\n";
            system("pause");
            break;
        }
        system("cls");
        cout << "\nWelcome, " << name << " (ID: " << ID << ")!\n";
        cout << "Loading";
        for (int i = 0; i < 3; i++)
        {
            cout << " . ";
            Sleep(500);
        }
        system("cls");
        semester = getValidSemester();
        year = getValidYear();
        cout << "\nRegistering for Trimester " << semester << "F-" << year << "!\n";
        break;
    }
    
    if (studentExistsInCSV(ID))
    {
        system("cls");
        cout << "Welcome back! Loading your data";
        for (int i = 0; i < 3; i++)
        {
            cout << " . ";
            Sleep(500);
        }
        system("cls");
        if (loadStudentFromCSV(ID, names, semester, year, page.classes))
        {
            name = names;
            cout << "========== YOUR INFO ==========\n";
            cout << "Name: " << name << "\n";
            cout << "ID: " << ID << "\n";
            cout << "Semester: " << semester << "F-" << year << "\n\n";
            bool hasCourses = false;
            for (const auto &cls : page.classes)
            {
                if (cls.second != 0)
                {
                    cout << "  - " << cls.first << ": 1E" << cls.second << "\n";
                    hasCourses = true;
                }
            }
            if (!hasCourses)
                cout << "  No courses registered yet.\n";

            cout << "\nPress Enter to continue... ";
            cin.ignore();
            cin.get();
            system("cls");
        }
    }
    
    LoadingMain();
    
    while (true)
    {
        cout << "\n========== Group Registration MAIN MENU ==========\n";
        cout << "1 - Register for grouping\n";
        cout << "2 - View/Print record\n";
        cout << "3 - View all students\n";
        cout << "0 - Exit\n";
        choice = getValidatedInteger("\nChoice: ");

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
            while (page.GroupRecordModule(name, semester, year, ID) != 0);
            break;
        case 3:
            system("cls");
            viewAllStudentsFromCSV();
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            system("cls");
            LoadingMain();
            break;
        case 0:
            cout << "\nExit program? (Y/N): ";
            ExitProgram(page.classes, name, ID, year, semester);
            return 0;
        default:
            system("cls");
            cout << "Invalid choice!\n";
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
        if (cls.second != 0) return true;
    }
    return false;
}

int Register::GroupRegistrationModule()
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
        cout << "\nSelect a unit:\n";
        cout << "1 - Programming (" << courseamt[group]["Programming"] << " slots available)\n";
        cout << "2 - Physics 1 (" << courseamt[group]["Physics 1"] << " slots available)\n";
        cout << "3 - Mathematics 2 (" << courseamt[group]["Mathematics 2"] << " slots available)\n";
        cout << "4 - Writing and Research Skills (" << courseamt[group]["Writing and Research Skills"] << " slots available)\n";
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
        case 1: selectedClass = "Programming"; break;
        case 2: selectedClass = "Physics 1"; break;
        case 3: selectedClass = "Mathematics 2"; break;
        case 4: selectedClass = "Writing and Research Skills"; break;
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
                cout << "Successfully registered ALL units in 1E" << group << "!\n";
                Loading();
            }
            else
            {
                system("cls");
                cout << "Cannot register all units:\n";
                for (const auto &r : reasons) cout << "  - " << r << "\n";
            }
            break;
        }
        default:
            system("cls");
            cout << "Invalid choice\n";
        }

        if (!selectedClass.empty())
        {
            if (courseamt[group][selectedClass] == 0 && course >= 1 && course <= 4)
            {
                cout << "Sorry, no slots available for 1E" << group << " - " << selectedClass << "\n";
            }
            else if (classes[selectedClass] != 0 && course >= 1 && course <= 4)
            {
                system("cls");
                cout << "You already registered for " << selectedClass << " in 1E" << classes[selectedClass] << "\n";
            }
            else if (course >= 1 && course <= 4)
            {
                system("cls");
                courseamt[group][selectedClass]--;
                classes[selectedClass] = group;
                cout << "You have successfully registered 1E" << group << " for " << selectedClass << "!\n";
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
        cout << "========== GROUPING RECORD ==========\n\n";
        cout << "Student: " << name << "\n";
        cout << "ID: " << ID << "\n";
        cout << "Trimester: " << semester << "F-" << year << "\n\n";
        cout << left << setw(35) << "Unit" << setw(10) << "Group" << "\n";
        cout << string(45, '=') << "\n";

        for (const auto &cls : classes)
        {
            if (cls.second != 0)
            {
                cout << setw(35) << cls.first << setw(10) << ("1E" + to_string(cls.second)) << "\n";
            }
        }
        cout << string(45, '=') << "\n";
        cout << right;

        char choice;
        while (true)
        {
            cout << "\nPrint record to file? (Y/N): ";
            cin >> ws >> choice;
            choice = toupper(choice);

            if (choice == 'Y')
            {
                ofstream file("Record.txt");
                file << "========== GROUPING RECORD ==========\n\n";
                file << "Student: " << name << "\n";
                file << "ID: " << ID << "\n";
                file << "Trimester: " << semester << "F-" << year << "\n\n";
                file << left << setw(35) << "Unit" << setw(10) << "Group" << "\n";
                file << string(45, '=') << "\n";

                for (const auto &cls : classes)
                {
                    if (cls.second != 0)
                    {
                        file << setw(35) << cls.first << setw(10) << ("1E" + to_string(cls.second)) << "\n";
                    }
                }
                file << string(45, '=') << "\n";
                file.close();

                system("start Record.txt");
                system("cls");
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
        }
    }
    else
    {
        system("cls");
        cout << "You have not registered yet!\n";
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
                try { semester = stoi(sem); } catch (...) { semester = 1; }
                try { year = stoi(yr); } catch (...) { year = 2024; }
                try { classes["Programming"] = stoi(prog); } catch (...) { classes["Programming"] = 0; }
                try { classes["Physics 1"] = stoi(phys); } catch (...) { classes["Physics 1"] = 0; }
                try { classes["Mathematics 2"] = stoi(math); } catch (...) { classes["Mathematics 2"] = 0; }
                try { classes["Writing and Research Skills"] = stoi(writ); } catch (...) { classes["Writing and Research Skills"] = 0; }
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
        cout << "\n========== ALL REGISTERED STUDENTS ==========\n";
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
            cout << "\n[" << count << "] ID: " << id << " | Name: " << name
                 << " | Semester: " << sem << "F-" << yr << "\n";

            if (prog != "0") cout << "    - Programming: 1E" << prog << "\n";
            if (phys != "0") cout << "    - Physics 1: 1E" << phys << "\n";
            if (math != "0") cout << "    - Mathematics 2: 1E" << math << "\n";
            if (writ != "0") cout << "    - Writing and Research Skills: 1E" << writ << "\n";
        }

        cout << "\n" << string(45, '=') << "\n";
        cout << "Total Students: " << count << "\n";
        file.close();
    }
    else
    {
        cout << "No student database found.\n";
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
            try { pg = stoi(prog); } catch (...) { }
            try { phg = stoi(phys); } catch (...) { }
            try { mg = stoi(math); } catch (...) { }
            try { wg = stoi(writ); } catch (...) { }

            if (pg > 0 && pg <= 4) courseamt[pg]["Programming"]--;
            if (phg > 0 && phg <= 4) courseamt[phg]["Physics 1"]--;
            if (mg > 0 && mg <= 4) courseamt[mg]["Mathematics 2"]--;
            if (wg > 0 && wg <= 4) courseamt[wg]["Writing and Research Skills"]--;
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
            std::cout << "Error: Enter valid number.\n";
        }
    }
}

string getname(const string &prompt)
{
    string temp;
    while (true)
    {
        bool valid = true;
        cout << prompt;
        getline(cin, temp);
        if (temp.empty())
        {
            cout << "ERROR: Name cannot be empty!\n";
            continue;
        }
        for (char c : temp)
        {
            if (isdigit(c))
            {
                cout << "ERROR: Name cannot contain numbers!\n";
                valid = false;
                break;
            }
        }
        if (valid) return temp;
    }
}

void Loading()
{
    cout << "Loading";
    for (int i = 0; i < 3; i++)
    {
        cout << " . ";
        Sleep(500);
    }
    system("cls");
}

void LoadingMain()
{
    cout << "Loading Main Menu";
    for (int i = 0; i < 3; i++)
    {
        cout << " . ";
        Sleep(500);
    }
    system("cls");
}

void printDeveloperInfo()
{
    system("chcp 65001 > nul");
    system("cls");
    cout << "\n\n";
    cout << R"(
+==================================================================================================+
|                                                                                                  |
|    ######### #########  ##     ## #########  ##        #######  ######   #########  ######       |
|    ##     ## ##          ##   ##  ##         ##       ##     ## ##   ##  ##         ##   ##      |
|    ##     ## #######     ##   ##  #######    ##       ##     ## ######   #######    ######       |
|    ##     ## ##           ## ##   ##         ##       ##     ## ##       ##         ##   ##      |
|    ######### #########     ###    #########  ########  #######  ##       #########  ##    ##     |
|                                                                                                  |
|                        ####  ##   ## #########  #######                                          |
|                         ##   ###  ## ##        ##     ##                                         |
|                         ##   ## # ## #######   ##     ##                                         |
|                         ##   ##  ### ##        ##     ##                                         |
|                        ####  ##   ## ##         #######                                          |
|                                                                                                  |
+==================================================================================================+
)" << "\n";
    system("chcp 437 > nul");
    cout << "Group 1E1-A:\n";
    cout << "1. Roy Roy (7000423210)\n";
    cout << "2. Pu3 Pu3 (7000424242)\n";
    cout << "3. Don Don (7000411441)\n";
    cout << "4. Hii Hii (7000410001)\n\n";
    cout << "Task Distribution:\n";
    cout << string(70, '-') << "\n";
    cout << "Roy Roy : Flowchart & Main Page\n";
    cout << "Pu3 Pu3 : Group Selection Module\n";
    cout << "Don Don : Integration\n";
    cout << "Hii Hii : Debugging & Exit\n\n";
    cout << "Thank you for using our program!\n";
    cout << string(70, '=') << "\n";
}

string getID()
{
    string ID;
    while (true)
    {
        ID = to_string(getValidatedInteger("\nEnter your ID: "));
        if (ID.length() != 9)
        {
            cout << "ERROR: ID must be 9 digits!\n";
            continue;
        }
        else if (ID.substr(0, 4) != "7000")
        {
            cout << "ERROR: ID must start with 7000!\n";
            continue;
        }
        else return ID;
    }
}

void ExitProgram(map<string, int> &classes, const string name, const string ID, const int year, const int semester)
{
    char ans;
    while (true)
    {
        cout << "Your choice: ";
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
            cout << "Returning to Main Menu";
            for (int i = 0; i < 3; i++)
            {
                Sleep(500);
                cout << " . ";
            }
            system("cls");
            break;
        }
        else
        {
            cout << "Invalid! Enter Y or N: ";
        }
    }
}

int getValidSemester()
{
    while (true)
    {
        int sem = getValidatedInteger("Enter Semester (1, 2, or 3): ");
        if (sem >= 1 && sem <= 3) return sem;
        cout << "Invalid semester!\n";
    }
}

int getValidYear()
{
    while (true)
    {
        int yr = getValidatedInteger("\nEnter Year (e.g. 2024): ");
        if (yr >= 1900 && yr <= 2100) return yr;
        cout << "Invalid year!\n";
    }
}
