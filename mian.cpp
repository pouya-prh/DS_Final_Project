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
			
			User user;
			while (true)
			{
				string command;
				
				getline(cin, command);

				if (command == "show all movies")
				{
					user.ShowMoviesInfo(movies);
				}
				else if (command == "search")
				{
					user.search(movies);
				}
				else if (command == "watch movie")
				{
					cout << "Enter movie's name :" << endl;
					string name;
					getline(cin, name);
					cin.clear();
					user.watch(movies, name);
				}
				else if (command == "filter")
				{
					user.Filter(movies);
				}
				else if (command == "add to favorite")
				{
					string name;
					cout << "What is the movie`s name? ";
				
					getline(cin, name);
					cin.clear();
					user.InsertToFavoriteList(movies, name);
				}
				else if (command == "remove from favorite")
				{
					string name;
					cout << "What is the movie`s name? ";
				
					getline(cin, name);
					cin.clear();
					user.DeleteFromFavoriteList(movies, name);
				}
				else if (command == "show favorite list")
				{
					user.ShowFavoritesList();
				}
				else if (command == "show suggests")
				{
					user.PrefferdMovies(movies);
				}
				else if (command == "scoreing")
				{
					string name;
					float score;
					cout << "What is the movie`s name? ";
					getline(cin, name);
					cin.clear();
					//cin.ignore();
					//cin >> name;
					cout << "score: ";
					cin >> score;
					user.Scoring(movies, name, score);
				}
				else if (command == "exit")
				{
					break;
				}
				cin.clear();  
				//cin.ignore();
			}

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
					
					getline(cin, name);
					cin.clear();

					cout << "Genre: ";
					getline(cin, genre);
					cin.clear();

					cout << "Country: ";
					getline(cin, country);
					cin.clear();

					cout << "Language: ";
					getline(cin, language);
					cin.clear();

					cout << "Story (brief description): ";
					getline(cin, story);
					cin.clear();

					cout << "Year: ";
					cin >> year;

					cout << "Score (out of 10): ";/// remove it later
					cin >> score;

					admin.AddMovie(movies, name, genre, story, language, year, country, score);

					cout << "Movie added successfully!\n";
				}
				else if (command == "Delete movie")
				{
					//string genre;
					string name;
					/*string country;
					string language;
					string story;
					int year;
					float score;
					cout << "Please complete the following questions:\n";*/

					cout << "Name: ";
				
					getline(cin, name);
					cin.clear();
				
					/*cout << "Genre: ";
					getline(cin, genre);
					cin.clear();

					cout << "Country: ";
					getline(cin, country);
					cin.clear();

					cout << "Language: ";
					getline(cin, language);
					cin.clear();

					cout << "Story (brief description): ";
					getline(cin, story);
					cin.clear();

					cout << "Year: ";
					cin >> year;

					cout << "Score (out of 10): ";///remove it later
					cin >> score;*/

					admin.RemoveMovie(movies, name);

					/*cout << "Movie Deleted successfully!\n";*/
				}
				else if (command == "exit")
				{
					break;
				}
			}
		}
		
	}

	return 0;
}


