#pragma once
#include "Headers.h"
class Movie
{
public:
	Movie(string& name, string& ganre, string& story, string& language, string& year,string& country);
	void ShowMovieInfo();



private:
	string name;
	string ganre;
	string story;
	string language;
	string year;
	string country;
	int score;


};


class Movies
{

public:
	Movies();
	void InsertMovie(Movie&);
	void RemoveMovie(Movie&);
	void ShowAllMovies();
	vector<Movie>& Search(string& name);
	vector<Movie>& Filter(string ganre = "\0", string language = "\0", string year = "\0", string countriy = "\0", int score = -1);
	vector<Movie>& AdvancedSearch(string& name);
private:

	// CompressedTrie compressedTrie;
	// vector<Movie> allMovies;
	// HashTable<vector<Movie>> ganres;
	// HashTable<vector<Movie> languages;
	// HashTable<vector<Movie> years;
	// HashTable<vector<Movie>> countries;
	// HashTable<vector<Movie> scores;
};
