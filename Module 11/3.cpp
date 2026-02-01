#include <iostream>
#include <string>
using namespace std;
double getValidatedDouble(const std::string &prompt);
int getValidatedInteger(const std::string &prompt);
int i;
int main()
{
    struct Readings
    {
        int day;
        float temp;
    };
    Readings Reading[3];
    double sum;
    for (int j = 0; j < 3; j++)
    {
        Reading[j].day = getValidatedInteger("Enter day no. : ");
        i = Reading[j].day;
        Reading[j].temp = getValidatedDouble("Enter reading for day "); 
    }
    cout << "\nTemperature reading list: " << endl;
    for(int k = 0 ; k < 3 ; k++){
        cout << "Day " << Reading[k].day << " - " << Reading[k].temp << endl;
        sum += Reading[k].temp;
    }
    cout << "Average reading: " << sum/3;
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
double getValidatedDouble(const std::string &prompt)
{
    std::string temp;
    while (true)
    {
        std::cout << prompt << i << " : ";
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
