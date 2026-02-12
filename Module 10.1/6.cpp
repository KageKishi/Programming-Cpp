/*6. Create a program that automatically generates bib number for runner every time a
runner’s nickname is entered into the system. The program then prompts to check if the
user would like to add another runner’s nickname into the system before proceeding with
the next input. A sample output for the program is given below:*/
#include <iostream>
#include <vector>
using namespace std;
void BibList();
int main()
{
    string name;
    string ans;
    cout << "~This program will generate your running bib number~";
    cout << endl
         << endl;
    do
    {
        cout << "Please enter runner's nickname: ";
        getline(cin >> ws, name);
        BibList();
        while (true)
        {
            cout << "Would you like to add another runner (y/n)?: ";
            getline(cin >> ws, ans);
            ans[0] = toupper(ans[0]);
            if(ans[0] == 'Y' || ans[0] == 'N'){
                break;
            }
        }
    } while (ans[0] != 'N');
    cout << "\nThank you for using the bibno generator!" << endl;
    return 0;
}
void BibList()
{
    static int i = 1000;
    cout << "Your BIB number is: A" << i << endl;
}