/*5. Complete the start-up code below to include the system functions to clear the screen, pause the
program and exit the program. */
#include <iostream>
using namespace std;
int main()
{
    char choice;
    int check = 0;
    do
    {
        cout << endl;
        cout << "Select from the following options: ";
        cout << endl
             << endl;
        cout << "A - Reload Menu and Clear Screen" << endl;
        cout << "B - Reload Menu" << endl;
        cout << "C - Exit Program" << endl
             << endl;
        cout << "Option: ";
        cin >> choice;
        switch (choice)
        {
        case 'A':
        case 'a':
        {
            cout << "You have chosen to reload and clear..." << endl;
            cout << "Wise of you my young padawan" << endl;
            system("pause");
            system("cls");
            break;
        }
        case 'B':
        case 'b':
        {
            cout << "You have chosen to reload and not clear..." << endl;
            cout << "Why oh why my dear child?" << endl;
            system("pause");
            break;
        }
        case 'c':
        case 'C':
        {
            cout << "You have chosen to part ways with me..." << endl;
            cout << "See you on the other side" << endl;
            system("cls");
            exit(0);
            break;
        }
        default:
        {
            cout << "Invalid Choice!" << endl;
            cout << "Rerun the program and choose A, B or C only" << endl;
        }
        }
    } while (check == 0);
    return 0;
}
