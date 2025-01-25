#pragma once
#include "Movies.h"

class ListOfInterests {
	AVLTree<string> InterestList;
	vector<string> allMovies;
public:
	void insert(string movie_name) {// we should update this list after deleting a movie
		InterestList.insert(movie_name);
		allMovies.push_back(movie_name);
	}
	void deleteMovie(string movie_name) {
		auto it = find(allMovies.begin(), allMovies.end(), movie_name);
		if (it != allMovies.end()) {
			allMovies.erase(it);
		}
		else {
			cout << movie_name << " not found in the list.\n";
			return;
		}

		InterestList.deleteKey(movie_name);
		
	}
	void showList() {
		InterestList.inOrder();
	}
};