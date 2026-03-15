/*3. Create a program to ask the user to choose a menu item from a list. Following that, the
program then asks for the quantity of the item required and prepare a receipt with details
of the order using ofstream into a text file. Refer to the following sample output to complete
your program.*/
#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
int getValidatedInteger(const std::string &prompt);
int main()
{
    double price;
    string item[3] = {"Chiken Macmafin set", "Sosej Macmafin with Egg set", "Bfast Wrap set"};
    int choice;
    while (choice < 1 || choice > 3)
    {
        choice = getValidatedInteger("Please make your selection:\n1) Chiken Macmafin set (RM4.95)\n2) Sosej Macmafin with Egg set (RM5.95)\n3) Bfast Wrap set (RM6.95)\n\n Choice: ");
        switch (choice)
        {
        case 1:
        {
            price = 4.95;
            break;
        }
        case 2:
        {
            price = 5.95;
            break;
        }
        case 3:
        {
            price = 6.95;
            break;
        }
        default:
        {
            cout << "Please only choose 1-3";
        }
        }
    }
    int quantity = getValidatedInteger("\nEnter the quantity (sets) required: ");
    cout << "\n\nThank You. That will be RM " << price * quantity;
    cout << "\n\nYour reciept is ready for printing";
    for (int i = 0; i < 4; i++)
    {
        cout << ".";
        Sleep(500);
    }
    ofstream receipt("Receipt.txt");
    receipt << "Order List: \n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n";
    receipt << quantity << " x " << item[choice - 1];
    receipt << "\n\nTotal Price: RM " << price * quantity;
    receipt << "\n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\nThank you and enjoy your meal!";
    receipt.close();
    system("start Receipt.txt");
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