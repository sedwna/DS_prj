#include "../include/GPS.hpp"

void GPS::Dijkstra(int adjacencyMatrix[SIZE_OF_CITY][SIZE_OF_CITY], int number_city, int start, int distances[])
{
    bool visited[number_city];
    for (int i = 1; i <= number_city; ++i)
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