#include "City.hpp"
#define SIZE_OF_PROVINCE 10

class Province
{

public:
    City city[SIZE_OF_PROVINCE];
    vector<vector<int>> cost_city();
    void create_local_matrix(int count_of_city);

};
