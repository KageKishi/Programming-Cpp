/*
2. Create a structure to store the following data/values by creating structure variables to
accept data for 2 different students.
• Nickname
• Date of Birth (e.g., 10, 15)
• Month of Birth (e.g., June, April)
• Year of Birth (e.g., 2001, 1990)
Refer to the following sample output to complete your program
*/
#include <iostream>
using namespace std;
struct student{
    string nickname;
    string month;
    int date;
    int year;
};
int main(){
    student students[2];
    cout << "Enter the first student birthday details: \n";
    for(int i = 0 ; i < 2 ; i++){
        if(i == 1){
            cout << "\nEnter the second student birthday details: \n";
        }
        cout << "Enter nickname: ";
        getline(cin >> ws, students[i].nickname);
        cout << "Enter day: ";
        cin >> ws >> students[i].date;
        cout << "Enter month: ";
        getline(cin >> ws, students[i].month);
        cout << "Enter year: ";
        cin >> ws >> students[i].year;
    }
    cout << "\n Data Entered: \n";
    for(int i = 0 ; i < 2 ; i++){
        cout << students[i].nickname << " - " << students[i].date << "/" << students[i].month << "/" << students[i].year << endl;
    }
    return 0;
}