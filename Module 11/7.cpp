#include <iostream>
using namespace std;
class MyLifeIsAJoke{
    public :
    void Joke1Ans(){
        cout << "A: Sign Language!:P \n";
    }
    void Joke2Ans(){
        cout << "A: He couldn't see himself doing it :) \n";
    }
};
int main()
{
    int option;
    MyLifeIsAJoke Yes;
    cout << "Your choices are: " << endl;
    cout << "1. Q: What is the least spoken language in the world?" << endl;
    cout << "2. Q: Why did the invisible man turn down the job offer?" << endl;
    cin >> option;
    cout << endl;
    if (option == 1)
    {
        system("pause");
        cout << endl;
        Yes.Joke1Ans();
    }
    if (option == 2)
    {
        system("pause");
        cout << endl;
        Yes.Joke2Ans();
    }
    if (option != 1 && option != 2)
    {
        cout << "Don't try to be funnier than your lecturer" << endl;
    }
    return 0;
}
