/*2.Your program will request the student to enter/choose details of the semester (i.e. Trimester 1F,2F,
or 3F and Year)*/
#include <iostream>
using namespace std;
int getValidatedInteger(const std::string &prompt);
int main(){
    int semester , year;
    semester = getValidatedInteger("Enter Semester (e.g., 1,2 or 3): ");
    year = getValidatedInteger("\nEnter Year (e.g. 2024): ");
    cout << "\nThank you for your input. You are registering for Trimester " << semester << "F-" << year << "!";
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
