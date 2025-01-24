#include "User.h"

void User::ShowMoviesInfo(Movies& movies)
{
	movies.ShowAllMovies();
}

void User::search(Movies& movies,string name)
{
    vector<Movie> results;

	movies.Search(name, results);
    for (auto it : results)
    {
        it.ShowMovieInfo();
    }
}
void User::Filter(Movies& movies)
{
    cout << "Filter your movie search based on the following criteria:" << endl;
    cout << "1. Genre  2. Score  3. Country  4. Language  5. Release Year" << endl;
    cout << "Enter the numbers corresponding to the criteria you'd like to filter by, one at a time." << endl;
    cout << "When you are done, enter -1 to proceed." << endl;

    vector<int> entries;
    while (true)
    {
        int a;
        cin >> a;
        if (a == -1)
            break;
        entries.push_back(a);
    }

    string genre = "\0";
    int score = -1;
    string country = "\0";
    string language = "\0";
    int date = -1;

    for (int i = 0; i < entries.size(); i++)
    {
        if (entries[i] == 1)
        {
            cout << "Enter the genre you'd like to filter by: ";
            cin >> genre;
        }
        else if (entries[i] == 2)
        {
            cout << "Enter the minimum score (e.g., 7 for movies rated 7 or higher): ";
            cin >> score;
        }
        else if (entries[i] == 3)
        {
            cout << "Enter the country you'd like to filter by: ";
            cin >> country;
        }
        else if (entries[i] == 4)
        {
            cout << "Enter the language you'd like to filter by (e.g., English, French): ";
            cin >> language;
        }
        else if (entries[i] == 5)
        {
            cout << "Enter the release year you'd like to filter by (e.g., 2021): ";
            cin >> date;
        }
        else
        {
            cout << "Invalid input. Please enter a valid number from the list (1-5) or -1 to finish." << endl;
        }
    }

    cout << "Applying your filters..." << endl;

    vector<Movie> filteredMovies = movies.Filter(genre, language, date, country, score);

    if (filteredMovies.empty())
    {
        cout << "No movies found matching your filters." << endl;
    }
    else
    {
        cout << "Here are the movies that match your filters:" << endl;
        for (auto& movie : filteredMovies)
        {
            movie.ShowMovieInfo();
        }
    }
}



