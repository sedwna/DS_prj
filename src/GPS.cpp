#include "../include/GPS.hpp"
// ------------------------------------------------------------------------------------------------------
void GPS::Dijkstra_local(int adjacencyMatrix[SIZE_OF_CITY][SIZE_OF_CITY], int number_city, int start, int distances[])
{
    bool visited[number_city];
    for (int i = 1; i <= number_city; ++i) // <=  corrct to : <
    {
        distances[i] = INF;
        visited[i] = false;
    }

    distances[start] = 0;

    for (int count = 0; count < number_city - 1; ++count)
    {
        int u = -1;
        for (int i = 1; i <= number_city; ++i)
        {
            if (!visited[i] && (u == -1 || distances[i] < distances[u]))
                u = i;
        }

        visited[u] = true;

        for (int v = 1; v <= number_city; ++v)
        {
            if (!visited[v] && adjacencyMatrix[u][v] && distances[u] != INF &&
                distances[u] + adjacencyMatrix[u][v] < distances[v])
            {
                distances[v] = distances[u] + adjacencyMatrix[u][v];
            }
        }
    }
}
// ------------------------------------------------------------------------------------------------------
void GPS::Dijkstra_foreign(int **adjacencyMatrix, int bg_count_)
{
    int distances[bg_count_];
    bool visited[bg_count_];
    for (int i = 1; i <= bg_count_; ++i) // <=  corrct to : <
    {
        distances[i] = INF;
        visited[i] = false;
    }

    
    for (int m = 1; m < bg_count_; m++)
    {
        distances[m] = 0;
        for (int count = 0; count < bg_count_ - 1; ++count)
        {
            int u = -1;
            for (int i = 1; i <= bg_count_; ++i)
            {
                if (!visited[i] && (u == -1 || distances[i] < distances[u]))
                    u = i;
            }

            visited[u] = true;

            for (int v = 1; v <= bg_count_; ++v)
            {
                if (!visited[v] && adjacencyMatrix[u][v] && distances[u] != INF &&
                    distances[u] + adjacencyMatrix[u][v] < distances[v])
                {
                    distances[v] = distances[u] + adjacencyMatrix[u][v];
                }
            }
        }
    }
}
