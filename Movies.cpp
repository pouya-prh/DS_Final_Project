#include "Movies.h"

Movie::Movie(string name, string ganre, string story, string language, int year, string country,float score)
{
	this->name = name;
	this->genre = ganre;
	this->story = story;
	this->language = language;
	this->year = year;
	this->country = country;
	this->score = score;
	if (score >= 0)
	{
		scoreAvg.push_back(score);
	}
}

void Movie::ShowMovieInfo()
{
	cout << "name: " << name << endl << "genre: " << genre << endl << "story: " <<story<< endl
		<< "country: " << country << endl << "year: " << year <<endl << "language: " << language << endl<<"score: "<<score << "-----------------------------\n";
}

string Movie::getGenre() const
{
	return genre;
}

string Movie::getName()const
{
	return name;
}

string Movie::getStory()const
{
	return story;
}

int Movie::getYear()const
{
	return year;
}

float Movie::getScore()const
{
	return score;
}

string Movie::getCountry()const
{
	return country;
}

void Movie::setScore(float score)
{
	scoreAvg.push_back(score);
	float avg = 0;
	for (int i = 0; i < scoreAvg.size(); i++)
	{
		avg += scoreAvg[i];
	}
	score = (avg / scoreAvg.size());
}

string Movie::getLanguage()const
{
	return language;
}


bool Movie::operator==(const Movie& other) const {
	return name == other.name &&
		genre == other.genre &&
		country == other.country &&
		score == other.score &&
		year == other.year;
}

Serial::Serial(string& name, string& ganre, string& story, string& language, int& year, 
	string& country, float episodeTime, int seasonsNum, int episodesNum, float score)
{
	this->name = name;
	this->genre = ganre;
	this->story = story;
	this->language = language;
	this->year = year;
	this->country = country;
	this->score = score;
	this->episodesNum = episodesNum;
	this->episodeTime = episodeTime;
	this->seasonsNum = seasonsNum;
}

void Serial::ShowSerialInfo()
{
	cout << "name: " << name << endl << "genre: " << genre << endl << "story: " << story << endl
		<< "country: " << country << endl << "year: " << year << endl << "language: " << language << endl
		<< "seasonNum: " << seasonsNum << endl<<"episodeNum: "<<episodesNum<<endl << "episodeTime: " << episodeTime << endl;
}

string Serial::getGenre()
{
	return genre;
}

string Serial::getName()
{
	return name;
}

string Serial::getStory()
{
	return story;
}

string Serial::getLanguage()
{
	return language;
}

int Serial::getYear()
{
	return year;
}

float Serial::getScore()
{
	return score;
}

string Serial::getCountry()
{
	return country;
}

bool Serial::operator==(const Serial& other) const {
	return name == other.name &&
		genre == other.genre &&
		country == other.country &&
		score == other.score &&
		year == other.year;
}


void Movies::InsertMovie(Movie& movie)
{
	if (searchFunctions.exists(movie.getName())) {
		cout << "this movie exists before !" << endl;
		return;
	}

	//Movie M = searchFunctions.find(movie.getName());

	allMoviesVector.push_back(movie);

	if (!allMovies.exists(movie.getGenre())) {
		AVLTree <pair< float, string >> newAvl;
		allMovies.insert(movie.getGenre(), newAvl);
	}
	allMovies.get(movie.getGenre()).insert({ movie.getScore(), movie.getName() });
	searchFunctions.addNewMovieToList(movie);

	string genre = movie.getGenre();
	string language = movie.getLanguage();
	string country = movie.getCountry();
	float score = movie.getScore();
	int year = movie.getYear();
	string name = movie.getName();

	if (!genres.exists(genre)) {
		genres.insert(genre, HashTable<string, Movie>());
	}
	genres.get(genre).insert(name, movie);

	if (!languages.exists(language)) {
		languages.insert(language, HashTable<string, Movie>());
	}
	languages.get(language).insert(name, movie);

	if (!countries.exists(country)) {
		countries.insert(country, HashTable<string, Movie>());
	}
	countries.get(country).insert(name, movie);

	if (!scores.exists(score)) {
		scores.insert(score, HashTable<string, Movie>());
	}
	scores.get(score).insert(name, movie);

	if (!years.exists(year)) {
		years.insert(year, HashTable<string, Movie>());
	}
	years.get(year).insert(name, movie);
}

void Movies::RemoveMovie(string name) {

	if (! searchFunctions.exists(name)) {
		cout << "this movie doesn't exist";
		return;
	}
	Movie movie = searchFunctions.find(name);
	string language = movie.getLanguage();
	string country = movie.getCountry();
	int year = movie.getYear();
	string genre = movie.getGenre();
	float score = movie.getScore();

	if (!(movie == NIL)) {
		searchFunctions.deleteMovie(name);
		allMovies.get(genre).deleteKey({ score, name });
		if (allMovies.get(genre).size() == 0) {
			allMovies.remove(genre, allMovies.get(genre));
			cache.erase(genre);
		}
	}

	if (genres.exists(genre)) {
		genres.get(genre).remove(name, movie);
	}
	if (countries.exists(country)) {
		countries.get(country).remove(name, movie);
	}
	if (languages.exists(language)) {
		languages.get(language).remove(name, movie);
	}
	if (scores.exists(score)) {
		scores.get(score).remove(name, movie);
	}
	if (years.exists(year)) {
		years.get(year).remove(name, movie);
	}
	auto it = std::find(allMoviesVector.begin(), allMoviesVector.end(), movie);
	if (it != allMoviesVector.end()) {
		allMoviesVector.erase(it);
	}
	cout << "Movie Deleted successfully!\n";
}

