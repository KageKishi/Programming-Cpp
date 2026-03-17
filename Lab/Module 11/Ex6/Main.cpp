#include <iostream>
using namespace std;
double getValidatedDouble(const std::string &prompt);
class Calculate
{
private:
    double Test1, Tes2, Test3, total;

public:
    void Total(double Test1, double Test2, double Test3)
    {
        total = Test1 + Test2 + Test3;
        cout << "Total Test Score: " << total << endl;
    }
    void Average()
    {
        cout << "Average Test Score: " << total / 3 << endl;
    }
};
int main()
{
    double T1, T2, T3;
    Calculate C;
    T1 = getValidatedDouble("Please enter the first test marks: ");
    T2 = getValidatedDouble("Please enter the second test marks: ");
    T3 = getValidatedDouble("Please enter the third test marks: ");
    C.Total(T1, T2, T3);
    C.Average();
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
