#include "Province.hpp"
#include "GPS.hpp"
// ------------------------------------------------------------------------------------------------------
class Map
{
private:
    int number_province;
    int number_city[SIZE_OF_PROVINCE];
    int bg_count = 0;

public:
    GPS gps;// شی از GPS
    Province province[SIZE_OF_PROVINCE];
    tuple<string, int, string, string> parse_CreateMap_instruction(string creat);
    tuple<string, string, int, string, string> parse_CreateRoad_instruction(string creat);

    int found_city_id(string Province_, string City_);
    void createMap();
    int** createRoad();
    int **create_foreign_matrix();
    void set_bg_count();
    int get_bg_count();
    const void show_foreign_matrix(int **foreign_matrix);
    void create_local_matrix();
    void set_bg_id_foreign_matrix(int **foreign_matrix,int temp[]);
    void set_node_id_local_matrix(int i_c, int i_p);
    const void show_local_matrix();
    const void set_cost_foreign_matrix(auto instruction,int **foreign_matrix,int city_id_start,int city_id_end);
    const void set_cost_local_matrix(auto instruction, int **foreign_matrix, int city_id_start, int city_id_end);
    const void set_min_cost_local_matrix();
    const void set_min_cost_foreign_matrix(int **foreign_matrix);
};
// ------------------------------------------------------------------------------------------------------