void Movies::ShowAllMovies()
{
	for (auto it : allMoviesVector)
	{
		it.ShowMovieInfo();
	}
}

void Movies::showSuggest()
{
	if(! cache.empty()){
		string mostRecentGanre = cache.getMostRecent();
		auto res = allMovies.get(mostRecentGanre).inOrder();
		for (auto item : res) {
			cout << item.first << " : " << item.second << endl;
		}
	}
}

void Movies::watch_movie(string movieName) {
	if(searchFunctions.exists(movieName))
		searchFunctions.watch_movie(movieName, cache);
	else
		cout << "Movie not found, we suggest you to search to find movie !" << endl;
}

const Movie& Movies::findMovie(string movieName)
{
	if (!searchFunctions.exists(movieName)) {
		cout << "this movie doesn't exist";
		return NIL;
	}
	Movie m = searchFunctions.find(movieName);
	if (!cache.empty())
		cache.insert(m.getGenre());
	return m;
	/*if (!(m == NIL)) {

	}
	return NIL;*/
}

bool Movies::exists(string movieName) {
	if (!searchFunctions.exists(movieName))
		return false;
	
	return true;
}

void Movies::Search(size_t typeOfSearch, string movieName)
{
	switch (typeOfSearch)
	{
	case 1:
		searchFunctions.showResults(movieName);
		break;
	case 2:
		searchFunctions.advancedSearch(movieName, cache);
		break;
	default:
		cout << "invalid input" << endl;
		break;
	}
}

void Movies::setScore(string movieName, float score) {
	searchFunctions.setScores(movieName, score);
}

void Movies::showMoviesForDelete(string name) {
	searchFunctions.applyLevenshtein(name);
	cout << endl;
}

void Movies::Filter(string genre, string language, int year, string country, int score)
{

	if (genre == "\0" && language == "\0" && year == -1 && country == "\0" && score == -1) {
		ShowAllMovies();
	}

	vector<Movie> byGenre;
	vector<Movie> byLanguage;
	vector<Movie> byYear;
	vector<Movie> byCountry;
	vector<Movie> byScore;

	
	if (genre != "\0" && genres.exists(genre)) {
		auto genreTable = genres.get(genre);
		auto genreKeys = genreTable.getTable();
		for (const auto& key : genreKeys) {
			byGenre.push_back(genreTable.get(key));
		}
	}

	if (language != "\0" && languages.exists(language)) {
		auto languageTable = languages.get(language);
		auto languageKeys = languageTable.getTable();
		for (const auto& key : languageKeys) {
			byLanguage.push_back(languageTable.get(key));
		}
	}

	if (year != -1 && years.exists(year)) {
		auto yearTable = years.get(year);
		auto yearKeys = yearTable.getTable();
		for (const auto& key : yearKeys) {
			byYear.push_back(yearTable.get(key));
		}
	}

	if (country != "\0" && countries.exists(country)) {
		auto countryTable = countries.get(country);
		auto countryKeys = countryTable.getTable();
		for (const auto& key : countryKeys) {
			byCountry.push_back(countryTable.get(key));
		}
	}

	if (score != -1) {
		float floatScore = static_cast<float>(score);
		if (scores.exists(floatScore)) {
			auto scoreTable = scores.get(floatScore);
			auto scoreKeys = scoreTable.getTable();
			for (const auto& key : scoreKeys) {
				byScore.push_back(scoreTable.get(key));
			}
		}
	}


	vector<Movie> tempResult = allMoviesVector;

	if (!byGenre.empty()) {
		tempResult = IntersectMovies(tempResult, byGenre);
	}
	if (!byLanguage.empty()) {
		tempResult = IntersectMovies(tempResult, byLanguage);
	}
	if (!byYear.empty()) {
		tempResult = IntersectMovies(tempResult, byYear);
	}
	if (!byCountry.empty()) {
		tempResult = IntersectMovies(tempResult, byCountry);
	}
	if (!byScore.empty()) {
		tempResult = IntersectMovies(tempResult, byScore);
	}

	for (auto it : tempResult) {
		it.ShowMovieInfo();
	}
}



vector<Movie> Movies::IntersectMovies( vector<Movie>& v1,  vector<Movie>& v2)
{
	vector<Movie> result;
	if (v1.empty() || v2.empty()) {
		std::cout << "One of the vectors is empty." << std::endl;
		return result;
	}
	for (int i = 0; i < v1.size() ; i++)
	{

		for (int j = 0; j < v2.size(); j++) {
			if (v1[i] == v2[j]) {
				result.push_back(v2[j]);
				break;
			}
		}
	}
	return result;
}

void Serials::InsertSerial(Serial& serial)
{
	allMovies.push_back(serial);
	string genre = serial.getGenre();
	string Language = serial.getLanguage();
	string country = serial.getCountry();
	float score = serial.getScore();
	int year = serial.getYear();
	genres.insert(genre, serial);
	languages.insert(Language, serial);
	countries.insert(country, serial);
	scores.insert(score, serial);
	years.insert(year, serial);
}

void Serials::RemoveSerial(Serial& serial)
{
	string genre = serial.getGenre();
	string Language = serial.getLanguage();
	string country = serial.getCountry();
	string name = serial.getName();
	float score = serial.getScore();
	int year = serial.getYear();

	genres.remove(genre, serial);
	countries.remove(country, serial);
	languages.remove(Language, serial);
	years.remove(year, serial);
}

