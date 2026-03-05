/*❖ 6. Text Editor
Write a program to record your note
→ Data must be permanently stored in local file (Ex. data.txt) */
#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;
int getValidatedInteger(const std::string &prompt);
class notes
{
public:
    json arr;
    json current;
    int choice;
    int order = 1;
    notes()
    {
        arr = json::array();
        ifstream READ("notes.json");
        if (READ && READ.peek() != EOF)
        {
            try
            {
                READ >> arr;
            }
            catch (...)
            {
                arr = json::array();
            }
        }

        if (READ.is_open())
            READ.close();
    }
    void saveNote()
    {
        ofstream WRITE("notes.json");
        WRITE << arr.dump(5);
        WRITE.close();
    }
    int MainMenu()
    {
        cout << "==== Menu ====\n";
        cout << "1. View my note\n";
        cout << "2. Edit\n";
        cout << "3. Quit\n";
        do
        {
            choice = getValidatedInteger("Choose an option: ");
        } while (choice < 1 || choice > 3);
        return choice;
    }
    void EditNote()
    {

        cout << "===Edit Following note===\n";
        MaNotes();
        cout << "1. Append new line\n";
        cout << "2. Update at line\n";
        cout << "3. Delete line\n";
        int editChoice = getValidatedInteger("Enter your choice: ");
        if (editChoice == 1)
        {
            cout << "Enter your note:\n";
            string content;
            getline(cin, content);
            current["content"] = content;
            current["order"] = order++;
            arr.push_back(current);
            saveNote();
        }
        if (editChoice == 2)
        {
            int lineNumber = getValidatedInteger("Enter line number to update: ");
            if (lineNumber < 1 || lineNumber > order)
            {
                cout << "Invalid line number.\n";
                return;
            }
            cout << "Enter new content:\n";
            string newContent;
            getline(cin, newContent);
            for (auto &note : arr)
            {
                if (note["order"] == lineNumber)
                {
                    note["content"] = newContent;
                    break;
                }
            }
            saveNote();
        }
        if (editChoice == 3)
        {
            int lineNumber = getValidatedInteger("Enter line number to delete: ");
            if (lineNumber < 1 || lineNumber > order)
            {
                cout << "Invalid line number.\n";
                return;
            }
            arr.erase(std::remove_if(arr.begin(), arr.end(),
                                     [lineNumber](const json &note)
                                     {
                                         return note["order"] == lineNumber;
                                     }),
                      arr.end());

            int i = 1;
            for (auto &note : arr)
            {
                note["order"] = i;
                i++;
            }
            saveNote();
        }
    }
    void MaNotes()
    {
        if (arr.empty())
        {
            cout << "Your note is empty.\n";
        }
        else
        {
            cout << "Your note:\n";
            for (const auto &note : arr)
            {
                cout << note["order"] << "--- " << note["content"] << endl;
            }
        }
    }
};
int main()
{
    notes myNotes;
    int choice;
    do
    {
        choice = myNotes.MainMenu();
        switch (choice)
        {
        case 1:
        {
            myNotes.MaNotes();
            break;
        }
        case 2:
        {
            myNotes.EditNote();
            break;
        }
        case 3:
        {
            cout << "Goodbye!\n";
            break;
        }
        default:
        {
            cout << "Invalid choice\n";
            break;
        }
        }
    } while (choice != 3);
    return 0;
}
int getValidatedInteger(const std::string &prompt)
{
    std::string temp;
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, temp);
        try
        {
            for (char c : temp)
            {
                if (!isdigit(c))
                {
                    throw std::invalid_argument("Invalid character");
                }
            }
            int value = std::stoi(temp);
            if (value > 0)
            {
                return value;
            }
        }
        catch (...)
        {
            cout << "Invalid input. Please enter a positive integer.\n";
        }
    }
}