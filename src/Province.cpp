#include "../include/Province.hpp"

void Province::set_local_matrix(int i, int j, int value)
{

    local_matrix[i][j] = value;
}
void Province::get_local_matrix()
{
    cout << endl;
    for (int i = 0; i < SIZE_OF_CITY; i++)
    {
        for (int j = 0; j < SIZE_OF_CITY; j++)
        {
            cout << local_matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}