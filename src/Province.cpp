#include "../include/Province.hpp"
const int INF = numeric_limits<int>::max();
// ------------------------------------------------------------------------------------------------------
void Province::set_local_matrix(int i, int j, int value)
{

    local_matrix[i][j] = value;
    copy_of_local_matrix[i][j] = value;
}
// ------------------------------------------------------------------------------------------------------
void Province::get_local_matrix()
{
    cout << endl;
    for (int i = 0; i < SIZE_OF_CITY; i++)
    {
        for (int j = 0; j < SIZE_OF_CITY; j++)
        {

            cout << left << setfill(' ') << setw(5) << local_matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
// ------------------------------------------------------------------------------------------------------