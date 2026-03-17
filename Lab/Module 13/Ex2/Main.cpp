/*2. Create a program for the student to enter the details of the 2 units enrolled this semester
(using a structure) into two separate text files using ofstream class. Refer to the sample
output of the program below*/
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    string code[2];
    string name[2];
    string UCname[2];
    for(int i = 1 ; i < 3 ; i++){
        cout << "Enter unit" << i << " code: ";
        getline(cin , code[i-1]);
        cout << "Enter unit" << i << " name: ";
        getline(cin , name[i-1]);
        cout << "Enter unit" << i << " UC name: ";
        getline(cin , UCname[i-1]);
        cout << endl;
        if(i == 1){
            cout << "File2.txt has been created\n";
            ofstream File1("File1.txt");
            File1 << "Unit: " << code[i-1] << name[i-1] << endl << endl;
            File1 << "Unit Coordinator: "<< UCname[i-1] << endl;
            File1.close();
            system("start File1.txt");
        }
        if(i == 2){
            cout << "File2.txt has been created\n";
            ofstream File2("File2.txt");
            File2 << "Unit: " << code[i-1] << name[i-1] << endl << endl;
            File2 << "Unit Coordinator: "<< UCname[i-1] << endl;
            File2.close();
            system("start File2.txt");
        }
    }
}