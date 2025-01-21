#include "Menu.h"
#include "SignUp.h"
void HideCursor();

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

void HideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo); // Get current cursor settings
    cursorInfo.bVisible = FALSE;                     // Set cursor visibility to false
    SetConsoleCursorInfo(consoleHandle, &cursorInfo); // Apply the settings
}
