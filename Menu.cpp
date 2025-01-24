#include "Menu.h"
#include "SignUp.h"
void HideCursor();

Menu::Menu(){}

void Menu::ShowMenu() {

    SetConsoleOutputCP(CP_UTF8);
    HideCursor();
    int i = 0;
    while (true) {

        system("cls");
        if (i % 2 == 0) {
            cout << "► Sign in" << endl << "  Sign up" << endl;
        }
        else {
            cout << "  Sign in" << endl << "► Sign up" << endl;
        }

        char c = _getch();
        if (c == 'w' || c == 'W') {
            i = (i - 1 + 2) % 2;
        }
        else if (c == 's' || c == 'S') {
            i = (i + 1) % 2;
        }
        else if (c == '\r') {
            break;
        }
    }
    system("cls");
    if (i == 0) {
        cout << "Sign in selected!" << endl;
    }
    else {
        SignUp signup;
        signup.MakeNewAccount();
    }
}

void Menu::addMovie(const Movie& m) {
    Movie M = searchFunctions.find(m.getName());
    if (!(M == NIL)) {
        cout << "this movie exists before !" << endl;
        return;
    }
    if (! Movies.exists(m.getGanre())) {
        AVLTree <pair< float, string >> newAvl;
        Movies.insert(m.getGanre(), newAvl);
    }
    Movies.get(m.getGanre()).insert({ m.getScore(), m.getName()});
    searchFunctions.addNewMovieToList(m);
    /*if (allMovies.search(m.getName(), m)) {
        cout << "this movie exists before !" << endl;
        return;
    }*/
    //allMovies.insert(m.getName(), m);
}

const Movie& Menu::findMovie(string movieName) {
    auto m = searchFunctions.find(movieName);
    if (!(m == NIL)) {
        if(!cache.find(m.getGanre()))
            cache.insert(m.getGanre());

        return m;
    }
    return NIL;
}

void Menu::deleteMovie(string movieName) {
    auto m = searchFunctions.find(movieName);
    if (!(m == NIL)) {
        searchFunctions.deleteMovie(m.getName());
        Movies.get(m.getGanre()).deleteKey({ m.getScore(), m.getName() });
        if (Movies.get(m.getGanre()).size() == 0) {
            Movies.remove(m.getGanre(), Movies.get(m.getGanre()));
            cache.erase(m.getGanre());
        }
        return;
    }
    cout << "movie not found !";
}

void Menu::search(size_t typeOfSearch, string movieName) {
    switch (typeOfSearch)
    {
    case 1:
        searchFunctions.showResults(movieName);
        break;
    case 2:
        searchFunctions.advancedSearch(movieName);
        break;
    case 3:
        break;
    default:
        cout << "invalid input" << endl;
        break;
    }
}

void Menu::showSuggest() {
    string mostRecentGanre = cache.getMostRecent();
    Movies.get(mostRecentGanre).inOrder();
}

void HideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo); // Get current cursor settings
    cursorInfo.bVisible = FALSE;                     // Set cursor visibility to false
    SetConsoleCursorInfo(consoleHandle, &cursorInfo); // Apply the settings
}