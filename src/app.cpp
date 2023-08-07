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
void App::createMap()
{

    int number_province;
    int number_city;
    bool greaterThan2 = false;
    bool greaterThan4 = false;

    while (!greaterThan2)
    {
        cout << "!!!your number should be greater than 2 -->  ";
        cin >> number_province;
        if (number_province >= 3)
        {
            greaterThan2 = true;
        }
    }

    for (size_t i = 0; i < number_province; i++)
    {
        
        while (!greaterThan4)
        {
            cout << "!!!your number should be greater than 4 -->  ";
            cin >> number_city;
            if (number_province >= 5)
            {
                greaterThan4 = true;
            }
        }
        string name;
        for (size_t j = 0; j < number_city; j++)
        {
            
            cout << "CREATE (";
            cin >> name;
        }
        
    }
}