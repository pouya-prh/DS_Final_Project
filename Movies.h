#pragma once
#include "Headers.h"
#include "SplayTree.h"
#include "HashTable.h"
class Movie
{
public:
	Movie(string& name, string& ganre, string& story, string& language, int& year,string& country,float score = -1);
	void ShowMovieInfo();



private:
	string name;
	string ganre;
	string story;
	string language;
	string country;
	int year;
	float score;


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

	 SplayTree splayTree;
	 //CompressedTrie compressedTrie;
	 vector<Movie> allMovies;
	 HashTable<string,vector<Movie>> ganres;
	 HashTable<string,vector<Movie>> languages;
	 HashTable<int,vector<Movie>> years;
	 HashTable<string,vector<Movie>> countries;
	 HashTable<int,vector<Movie>> scores;
};
