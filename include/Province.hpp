#include "City.hpp"
#define SIZE_OF_PROVINCE 10
#define SIZE_OF_CITY 10
// ------------------------------------------------------------------------------------------------------
class Province
{
public:
    City city[SIZE_OF_PROVINCE];
    int local_matrix[SIZE_OF_CITY][SIZE_OF_CITY];
    int copy_of_local_matrix[SIZE_OF_CITY][SIZE_OF_CITY];
    void get_local_matrix();
    void set_local_matrix(int i, int j, int value);
};
// ------------------------------------------------------------------------------------------------------
