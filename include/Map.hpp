#include "Province.hpp"

class Map
{
private:
    int number_province;
    int number_city[SIZE_OF_PROVINCE];
    int bg_count = 0;

public:
    Province province[SIZE_OF_PROVINCE];
    tuple<string, int, string, string> parse_CreateMap_instruction(string creat);
    tuple<string, string, int, string, string> parse_CreateRoad_instruction(string creat);

    int found_city_id(string Province_, string City_);
    void createMap();
    void createRoad();
    int **create_foreign_matrix();
    void set_bg_count();
    int get_bg_count();
    const void show_foreign_matrix(int **foreign_matrix);
};
