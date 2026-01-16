/*
Write a program to ask questions for checking Health regarding to Covid-19.
Use an Array to store answers from user’s input
*/
#include <cctype>
#include <iostream>
using namespace std;
bool validAnswer(string &ans) {
    for (size_t i = 0; i < ans.length(); i++) {
        ans[i] = tolower(ans[i]);
    }
    ans[0] = toupper(ans[0]);
    return (ans == "Yes" || ans == "No");
}
int main() {
    string questions[8] = {
        "Feeling feverish and/or having chills?",
        "Has there been any use of fever reducing medication within the last 24 hours not due to another health condition?",
        "A new cough that is not due to another health condition?",
        "New chills that are not due to another health condition?",
        "A new sore throat that is not due to another health condition?",
        "A new loss of taste or smell?",
        "Have you had a positive test for the virus that causes COVID-19 disease within the past 10 days?",
        "In the past 14 days, have you had close contact (within about 6 feet for 15 minutes or more) with someone with suspected or confirmed COVID-19?"
    };
    string answers[8];
    cout << "==== Covid-19 Screen Health ===\n";
    for (int i = 0; i < 8; i++) {
        do {
            cout << "Q" << i + 1 << ". " << questions[i] << " ";
            cin >> answers[i];
        } while (!validAnswer(answers[i]));
    }
    cout << "========================\n";
    cout << "| Questions |  Answers |\n";
    cout << "========================\n";
    for (int i = 0; i < 8; i++) {
        cout << "| Q" << i + 1 << "        | " << answers[i] << "      |\n";
        cout << "------------------------\n";
    }
    return 0;
}