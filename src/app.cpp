#include "../include/app.hpp"

// tuple<string, >
// -------------------------------------------------------
App::App()
{
    // splashScreen();
    createMap();
}
// -------------------------------------------------------
void App::splashScreen() const
{

    cout << "   |=|===================|=|      \n";
    cout << "   |=|                   |=|      \n";
    cout << "   |=|       Sapp        |=|      \n";
    cout << "   |                       |      \n";
    cout << "   |=======================|      \n";
    cout << "   |=======================|      \n";

    cout << endl;

    cout << "[<!>] "
         << "Enter <create> command to create map\n"
         << endl;
    cout << "[<!>] "
         << "Enter <help> command to guide you\n"
         << endl;
}
// -------------------------------------------------------
void App::createMap(){
    
}