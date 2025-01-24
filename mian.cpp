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
    //Movie m1("Prestige", "Mystery", "you should just watch it...", "English", 2008, "USA", 8.5);
    //Movie m2("Inception", "Action", "Mind-bending action thriller", "English", 2010, "USA", 9.0);
    //Movie m3("The Dark Knight", "Action", "Superhero action movie", "English", 2008, "USA", 9.0);
    //Movie m4("Memento", "Mystery", "Suspenseful story told in reverse", "English", 2000, "USA", 8.5);
    //Movie m5("Interstellar", "Action", "Sci-fi adventure", "English", 2014, "USA", 8.6);

    //// Create a hash table to store movies by genre
    //HashTable<string, Movie> moviesByGenre;
    //// Insert movies into the hash table
    //moviesByGenre.insert("Action", m2);
    //moviesByGenre.insert("Action", m3);
    //moviesByGenre.insert("Mystery", m1);

    //HashTable <string, HashTable<string, Movie>> table;
    //table.insert("genre", moviesByGenre);
    ////// Display movies in the hash table
    //cout << "Movies before removal:" << endl;
    //moviesByGenre.display();
  
    //moviesByGenre.remove("Action", m2);  // Remove Inception (Action)
    //

    //// Display movies after removal
    //cout << "\nMovies after removal:" << endl;
    //moviesByGenre.display();
    
   //----------------------------------------Filter test
    M/*ovie m1("Prestige", "Mystery", "you should just watch it...", "English", 2008, "USA", 8.5);
    Movie m2("Inception", "Action", "Mind-bending action thriller", "English", 2010, "USA", 9.0);
    Movie m3("The Dark Knight", "Action", "Superhero action movie", "English", 2008, "USA", 9.0);
    Movie m4("Memento", "Mystery", "Suspenseful story told in reverse", "English", 2000, "USA", 8.5);
    Movie m5("Interstellar", "Action", "Sci-fi adventure", "English", 2014, "USA", 8.6);
   
    Movies movies;
    movies.InsertMovie(m1);
    movies.InsertMovie(m2);
    movies.InsertMovie(m3);
    movies.InsertMovie(m4);
    movies.InsertMovie(m5);

    movies.ShowAllMovies();

    cout << endl << "--------------------" << endl;
    User user;
    user.Filter(movies);*/
   //------------------------------------------
}


