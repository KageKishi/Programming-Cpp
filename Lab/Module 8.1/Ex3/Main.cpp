/*3.Write a program using to count number of Vowel, Consonant and Space. Use array and loop*/
#include <iostream>
#include <map>
#include <cctype>
using namespace std;
int main()
{
    int space = 0, consonants = 0, vowels = 0;
    string sentence;
    map<char, int> Vowelcount;
    Vowelcount['a'] = 0;
    Vowelcount['e'] = 0;
    Vowelcount['i'] = 0;
    Vowelcount['o'] = 0;
    Vowelcount['u'] = 0;
    cout << "Input a sentence: ";
    getline(cin, sentence);
    for (size_t i = 0; i < sentence.length(); i++)
    {
        sentence[i] = tolower(sentence[i]);
        if (Vowelcount.find(sentence[i]) != Vowelcount.end())
        {
            Vowelcount[sentence[i]]++;
            vowels++;
        }
        else if (isspace(sentence[i]))
        {
            space++;
        }
        else if (isalpha(sentence[i]))
        {
            consonants++;
        }
        else
        {
            continue;
        }
    }
    for (map<char, int>::iterator it = Vowelcount.begin(); it != Vowelcount.end(); it++)
    {
        cout << "\nsentence has " << it->second << " " << it->first;
    }
    cout << "\nCount of Vowels: " << vowels;
    cout << "\nCount of Consonants: " << consonants;
    cout << "\nCount of Spaces: " << space;
    return 0;
}
