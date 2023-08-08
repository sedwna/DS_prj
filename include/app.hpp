#include "Map.hpp"

class App
{
private:
public:
    App();
    Map map;
    tuple<int, string, string, string> parse_instruction(string creat, int number_province, int number_city);
    void splashScreen() const;
    void createMap();
};