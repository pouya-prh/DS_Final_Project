#include "Movies.h"

Movie::Movie(string& name, string& ganre, string& story, string& language, int& year, string& country,float score)
{
	this->name = name;
	this->ganre = ganre;
	this->story = story;
	this->language = language;
	this->year = year;
	this->country = country;
	this->score = score;
}

void Movie::ShowMovieInfo()
{
	cout << "name: " << name << endl << "ganre: " << ganre << endl << "story: " <<story<< endl
		<< "country: " << country << endl << "year: " << year <<endl << "language: " << language << endl;
}
