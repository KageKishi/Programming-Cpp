/*1. Create a program to store 2 students email address and social media nickname using a
structure. Refer to the sample output below:*/
#include <iostream>
using namespace std;
struct student{
    string email;
    string instagram;
};
int main(){
    student students[2];
    for(int i = 0 ; i < 2 ; i++){
        cout <<"Enter your email address : ";
        getline(cin , students[i].email);
        cout << "Enter your Instagram handle: ";
        getline(cin , students[i].instagram);
    }
    cout << "\nYour List: \n";
    for(int i = 0 ; i < 2 ; i++){
        cout << "Email address: " << students[i].email << endl;
        cout << "Instagram ID: " << students[i].instagram << endl;
        cout << endl;
    }
    return 0;
}