#include "Headers.h"
#include "Menu.h"
#include "User.h";
#include "Admin.h"
#include "Movies.h"
using namespace std;


int main()
{
	Menu menu;
	Movies movies;
	
	while(true)
	{
		int type = menu.ShowMenu();
		if (type == 0) //user
		{
			return 0;
			User user;

		}
		else if (type == 1) //admin
		{
			Admin admin;
			while (true)
			{
				string command;
				getline(cin, command);
				if (command == "Add movie")
				{
					string genre;
					string name;
					string country;
					string language;
					string story;
					int year;
					float score;
					cout << "Please complete the following questions:\n";

					cout << "Name: ";
					cin.ignore();
					getline(cin, name);

					cout << "Genre: ";
					getline(cin, genre);

					cout << "Country: ";
					getline(cin, country);

					cout << "Language: ";
					getline(cin, language);

					cout << "Story (brief description): ";
					getline(cin, story);

					cout << "Year: ";
					cin >> year;

					cout << "Score (out of 10): ";
					cin >> score;

					admin.AddMovie(movies, name, genre, story, language, year, country, score);

					cout << "Movie added successfully!\n";
				}
				else if (command == "Delete movie")
				{
					string genre;
					string name;
					string country;
					string language;
					string story;
					int year;
					float score;
					cout << "Please complete the following questions:\n";

					cout << "Name: ";
					cin.ignore();
					getline(cin, name);

					cout << "Genre: ";
					getline(cin, genre);

					cout << "Country: ";
					getline(cin, country);

					cout << "Language: ";
					getline(cin, language);

					cout << "Story (brief description): ";
					getline(cin, story);

					cout << "Year: ";
					cin >> year;

					cout << "Score (out of 10): ";
					cin >> score;

					admin.RemoveMovie(movies, name, genre, story, language, year, country, score);

					cout << "Movie Deleted successfully!\n";
				}
			}
		}
		
	}

	return 0;
}


