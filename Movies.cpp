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
}

void Movie::ShowMovieInfo()
{
	cout << "name: " << name << endl << "ganre: " << genre << endl << "story: " <<story<< endl
		<< "country: " << country << endl << "year: " << year <<endl << "language: " << language << endl;
}

string Movie::getGanre()
{
	return genre;
}

string Movie::getName()
{
	return name;
}

string Movie::getStory()
{
	return story;
}

int Movie::getYear()
{
	return year;
}

float Movie::getScore()
{
	return score;
}

string Movie::getCountry()
{
	return country;
}

string Movie::getLanguage()
{
	return language;
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
	cout << "name: " << name << endl << "ganre: " << genre << endl << "story: " << story << endl
		<< "country: " << country << endl << "year: " << year << endl << "language: " << language << endl
		<< "seasonNum: " << seasonsNum << endl<<"episodeNum: "<<episodesNum<<endl << "episodeTime: " << episodeTime << endl;
}

string Serial::getGanre()
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

void Movies::InsertMovie(Movie& movies)
{

	allMovies.push_back(movies);
	string genre = movies.getGanre();
	string Language = movies.getLanguage();
	string country = movies.getCountry();
	float score = movies.getScore();
	int year = movies.getYear();
	genres.insert(genre, movies);
	languages.insert(Language, movies);
	countries.insert(country, movies);
	scores.insert(score, movies);
	years.insert(year, movies);
	
	
	
}

void Movies::RemoveMovie(Movie& movie)
{
	string genre = movie.getGanre();
	string Language = movie.getLanguage();
	string country = movie.getCountry();
	string name = movie.getName();
	float score = movie.getScore();
	int year = movie.getYear();

	genres.remove(genre, movie);
	countries.remove(country, movie);
	languages.remove(Language, movie);
	years.remove(year, movie);


}

void Serials::InsertSerial(Serial& serial)
{
	allMovies.push_back(serial);
	string genre = serial.getGanre();
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
	string genre = serial.getGanre();
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
