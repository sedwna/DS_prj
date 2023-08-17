#include <iostream>
#include <limits>
using namespace std;
#define SIZE_OF_CITY 10
// ------------------------------------------------------------------------------------------------------
class GPS
{
private:
    const int INF = numeric_limits<int>::max();

public:
    void Dijkstra_local(int adjacencyMatrix[SIZE_OF_CITY][SIZE_OF_CITY], int number_city, int start, int distances[]);
    void Dijkstra_foreign(int** adjacencyMatrix,int bg_count_);

    // در این حد فقط بدون که کمترین کاست رو میده تحویل میده
};
// ------------------------------------------------------------------------------------------------------