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
        for (size_t j = 0; j < number_city; j++)
        {

            map.province[i].city[j].id;
            map.province[i].city[j].city_name;
            map.province[i].city[j].province_name;
            map.province[i].city[j].type;

            cout << "CREATE (";
        }
        
    }
}

tuple<int, string, string, string> App::parse_instruction(string create)
{
    for (size_t i = 0; i < 4; i++)
    {
        bool check = true;
        int j = 0;
        while (check)
        {
            if (create[j] == '\'')
            {
                
            }
            
        }
        //return make_tuple(id, Province, rt, func);
    }
    
}