/*4. Complete the program below that ask for the number of students required for storing a
list of students’ heights. Once all the heights are entered, the program then transfers the
information into a text file called Heights.txt. Complete the program by using ofstream
class. A sample output for the program is given below:*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int getValidatedInteger(const std::string &prompt);
double getValidatedDouble(const std::string &prompt , const int &i);
int main(){
    int quantity = getValidatedInteger("Please enter number of students: ");
    cout << endl;
    double height[quantity];
    for(int i = 0 ; i < quantity ; i++){
        height[i] = getValidatedDouble("height: ",i+1); 
    }
    ofstream Heights("Heights.txt");
    Heights << setw(10) << "Student" << setw(10) << "Height";
    for(int j = 0 ; j < quantity ; j++){
        Heights << endl;
        Heights << setw(10) << j+1 << setw(10) << height[j];
    }
    Heights.close();
    system("start Heights.txt");
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
double getValidatedDouble(const std::string &prompt ,const int &i)
{
    std::string temp;

    while (true)
    {
        std::cout << "Please Enter Student" << i << " " << prompt;
        std::getline(std::cin, temp);
        try
        {
            bool dotSeen = false;
            for (char c : temp)
            {
                if (isdigit(c))
                    continue;
                if (c == '.' && !dotSeen)
                {
                    dotSeen = true;
                    continue;
                }
                throw std::invalid_argument("Invalid character");
            }
            double value = std::stod(temp);
            if (value > 0)
                return value;
            std::cout << "Error: Value must be greater than 0.\n";
        }
        catch (...)
        {
            std::cout << "Error: Please enter a valid number.\n";
        }
    }
}
