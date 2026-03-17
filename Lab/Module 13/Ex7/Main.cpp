/*7. Modify the given startup code to allow the program to store two or more set of jokes and
answers into a single text file*/
#include <iostream>
#include <fstream>
using namespace std;
int getValidatedInteger(const std::string &prompt);
int main()
{
    char joke[100], ans[100];
    int choice;
    do
    {
        cout << "Please enter your riddle here: ";
        cin.getline(joke, 100);
        cout << "Please enter the answer to your riddle here: ";
        cin.getline(ans, 100);
        ofstream Jokes("DadJokes.txt", ios::app);
        Jokes << joke << endl;
        Jokes << ans << endl;
        Jokes << "___________________________" << endl
              << endl;
        Jokes.close();
        choice = getValidatedInteger("Press 1 - Add another joke\n Press 2 - To exit the program ");
    } while (choice == 1);
    system("start DadJokes.txt");
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
