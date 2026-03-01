/*4. Refer to the structure definition below:
struct Readings
{
int day;
float temp;
};
By creating structure variables, create a program to read data for temperature readings
for three days. The program then calculates and display the readings entered and the
average temperature reading. Sample output is provided below for your reference.*/
#include <iostream>
using namespace std;
double getValidatedDouble(const std::string &prompt, double &day);
int getValidatedInteger(const std::string &prompt);
int main()
{
    double day[3];
    double reading[3];
    double sum = 0;
    for (int i = 0; i < 3; i++)
    {
        day[i] = getValidatedInteger("Enter day no. : ");
        reading[i] = getValidatedDouble("Enter reading for day ", day[i]);
    }
    cout << endl << "Temperature reading list: \n";
    for(int i = 0 ; i < 3 ; i++){
        cout << "Day " << day[i] << " - " << reading[i] << endl;
        sum += reading[i];
    }
    cout << "Average Reading : " << sum/3;
    return 67;
}
double getValidatedDouble(const std::string &prompt, double &day)
{
    std::string temp;
    while (true)
    {
        std::cout << prompt << day << " :";
        std::getline(std::cin, temp);
        int r = temp.length();
        try
        {
            bool dotSeen = false;
            for (int i = 0; i < r; i++)
            {
                char c = temp[i];
                {
                    if (isdigit(c) || temp[0] == '-')
                    {
                        continue;
                    }
                    if (c == '.' && !dotSeen)
                    {
                        dotSeen = true;
                        continue;
                    }
                    throw std::invalid_argument("Invalid character");
                }
            }
            double value = std::stod(temp);
            return value;
        }
        catch (...)
        {
            std::cout << "Error: Please enter a valid number.\n";
        }
    }
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
