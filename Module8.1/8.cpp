/*8.Write a program to allow user to infinitely input student to a table by using Arrays for storing all information.
You can suggest any student’s attributes (id, name, age, etc.)*/
#include <iostream>
#include <iomanip>
using namespace std;
int getValidatedInteger(const std::string &prompt);
bool choices();
int main()
{
    int *Age = nullptr;
    string *name = nullptr;
    int *ID = nullptr;
    int i = 0;
    do
    {
        string *tempname = new string[i + 1];
        int *temp = new int[i + 1];
        int *Iden = new int[i + 1];
        for (int j = 0; j < i; j++)
        {
            temp[j] = Age[j];
            tempname[j] = name[j];
            Iden[j] = ID[j];
        }
        cout << "Student #1:\n";
        Iden[i] = getValidatedInteger("ID: ");
        cout << "Name: ";
        getline(cin >> std::ws, tempname[i]);
        temp[i] = getValidatedInteger("Age: ");
        delete[] Age;
        delete[] name;
        delete[] ID;
        Age = temp;
        name = tempname;
        ID = Iden;
        i++;
    } while (choices());
    cout << left;
    cout << "========================================\n";
    cout << "| " << setw(4) << "No"
         << "| " << setw(8) << "ID"
         << "| " << setw(15) << "Name"
         << "| " << setw(4) << "Age" << "|\n";
    cout << "========================================\n";
    for (int k = 0; k < i ; k++)
    {
        cout << "| " << setw(4) << k+1
             << "| " << setw(8) << ID[k]
             << "| " << setw(15) << name[k]
             << "| " << setw(4) << Age[k] << "|\n";
    }
    cout << "========================================\n";
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
            for (size_t i = 0; i < temp.length(); i++)
            {
                char c = temp[i];
                {
                    if (isdigit(c) || temp[0] == '-')
                    {
                        continue;
                    }
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
bool choices()
{
    string input;
    cout << "Do you want to add more (y/n)?: ";
    getline(cin >> std::ws, input);

    if (input.length() == 1)
    {
        char c = toupper(input[0]);
        if (c == 'Y')
            return true;
        if (c == 'N')
            return false;
    }
    return choices();
}
