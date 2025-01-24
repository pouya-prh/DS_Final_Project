#pragma once
#include "Headers.h"
#include "SplayTree.h"
#include "HashTable.h"

class Movie
{
public:
	Movie(string name, string ganre, string story, string language, int year,string country,float score = -1);
	void ShowMovieInfo();
	string getGanre() const;
	string getName() const;
	string getStory() const;
	string getLanguage() const;
	int getYear() const;
	float getScore() const;
	string getCountry() const;
	bool operator==(const Movie& other) const;
	
	void operator =(const Movie& other)
	{
		this->name = other.name;
		this->country = other.country;
		this->genre = other.genre;
		this->score = other.score;
		this->year = other.year;

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
const Movie NIL("", "", "", "", 0, "");


class Movies
{

public:
	Movies()
		: allMovies(),
		genres(),
		languages(),
		years(),
		countries(),
		scores() {}
	void InsertMovie(Movie&);
	void RemoveMovie(Movie&);
	void ShowAllMovies();
	void Search(string& name,vector<Movie>& results);
	vector<Movie> Filter(string genre = "\0", string language = "\0", int year = -1, string country = "\0", int score = -1);
	vector<Movie> IntersectMovies( vector<Movie>& v1,  vector<Movie>& v2);
	
	/*vector<Movie>& AdvancedSearch(string& name);*/
private:

	 //SplayTree splayTree;
	 //CompressedTrie compressedTrie;
	 vector<Movie> allMovies;
	 HashTable<string,HashTable<string,Movie>> genres;
	 HashTable<string, HashTable<string, Movie>> languages;
	 HashTable<int, HashTable<string, Movie>> years;
	 HashTable<string, HashTable<string, Movie>> countries;
	 HashTable<float, HashTable<string, Movie>> scores;
	

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
	bool operator==(const Serial& other) const;
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