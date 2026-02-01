/*6.Write a program to choose menu and perform calculation based on options provided; if user choose an
incorrection option, program still keep asking to re-input a correct option number:*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
double getValidatedDouble(const string &prompt);
int getValidatedInteger(const string &prompt);
class Calculator {
private:
    double num1{}, num2{}, result{};
    bool first = true;
    char ans;
public:
    void Input() {
        if (first) {
            num1 = getValidatedDouble("Please input value A: ");
            first = false;
        }
        num2 = getValidatedDouble("Please input value B: ");
    }
    void Addition() {
        result = num1 + num2;
        cout << "Answer: " << result << endl;
        num1 = result;
    }
    void Subtraction() {
        result = num1 - num2;
        cout << "Answer: " << result << endl;
        num1 = result;
    }
    void Multiplication() {
        result = num1 * num2;
        cout << "Answer: " << result << endl;
        num1 = result;
    }
    void Division() {
        if (num2 == 0) {
            cout << "Error: Division by zero!\n";
            return;
        }
        result = num1 / num2;
        cout << "Answer: " << result << endl;
        num1 = result;
    }
    bool Again() {
        cout << "Continue with result? (y/n): ";
        cin >> ans;
        cin.ignore();
        ans = toupper(ans);
        if (ans == 'Y') return true;
        if (ans == 'N') {
            first = true;
            return false;
        }
        cout << "Invalid choice. Please enter y or n.\n";
        return Again();
    }
};
int main() {
    Calculator calculator;
    int choice;
    while (true) {
        choice = getValidatedInteger(
            "\n=== Math Menu ===\n"
            "1. Addition (+)\n"
            "2. Subtraction (-)\n"
            "3. Multiplication (x)\n"
            "4. Division (/)\n"
            "5. Quit\n"
            "Choose: "
        );
        if (choice == 5) break;
        if (choice < 1 || choice > 5) {
            cout << "Invalid menu option.\n";
            continue;
        }
        do {
            calculator.Input();
            switch (choice) {
                case 1: calculator.Addition(); break;
                case 2: calculator.Subtraction(); break;
                case 3: calculator.Multiplication(); break;
                case 4: calculator.Division(); break;
            }
        } while (calculator.Again());
    }
    cout << "Goodbye!\n";
    return 0;
}
double getValidatedDouble(const std::string &prompt)
{
    std::string temp;
    while (true)
    {
        std::cout << prompt;
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

