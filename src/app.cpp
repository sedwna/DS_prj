#include "../include/app.hpp"
// ------------------------------------------------------------------------------------------------------
App::App()
{
     int **foreign_matrix;

     // splashScreen();

     myMap.createMap();

     foreign_matrix = myMap.createRoad();
     myMap.set_min_cost_local_matrix();
     myMap.set_min_cost_foreign_matrix(foreign_matrix);

     myMap.show_foreign_matrix(foreign_matrix);
     myMap.show_local_matrix();

     myMap.find_route_taken(foreign_matrix);
     
     cout << endl;
}
// ------------------------------------------------------------------------------------------------------
void App::splashScreen() const
{

     cout << "   |=|===================|=|      \n";
     cout << "   |=|                   |=|      \n";
     cout << "   |=|       Sapp        |=|      \n";
     cout << "   |                       |      \n";
     cout << "   |=======================|      \n";
     cout << "   |=======================|      \n";

     cout << endl;
}
// ------------------------------------------------------------------------------------------------------
