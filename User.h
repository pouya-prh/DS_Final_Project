#pragma once
#include "Movies.h"
class User
{
public:
	void ShowMoviesInfo(Movies&);
	void search(Movies&);
	void Filter(Movies&);
	//void AdvancedSearch();
	void FavoritesList();
	void FavoritesListManagement();
	void PrefferdMovies();
	void Scoring();
private:
	
	// vector<Movie> favoriteList;
};

