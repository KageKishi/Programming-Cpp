#include <iostream>
#include <string>
using namespace std;
int main()
{
    struct SocialMedia
    {
        string email;
        string name;
    };
    SocialMedia User[2];
    for (int i = 0 ; i < 2; i++)
    {
        cout << "Enter your email address: ";
        getline(cin >> ws, User[i].email);
        cout << "Enter your Instagram handle: ";
        getline(cin >> ws, User[i].name);
    }
    cout << "\n\nYour List: \n";
    for(int i = 0 ; i < 2 ; i++){
        cout << "Email address: " << User[i].email << endl;
        cout << "Instagram ID: " << User[i].name << endl << endl;
    }
    return 0;
}