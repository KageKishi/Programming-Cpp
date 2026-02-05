/*1. Create a program for the user to enter the details using 3 Student IDs and their marks
and store the information into a text file called StudentList.txt using ofstream class. Refer
to the sample output of the program below: */
#include <iostream>
#include <fstream>
using namespace std;
int getValidatedInteger(const std::string &prompt, const int &i);
int getValidID(const int &i);
int main()
{
    int ID[3];
    int Mark[3];
    for (int i = 1; i < 4; i++)
    {
        ID[i - 1] = getValidID(i);
        Mark[i - 1] = getValidatedInteger("Mark : ", i);
        cout << endl;
    }
    ofstream Data("StudentList.txt");
    if(Data){
        cout << "\nStudentList.txt has been created\n";
        for(int j = 0 ; j < 3 ; j++){
            Data << ID[j] << endl;
            Data << Mark[j] << endl;
            Data << endl;
        }
        Data.close();
    }else{
        cout << "File failed to create\n";
        Data.close();
    }
    system("start StudentList.txt");
    return 0;
}
int getValidatedInteger(const std::string &prompt, const int &i)
{
    std::string temp;
    while (true)
    {
        std::cout << "Enter Student" << i << " " << prompt;
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
int getValidID(const int &i)
{
    string temp;
    while (true)
    {
        temp = to_string(getValidatedInteger("ID : ", i));
        if (temp.substr(0, 4) != "7000")
        {
            cout << "First 4 digit must be 7000\n";
        }
        else
        {
            int value = stoi(temp);
            return value;
        }
    }
}
