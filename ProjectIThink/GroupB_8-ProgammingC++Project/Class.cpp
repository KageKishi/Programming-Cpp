
class Register
{
public:
    map<string, int> classes = {
        {"Programming", 0},
        {"Physics 1", 0},
        {"Mathematics 2", 0},
        {"Writing and Research Skills", 0}};

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
    Register()
    {
        RecalculateGroupSlots(courseamt);
    }

    bool hasRegistrations()
    {
        for (const auto &cls : classes)
        {
            if (cls.second != 0)
                return true;
        }
        return false;
    }

    int GroupRegistrationModule()
    {
        bool validGroup = false;
        while (!validGroup)
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
            

            setColor(COLOR_YELLOW);
            groupchoice = getValidatedInteger("\nGroup Selection: ");
            

            if (groupchoice >= 1 && groupchoice <= 4)
            {
                setColor(COLOR_GREEN);
                cout << "> You have chosen Group ";
                setColor(COLOR_CYAN);
                cout << "1E" << groupchoice;
                
                cout << "\n";
                validGroup = true;
            }
            else if (groupchoice != 0)
            {
                system("cls");
                setColor(COLOR_RED);
                cout << "X Invalid choice\n";
                
                Sleep(1000);
            }
            else
            {
                system("cls");
                return 0;
            }
        }
        return groupchoice;
    }

    int CourseChoosing(const int &group, string &ID, string &name, int &semester, int &year)
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
            

            setColor(COLOR_YELLOW);
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
                        courseamt[group][cll.first]--;
                    for (auto &cll : classes)
                        cll.second = group;
                    registered = true;
                    system("cls");
                    setColor(COLOR_GREEN);
                    cout << "> Successfully registered ALL units in ";
                    SaveToJSON(ID, name, semester, year, classes);
                    setColor(COLOR_CYAN);
                    cout << "1E" << group;
                    setColor(COLOR_GREEN);
                    cout << "!\n";
                    
                    Loading();
                }
                else
                {
                    system("cls");
                    setColor(COLOR_RED);
                    cout << "X Cannot register all units:\n";
                    
                    for (const auto &r : reasons)
                    {
                        setColor(COLOR_YELLOW);
                        cout << "  - " << r << "\n";
                        
                    }
                    Sleep(2000);
                }
                break;
            }
            default:
                system("cls");
                setColor(COLOR_RED);
                cout << "X Invalid choice\n";
                
                Sleep(1000);
            }

            if (!selectedClass.empty())
            {
                if (courseamt[group][selectedClass] == 0 && course >= 1 && course <= 4)
                {
                    setColor(COLOR_RED);
                    system("cls");
                    cout << "X Sorry, no slots available for ";
                    setColor(COLOR_CYAN);
                    cout << "1E" << group;
                    setColor(COLOR_RED);
                    cout << " - ";
                    setColor(COLOR_CYAN);
                    cout << selectedClass << "\n";
                    if (classes[selectedClass] != 0 && course >= 1 && course <= 4)
                    {
                        setColor(COLOR_RED);
                        cout << "! You have also already registered for ";
                        setColor(COLOR_CYAN);
                        cout << selectedClass;
                        setColor(COLOR_RED);
                        cout << " in ";
                        setColor(COLOR_CYAN);
                        cout << "1E" << classes[selectedClass];
                        
                        cout << "\n";
                    }
                    
                    Sleep(1500);
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
                    
                    cout << "\n";
                    Sleep(2000);
                }
                else if (course >= 1 && course <= 4)
                {
                    system("cls");
                    courseamt[group][selectedClass]--;
                    classes[selectedClass] = group;
                    SaveToJSON(ID, name, semester, year, classes);
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
                    
                    registered = true;
                    Loading();
                    return 1;
                }
            }
        }
    }

    int GroupRecordModule(const string &name, int semester, int year, string ID)
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
            

            char choice;
            while (true)
            {
                setColor(COLOR_YELLOW);
                cout << "\nPrint record to file? (Y/N): ";
                setColor(COLOR_CYAN);
                cin >> ws >> choice;
                string trash;
                getline(cin, trash);
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
                    

                    file.close();
                    system("start Record.txt");
                    SaveToJSON(ID, name, semester, year, classes);
                    LoadingMain();
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
                    
                }
            }
        }
        else
        {
            system("cls");
            setColor(COLOR_RED);
            cout << "X You have not registered yet!\n";
            
            Sleep(1500);
            return 0;
        }
    }
};
