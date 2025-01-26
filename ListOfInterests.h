#pragma once
#include "Movies.h"

class ListOfInterests {
	AVLTree<string> InterestList;
	//vector<string> allMovies;
public:
	void insert(Movies& movies, string movie_name) { // O(log n)
		if (movies.exists(movie_name)) {
			InterestList.insert(movie_name);
		}
		else {
			cout << "this movie not found";
		}
		//allMovies.push_back(movie_name);
	}

	void deleteMovie(Movies & movies, string movie_name) {
		/*auto it = find(allMovies.begin(), allMovies.end(), movie_name);
		if (it != allMovies.end()) {
			allMovies.erase(it);
		}
		else {
			cout << movie_name << " not found in the list.\n";
			return;
		}*/
		if (movies.exists(movie_name)) {
			InterestList.deleteKey(movie_name);	//O(log n)
		}
		else {
			cout << "this movie not found";
		}
	}

	void showList(Movies& movies) { // O(n)
		vector<string> names = InterestList.inOrder();
		//updating
		string prev_name;
		for (string name : names) {
			if (!movies.exists(name))
				InterestList.deleteKey(name);	
			else if(prev_name != name)
				cout << name << endl;
			prev_name = name;
		}
	}
};