#pragma once
#include "Headers.h"
#include "Movies.h"
class Admin
{
public:
	void AddMovie(Movies&,string& name, string& ganre, string& story, string& language, int& year, string& country, float score = -1);
	void AddSerial(Serials&,string& name, string& ganre, string& story, string& language, int& year, string& country,
		float episodeTime, int seasonsNum, int episodesNum, float score = -1);
	void RemoveMovie(Movies&,Movie& movie);
	void RemoveSerial(Serial& movie);
};

