#include <iostream>
using namespace std;
class UncleJoke
{
    public :
    UncleJoke(){
      //this is useless  
    }
    void Punchline()
    {
        cout << "Answer: Nobody Knows" << endl;
    }
};
int main()
{
    UncleJoke Joke;
    cout << "Question: What do you call someone with no body and no nose?";
    cout << endl
         << endl;
    system("pause");
    cout << endl;
    Joke.Punchline();
    return 0;
}