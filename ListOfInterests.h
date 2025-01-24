#pragma once
#include "Avl.h"
#include "Movies.h"

class ListOfInterests {
	AVLTree<string> InterestList;
public:
	void insert(string movie_name) {// we should update this list after deleting a movie
		InterestList.insert(movie_name);
	}
	void deleteMovie(string movie_name) {
		InterestList.deleteKey(movie_name);
	}
	void showList() {
		InterestList.inOrder();
	}
};