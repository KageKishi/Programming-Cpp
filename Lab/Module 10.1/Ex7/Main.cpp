/*
7. Create a program that automatically count the number of responses from the user based
on the two given options as seen below. Use the startup code provided and complete
your solution by creating the Count() user-defined function and using static data storage
type to store the count values. Please ensure that the output remains the same.
*/
#include <iostream>
using namespace std;
void Count(int choice);
int main()
{
    int choice;
    do
    {
        cout << "Choose your side: " << endl;
        cout << "Press 1 - Team Ronaldo OR 2 - Team Messi OR 3 - Undecided/Exit" << endl;
        cout << "Team: ";
        cin >> choice;
        cout << endl;
        Count(choice);
    } while (choice != 3);
    return 0;
}
void Count(int choice)
{
    static int Messi = 0;
    static int Ronaldo = 0;
    switch (choice)
    {
    case 1:
    {
        Ronaldo++;
        cout << "Team Ronaldo Count = " << Ronaldo;
        cout << "\nTeam Messi Count = " << Messi;
        cout << endl;
        break;
    }
    case 2:
    {
        Messi++;
        cout << "Team Ronaldo Count = " << Ronaldo;
        cout << "\nTeam Messi Count = " << Messi;
        cout << endl;
        break;
    }
    case 3:
    {
        cout << "\nKthxbye!";
        break;
    }
    default:
    {
        cout << "Invalid choice\n";
        break;
    }
    }
}