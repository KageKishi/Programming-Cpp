/*1. Student management
Write a program to allow user mange a list of student by using Array.
You can suggest Attributes (id, name, age, etc.)*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;

int getValidatedInteger(const std::string &prompt);

class management
{
public:
    struct Student
    {
        int ID;
        string name;
        int age;
    };
    int choice;

    int Menu()
    {
        while (true)
        {
            choice = getValidatedInteger("===Menu===\n1. View all students\n2. Add a new student\n3. Delete a student\n4. Quit\nChoose an Option: ");
            if (choice > 0 && choice < 5)
            {
                return choice;
            }
            else
            {
                cout << "Please enter only 1 to 4\n";
                continue;
            }
        }
    }

    void ViewAllStudent()
    {
        ifstream infile("Record.csv");
        if (!infile)
        {
            cout << "No records found.\n";
            return;
        }
        string line;
        while (getline(infile, line))
        {
            cout << line << "\n";
        }
        infile.close();
    }

    void AddStudent(const Student &stu)
    {
        int amountoflines = 0;
        ifstream infile("Record.csv");
        bool header = false;
        string line;
        if (getline(infile, line))
        {
            header = true;
            while (getline(infile, line))
                amountoflines++;
        }
        infile.close();
        ofstream outfile("Record.csv", ios::app);
        if (!header)
        {
            outfile << "Number,ID,Name,Age\n";
        }
        outfile << (amountoflines + 1) << "," << stu.ID << "," << stu.name << "," << stu.age << "\n";
        outfile.close();
        cout << "Student added.\n";
    }
    bool StudentInCSV(int ID)
    {
        ifstream MyStudent("Record.csv");
        string line;
        // skip header (if present)
        if (!getline(MyStudent, line))
        {
            MyStudent.close();
            return false;
        }
        string id;
        string number;
        while (getline(MyStudent, line))
        {
            stringstream ss(line);
            if (!getline(ss, number, ','))
                continue;
            if (!getline(ss, id, ','))
                continue;
            try
            {
                if (id.empty())
                    continue;
                int Id = stoi(id);
                if (Id == ID)
                {
                    MyStudent.close();
                    return true;
                }
            }
            catch (...)
            {
                continue;
            }
        }
        MyStudent.close();
        return false;
    }
    void DeleteStudent(int ID)
    {
        ifstream Delete("Record.csv");
        ofstream temp("Temp.csv");
        string line;
        vector<string> lines;
        string id;
        string number;
        if (getline(Delete, line))
            lines.push_back(line);
        while (getline(Delete, line))
        {
            stringstream ss(line);
            if (!getline(ss, number, ','))
            {
                lines.push_back(line);
                continue;
            }
            if (!getline(ss, id, ','))
            {
                lines.push_back(line);
                continue;
            }
            try
            {
                if (id.empty())
                {
                    lines.push_back(line);
                    continue;
                }
                int Id = stoi(id);
                if (Id == ID)
                {
                    continue; // skip this line (delete)
                }
            }
            catch (...)
            {
            }
            lines.push_back(line);
        }
        for (string L : lines)
        {
            temp << L << "\n";
        }
        Delete.close();
        remove("Record.csv");
        temp.close();
        ofstream New("Record.csv");
        ifstream Transfer("Temp.csv");
        int i = 0;
        string trash;
        string name;
        string Identification;
        string Age;
        if (getline(Transfer, line))
        {
            New << line << endl;
        }
        while (getline(Transfer, line))
        {
            stringstream ss(line);
            getline(ss, trash, ',');
            getline(ss, Identification, ',');
            getline(ss, name, ',');
            getline(ss, Age, ',');
            i++;
            New << i << "," << Identification << "," << name << "," << Age << endl;
            cout << i << "," << Identification << "," << name << "," << Age << endl;
        }
        New.close();
        Transfer.close();
        remove("Temp.csv");
    }
};

int main()
{
    management manage;
    bool exit = false;
    while (true)
    {
        switch (manage.Menu())
        {
        case 1:
        {
            manage.ViewAllStudent();
            break;
        }
        case 2:
        {
            management::Student s;
            s.ID = getValidatedInteger("Enter ID: ");
            cout << "Enter name: ";
            std::getline(std::cin, s.name);
            s.age = getValidatedInteger("Enter age: ");
            manage.AddStudent(s);
            break;
        }
        case 3:
        {
            cout << "====Delete a student====\n";
            int ID = getValidatedInteger("Input Student ID: ");
            if (manage.StudentInCSV(ID))
            {
                manage.DeleteStudent(ID);
                cout << "The student has been deleted.\n";
            }
            else
            {
                cout << "Student is not found. Try again\n";
            }
            break;
        }
        case 4:
        {
            exit = true;
            break;
        }
        default:
        {
            break;
        }
        }
        if (exit)
        {
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
        std::getline(std::cin, temp);
        try
        {
            if (temp.empty())
                throw std::invalid_argument("Empty input");
            for (char c : temp)
            {
                if (!std::isdigit(static_cast<unsigned char>(c)))
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
