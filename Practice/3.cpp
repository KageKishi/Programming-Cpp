/*Write a program to allow user mange and search a list of video by Array.
You can suggest Attributes (Title, uploader, length, type, .etc)*/
#include <iostream>
#include <fstream>
#include "json.hpp"
#include <string>
using namespace std;
using json = nlohmann::json;
int getValidatedInteger(const std::string &prompt);
class YouTube
{
private:
    json arr;
    json current;
    string Title, Publisher, Genre;
    int length;
    int choice;

public:
    YouTube()
    {
        arr = json::array();
        ifstream READ("Videos.json");
        READ >> arr;
        READ.close();
    }
    void AddVideo()
    {
        cout << "====Add a Video====\n";
        cout << "Title: ";
        getline(cin, Title);
        cout << "Publisher: ";
        getline(cin, Publisher);
        length = getValidatedInteger("Length(s): ");
        cout << "Genre: ";
        getline(cin, Genre);
        ofstream Upload("Videos.json");
        current["Title"] = Title;
        current["Publisher"] = Publisher;
        current["Length"] = length;
        current["Genre"] = Genre;
        arr.push_back(current);
        Upload << arr.dump(5);
        Upload.close();
    }
    void ViewAllVideos()
    {
        for (auto &Reach : arr)
        {
            cout << string(20, '=') << endl;
            cout << "Title: " << Reach["Title"] << " - " << Reach["Publisher"] << endl;
            cout << "Length: " << Reach["Length"] << "s - Genre: " << Reach["Genre"] << endl;
            cout << string(20, '=') << endl;
        }
    }
    void SearchVideos()
    {
        cout << "How do you want to Search?\n";
        cout << "1. By Title\n";
        cout << "2. By Publisher\n";
        cout << "3. By Length\n";
        cout << "4. By Genre\n";
        choice = getValidatedInteger("Choose an Option: ");
        switch (choice)
        {
        case 1:
        {
            int i = 1;
            cout << "Input Title: ";
            getline(cin, Title);
            for (auto &title : arr)
            {
                if (title["Title"].get<string>().find(Title) != string::npos)
                {
                    cout << i << ". " << title["Title"] << " - By " << title["Publisher"];
                    i++;
                }
            }
            break;
        }
        }
    }
};
int main()
{
    YouTube Videos;
    while (true)
    {
        int choice;
        cout << "====Menu====\n";
        cout << "1. Search\n";
        cout << "2. View all Videos\n";
        cout << "3. Add a New Video\n";
        cout << "4. Quit\n";
        choice = getValidatedInteger("Choose an Option: ");

        switch (choice)
        {
        case 1:
        {
            Videos.SearchVideos();
            break;
        }
        case 2:
        {
            Videos.AddVideo();
            break;
        }
        case 3:
        {
            Videos.ViewAllVideos();
            break;
        }
        case 4:
        {
            return 0;
        }
        default:
        {
            cout << "Invalid choice\n";
            break;
        }
        }
        system("pause");
    }
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
            std::cout << "Error: Please enter a valid integer.\n";
        }
    }
}
