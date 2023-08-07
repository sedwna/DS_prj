#pragma once
#include "City.hpp"

using namespace std;

class province
{

public:
    vector<City> city;
    vector<vector<int>> cost_city();
};
