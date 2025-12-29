/*7.Create a program that requests for the user to guess a single word string. Your program will
compare and check if the string entered is the correct secret word that you have set earlier.
Complete this program by:
a) Using a do while loop and strcmp() function.
b) Modifying the completed program in a) that will allow the user to enter their guess using any
combination of uppercase or lowercase characters, using tolower function.*/
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char secret[7] = "orange";
    char input[100];
    do
    {
        cout << "\nPlease guess the secret fruit: ";
        cin >> input;
        if (strcmp(input, secret) == 0)
        {
            cout << "Yes, You got it right ";
        }
        else
        {
            cout << "Sorry, try again! ";
            memset(input, 0, sizeof(input));
        }
    } while (strcmp(input, secret) != 0);
}