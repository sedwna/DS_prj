#include "Map.hpp"

class App
{
private:
public:
    App();
    Map myMap;

    tuple<string, int, string, string> parse_instruction(string creat);
    void splashScreen() const;
    void createMap();
    void show_info();
};