#pragma once
#include "Movies.h"
#include "ListOfInterests.h"
class User
{
public:
	void ShowMoviesInfo(Movies&);
	void search(Movies&);
	void Filter(Movies&);
	//void AdvancedSearch();
	void ShowFavoritesList();
	void InsertToFavoriteList(Movies&,string);
	void DeleteFromFavoriteList(Movies&,string);
	void PrefferdMovies(Movies&);
	void Scoring(Movies&, string,float);
	void watch(Movies&, string);
private:

	ListOfInterests interestedList;
	
	
};

