#pragma once
#include "Headers.h" //added vector to headers
#include "Movies.h"
#include "CompressedTrie.h"
#include "SplayTree.h"
#include "Levenshtein.h"


class SearchMovie {
    HashTable<string, Movie> movies;
    CompressedTrie trie;
    SplayTree cache;
public:
    
    void addNewMovieToList(const Movie& m) {
        //movies[m.getName()] = m;
        movies.insert(m.getName(), m);
        //movies.push_back(m);
        trie.insert(m.getName());// .name() added to movie
        //cache.insert(m.Name());
    }

    void deleteMovie(const string& search_text) {
        if (trie.find(search_text)) {
            movies.remove(search_text, movies.get(search_text));
            trie.delete_word(search_text);
        }
        else {
            cout << "this movie doesn't exist" << endl;
            return;
        }
        if (cache.find(search_text)) {
            cache.erase(search_text);
        }
    }

    const Movie& find(const string& search_text) {
        if (trie.find(search_text)) {
            cache.insert(search_text);
            return movies.get(search_text); //O(1)
        }

        /*cout << "\nSuggestions :" << endl;
        trie.print_similar_results(search_text);
        cout << endl;*/

        return NIL;
    }

    void showResults(const string& search_text) { // normal search
        trie.print_similar_results(search_text);
    }

    void advancedSearch(const string& search_text) {
        cout << "~ recently searched: " << endl;
        showRecentlySearches();
        cout << "\n~ similar results :" << endl;
        trie.print_similar_results(search_text);
        cout << "\n~ Do you mean ..." << endl;

        vector<string> names = movies.getTable();
        Levenshtein lev;
        for (auto name : names) {
            if (lev.minDistance(search_text, name) <= search_text.length() / 3) {
                cout << name << endl;
            }
        }
        cout << endl;
    }

    void showRecentlySearches() {
        cache.printNearRoot(2);
    }

};