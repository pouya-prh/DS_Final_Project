#include "Headers.h"
#include "Menu.h"
#include "User.h";
#include "Movies.h"
#include "CompressedTrie.h"

int main()
{
	

    //-----------------------------------
	/* 
      Menu menu;
	  menu.ShowMenu();
    */


    //------------------------------------Splay tree test:
   /* SplayTree tree;
    tree.insert("The Dark Knight");
    tree.insert("Inception");
    tree.insert("Interstellar");

    tree.display();  
    cout << "--------------------"<<endl;
    tree.insert("Inception"); 
    tree.display(); */
    //------------------------------------Compressed tree test:
   /* CompressedTrie root;
    std::vector<std::string> words{ "banana", "bananas", "bandanas", "bandana", "band", "apple", "all", "beast" };
    
    root.insert_many(words);
    
    std::cout << "Words: ";
    for (const auto& word : words) {
        std::cout << word << " ";
    }
    
    std::cout << "\nTree:\n";
    root.print_tree();*/
  //--------------------------------------Hash table test:
    /*string name = "Prestige";
    string story = "you shoul just watch it...";
    string country = "USA";
    string ganre = "Mystery";
    string language = "English";
    int year = 2008;
    float score = 8.5;
    string name2 = "Interstellar";
    string story2 = "about space";
    string country2 = "USA";
    string ganre2 = "Adventure epic";
    string language2 = "English";
    int year2 = 2014;
    float score2 = 8.7;
    string name3 = "Parasite";
    string story3 = "lkvarnkvnrakevelvr";
    string country3 = "Corea";
    string ganre3 = "Adventure epic";
    string language3 = "Corean";
    int year3 = 2012;
    float score3 = 8.7;
    Movie m1(name, ganre, story, language, year, country, score);
    Movie m2(name2, ganre2, story2, language2, year2, country2, score2);
    Movie m3(name3, ganre3, story3, language3, year3, country3, score3);
    vector<Movie> usaMovies,oldMovies,coreMovies;
    usaMovies.push_back(m1);
    usaMovies.push_back(m2);
    oldMovies.push_back(m1);
    coreMovies.push_back(m3);
    HashTable<string,vector<Movie>> moviesByCountry(10);
    HashTable<int,vector<Movie>> moviesByDate(10);
    moviesByCountry.insert(country, usaMovies);
    moviesByCountry.insert(country3, coreMovies);
    moviesByDate.insert(year, oldMovies);
    moviesByCountry.display();
    moviesByDate.display();*/
   //----------------------------------------

}


