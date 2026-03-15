/*5. The information on five runners’ timings is stored in Record.txt (refer to attached file). By
using ifstream class, create a program to retrieve these timings and display the average
of the timings recorded. Refer to the sample output provided below.
*/
#include <iostream>
#include <fstream>
double getValidatedDouble(const std::string &prompt);
using namespace std;
int main(){
    cout << "Runner's timings";
    double Time[5];
    double sum;
    cout << endl;
    for(int i = 0 ; i < 5 ; i++){
        Time[i] = getValidatedDouble("");
        sum += Time[i];
        if(i == 4){
            double Average = sum/5;
            cout << "Average Timing: " << Average;
        }
    }
    ofstream time("Record.txt");
    for(int i = 0 ;i < 5 ; i++){
        time << Time[i] << endl;
    }
    time.close();
    system("start Record.txt");
    return 0;
}
double getValidatedDouble(const std::string &prompt)
{
    std::string temp;

    while (true)
    {
        std::cout << prompt;
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
