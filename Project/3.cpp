/*3. Your program will request the user to select the groupings based on the units enrolled for that
particular semester. You can choose any Diploma or Foundation units listed under SPACE with a
minimum of 4 units to be included in your program for the user to choose from.
You program will start with the Main Page as seen below.*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int getValidatedInteger(const std::string &prompt);
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
        return groupchoice;
    }

    int choosegroup(int group)
    {
        while (true)
        {
            cout << "\nSelect a unit:\n";
            cout << "1 - Programming\n";
            cout << "2 - Physics\n";
            cout << "3 - Math\n";
            cout << "4 - Chemistry\n";
            cout << "5 - Select ALL the units above (only if you have not chosen individual unit)\n";
            cout << "0 - Exit\n";
            course = getValidatedInteger("Choice: ");
            string selectedClass;
            if (course == 0)
            {
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
                    classes["Programming"] = group;
                    classes["Mathematics 2"] = group;
                    classes["Physics 1"] = group;
                    classes["Writing and Research Skills"] = group;
                }
                else
                {
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
                cout << "Invalid choice\n";
            }

            if (classes[selectedClass] != 0)
            {
                cout << "Sorry, you have previously registered into 1E" << classes[selectedClass]
                     << " for "
                     << selectedClass << "\n";
            }
            else if(course != 5)
            {
                classes[selectedClass] = group;
                cout << "You have sucessfully registered into 1E" << group
                     << " for " << selectedClass << "\n";
            }
        }
    }
};
int main()
{
    int choice;
    Register page;
    while (true)
    {
        choice = getValidatedInteger("Group Registration Main Page\n1 - Register for grouping\n2 - View/Print grouping record\n0 - Exit program\n\nYour choice: ");
        switch (choice)
        {
        case 1:
            while (choice != 0)
            {
                choice = page.grouppage();
                if(choice == 0) {break;}
                while (page.choosegroup(choice) != 0)
                    ;
            }

            break;
        case 2:
            break;
        default:
            cout << "Sorry, please select option 0 to 2 only!";
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
            return value;
        }
        catch (...)
        {
            std::cout << "Error: Please enter a valid integer.\n";
        }
    }
}
