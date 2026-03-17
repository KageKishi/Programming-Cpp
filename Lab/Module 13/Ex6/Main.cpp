/*6. The information on four units is stored in the separate files attached (File01.txt, File02.txt,
File03.txt and File04.txt). Create a program to ask the user to key in the unit code name
(e.g., FP-050) and the program will search and retrieve the information of the given unit
from the respective text file into the screen. Refer to the sample outputs of the program
below: */
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream File1("File01.txt");
    File1 << "FP-060" << endl
          << "PROG_CPP_063" << endl
          << "88.5";
    File1.close();
    ofstream File2("File02.txt");
    File2 << "FP-050" << endl
          << "PHY_061" << endl
          << "90.5";
    File2.close();
    ofstream File3("File03.txt");
    File3 << "FP-040" << endl
          << "ENG_MATH_061" << endl
          << "80.5";
    File3.close();
    ofstream File4("File04.txt");
    File4 << "FP-059" << endl
          << "ECS_061" << endl
          << "95.5";
    File4.close();
    string PASSWORD;
    cout << "Please enter unit code: ";
    getline(cin , PASSWORD);
    cout << endl;
    if (PASSWORD == "FP-060")
    {
        cout << "Your Result: \n";
        cout << "Unit Code: " << "FP-060" << endl
             << "Unit Name: " << "PROG_CPP_063" << endl
             << "Marks: " << "88.5";
        system("start File01.txt");
    }
    else if (PASSWORD == "FP-050")
    {
        cout << "Your Result: \n";
        cout << "Unit Code: " << "FP-050" << endl
             << "Unit Name: " << "PHY_061" << endl
             << "Marks: " << "90.5";
        system("start File02.txt");
    }
    else if (PASSWORD == "FP-040")
    {
        cout << "Your Result: \n";
        cout << "Unit Code: " << "FP-040" << endl
             << "Unit Name: " << "ENG_MATH_061" << endl
             << "Marks: " << "80.5";
        system("start File03.txt");
    }
    else if (PASSWORD == "FP-059")
    {
        cout << "Your Result: \n";
        cout << "Unit Code: " << "FP-059" << endl
             << "Unit Name: " << "ECS_061" << endl
             << "Marks: " << "95.5";
        system("start File04.txt");
    }
    else
    {
        cout << "Sorry, no matching unit found.";
    }
    return 0;
}