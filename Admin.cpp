#include "Admin.h"

void Admin::AddMovie(Movies& movies, string& name, string& genre, string& story, string& language, int& year, string& country, float score)
{
	Movie movie(name, genre, story, language, year, country, score);
	movies.InsertMovie(movie);
}

void Admin::AddSerial(Serials& serials, string& name, string& genre, string& story, string& language, int& year, string& country, float episodeTime, int seasonsNum, int episodesNum, float score)
{
	Serial serial(name, genre, story, language, year, country, episodeTime, seasonsNum, episodesNum, score);
	
	serials.InsertSerial(serial);
}

void Admin::RemoveMovie(Movies& movies, string name)
{
	//Movie movie(name, genre, story, language, year, country, score);
	movies.RemoveMovie(name);
}

void Admin::RemoveSerial(Serials&, string& name, string& genre, string& story, string& language, int& year, string& country,
	float episodeTime, int seasonsNum, int episodesNum, float score)
{
}

