#pragma once
#include "Headers.h"
#include "SplayTree.h"
#include "HashTable.h"

class Movie
{
public:
	Movie(string name, string ganre, string story, string language, int year,string country,float score = -1);
	void ShowMovieInfo();
	string getGanre();
	string getName();
	string getStory();
	string getLanguage();
	int getYear();
	float getScore();
	string getCountry();
	bool operator==(const Movie& other) const {
		return name == other.name &&
			genre == other.genre &&
			country == other.country &&
			score == other.score &&
			year == other.year;
	}
	

private:
	string name;
	string genre;
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
	/*void ShowAllMovies();
	vector<Movie>& Search(string& name);
	vector<Movie>& Filter(string ganre = "\0", string language = "\0", string year = "\0", string countriy = "\0", int score = -1);
	vector<Movie>& AdvancedSearch(string& name);*/
private:

	 //SplayTree splayTree;
	 //CompressedTrie compressedTrie;
	 vector<Movie> allMovies;
	 HashTable<string,Movie> genres;
	 HashTable<string,Movie> languages;
	 HashTable<int,Movie> years;
	 HashTable<string,Movie> countries;
	 HashTable<float,Movie> scores;
	

};


class Serial
{
public:
	Serial(string& name, string& genre, string& story, string& language, int& year, string& country,
		float episodeTime, int seasonsNum, int episodesNum, float score = -1);
	void ShowSerialInfo();
	string getGanre();
	string getName();
	string getStory();
	string getLanguage();
	int getYear();
	float getScore();
	string getCountry();
	bool operator==(const Serial& other) const {
		return name == other.name &&
			genre == other.genre &&
			country == other.country &&
			score == other.score &&
			year == other.year;
	}
private:
	string name;
	string genre;
	string story;
	string language;
	string country;
	int year;
	int seasonsNum;
	int episodesNum;
	float episodeTime;
	float score;


};

class Serials
{
public:
	Serials();
	void InsertSerial(Serial&);
	void RemoveSerial(Serial&);
	/*void ShowAllSerials();
	vector<Serial>& Search(string& name);
	vector<Serial>& Filter(string genre = "\0", string language = "\0", string year = "\0", string countriy = "\0", int score = -1);
	vector<Serial>& AdvancedSearch(string& name);*/
private:

	//SplayTree splayTree;
	////CompressedTrie compressedTrie;
	vector<Serial> allMovies;
	HashTable<string, Serial> genres;
	HashTable<string,Serial> languages;
	HashTable<int,Serial> years;
	HashTable<string,Serial> countries;
	HashTable<float,Serial> scores;

};