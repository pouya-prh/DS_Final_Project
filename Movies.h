#pragma once
#include "Headers.h"
#include "SplayTree.h"
#include "CompressedTrie.h"
#include "Avl.h"
#include "HashTable.h"
#include "Searches.h"
#include "Levenshtein.h"


class Movie
{
public:
	Movie(string name, string ganre, string story, string language, int year,string country,float score = -1);
	void ShowMovieInfo();
	string getGenre() const;
	string getName() const;
	string getStory() const;
	string getLanguage() const;
	int getYear() const;
	float getScore() const;
	string getCountry() const;
	void setScore(float);
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
	vector<float> scoreAvg;


};
const Movie NIL("", "", "", "", 0, "");


class Movies
{
	class SearchMovie {
		HashTable<string, Movie> movies;
		CompressedTrie trie;
		SplayTree cache;
	public:

		void addNewMovieToList(Movie& m) {
			//movies[m.getName()] = m;
			movies.insert(m.getName(), m);
			//movies.push_back(m);
			trie.insert(m.getName());
		}

		void deleteMovie(const string& search_text) {
			if (trie.find(search_text)) {
				movies.remove(search_text, movies.get(search_text));
				trie.delete_word(search_text);
			}
			else {
				cout << "this movie doesn't exist" << endl;
				return;
			}
			if (cache.find(search_text)) {
				cache.erase(search_text);
			}
		}

		bool exists(const string& search_text) {
			return trie.find(search_text);
		}

		const Movie& find(const string& search_text) {
			if (trie.find(search_text)) {
				cache.insert(search_text);
				return movies.get(search_text); //O(1)
			}
			return NIL;
		}

		void setScores(string movie_name, float score) {
			movies.get(movie_name).setScore(score);
		}

		void showResults(const string& search_text) { // normal search
			trie.print_similar_results(search_text);
		}

		void advancedSearch(const string& search_text, SplayTree& genreCache) {
			cout << "~ recently searched: " << endl;
			showRecentlySearches();
			cout << "\n~ similar results :" << endl;
			trie.print_similar_results(search_text);
			cout << "\n~ Do you mean ..." << endl;

			vector<string> names = movies.getTable();
			Levenshtein lev;
			for (auto name : names) {
				if (lev.minDistance(search_text, name) <= max(name.length(), search_text.length()) / 3) {
					cout << name << endl;
					cache.insert(name);
					genreCache.insert(movies.get(name).getGenre());
				}
			}
			cout << endl;
		}

		void showRecentlySearches() {
			cache.printNearRoot(2);
		}
	
		void watch_movie(const string& movie_name, SplayTree& genreCache) {
			//if (!cache.empty())
			//{
				cache.insert(movie_name);
				genreCache.insert(movies.get(movie_name).getGenre());
				movies.get(movie_name).ShowMovieInfo();
				//return;
			//}
			//cout << "Movie not found, we suggest you to search to find movie !"<<endl;
		}
	};

	SplayTree cache;
	HashTable<string, AVLTree<pair<float, string>>> allMovies;
	SearchMovie searchFunctions;
	vector<Movie> allMoviesVector;
	HashTable<string,HashTable<string,Movie>> genres;
	HashTable<string, HashTable<string, Movie>> languages;
	HashTable<int, HashTable<string, Movie>> years;
	HashTable<string, HashTable<string, Movie>> countries;
	HashTable<float, HashTable<string, Movie>> scores;

public:
	Movies()
		: allMovies(),
		genres(),
		languages(),
		years(),
		countries(),
		scores() {}
	void InsertMovie(Movie&);
	void RemoveMovie(string);
	void ShowAllMovies();
	void showSuggest();
	void watch_movie(string movieName);
	const Movie& findMovie(string movieName);
	void Search(size_t typeOfSearch, string movieName);
	void setScore(string, float);
	void Filter(string genre = "\0", string language = "\0", int year = -1, string country = "\0", int score = -1);
	vector<Movie> IntersectMovies( vector<Movie>& v1,  vector<Movie>& v2);
};


class Serial
{
public:
	Serial(string& name, string& genre, string& story, string& language, int& year, string& country,
		float episodeTime, int seasonsNum, int episodesNum, float score = -1);
	void ShowSerialInfo();
	string getGenre();
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


