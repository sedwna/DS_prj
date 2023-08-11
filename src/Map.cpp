#include "../include/Map.hpp"

void Map::createMap()
{

    bool greaterThan2 = false;
    bool greaterThan4 = false;
    int bg_count = 0;
    // set 0 in the local matrix
    for (size_t i = 0; i < number_province; i++)
    {
        for (size_t j = 0; j < SIZE_OF_CITY; j++)
        {
            for (size_t k = 0; k < SIZE_OF_CITY; k++)
            {
                province[i].set_local_matrix(j, k, 0);
            }
        }
    }

    while (!greaterThan2)
    {
        cout << " number of province  " << endl;
        cout << "!!!your number should be greater than 2 -->  ";
        cin >> number_province;
        if (number_province > 2)
        {
            greaterThan2 = true;
        }
    }

    for (int i_p = 0; i_p < number_province; i_p++)
    {

        while (!greaterThan4)
        {
            cout << "number of city in province " << i_p << endl;
            cout << "!!!your number should be greater than 4 -->  ";
            cin >> number_city[i_p];
            cout << endl
                 << "enter  " << number_city[i_p] << "  cities -->";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (number_city[i_p] > 4)
            {
                greaterThan4 = true;
            }
        }

        for (int i_c = 0; i_c < number_city[i_p]; i_c++)
        {
            string line;
            getline(cin, line);

            auto instruction = parse_CreateMap_instruction(line);
            province[i_p].city[i_c].city_name = get<0>(instruction);
            province[i_p].city[i_c].id = get<1>(instruction);
            province[i_p].city[i_c].type = get<2>(instruction);
            province[i_p].city[i_c].province_name = get<3>(instruction);
            // cout << province[i_p].city[i_c].city_name << endl;
            // cout << province[i_p].city[i_c].id << endl;
            // cout << province[i_p].city[i_c].type << endl;
            // cout << province[i_p].city[i_c].province_name << endl;

            if (get<2>(instruction) == "BG")
            {
                set_bg_count();
            }
            // set id in local matrix
            province[i_p].set_local_matrix(0, i_c + 1, province[i_p].city[i_c].id);
            province[i_p].set_local_matrix(i_c + 1, 0, province[i_p].city[i_c].id);
        }
        greaterThan4 = false;
    }
    for (size_t i = 0; i < number_province; i++)
    {
        cout << endl
             << " show local matrix " << endl;

        province[i].get_local_matrix();

        cout << endl;
    }
}

tuple<string, int, string, string> Map::parse_CreateMap_instruction(string create)
{

    string province_name;
    string city_name;
    string type;
    int id;
    stringstream check1(create);
    string intermediate;

    // Tokenizing input
    getline(check1, intermediate, '(');  // delete useless info
    getline(check1, intermediate, ':');  // get city name
    city_name = intermediate;            // push city name
    getline(check1, intermediate, '\''); // delete useless info
    getline(check1, intermediate, '\''); // get id
    id = stoi(intermediate);             // push id
    getline(check1, intermediate, '\''); // delete useless info
    getline(check1, intermediate, '\''); // get BG or  NBG
    type = intermediate;                 // //p[ush BG or NBG]
    getline(check1, intermediate, ' ');  // delete useless info
    getline(check1, intermediate, ':');  // get province name
    province_name = intermediate;        // get province name
    // cout << "complete parse" << endl;
    return make_tuple(city_name, id, type, province_name);
}

tuple<string, string, int, string, string> Map::parse_CreateRoad_instruction(string road)
{

    string start_city;
    string end_city;
    string start_province;
    string end_province;
    int cost;

    stringstream check1(road);
    string intermediate;

    // CREATE (A.Qom) – [:ROAD {cost:50}] –> (K.Tabriz)

    // Tokenizing input
    getline(check1, intermediate, '('); // delete useless info
    getline(check1, intermediate, '.'); // get start_city name
    start_city = intermediate;          // push start_city name
    getline(check1, intermediate, ')'); // get start_province name
    start_province = intermediate;      // push start_province name
    getline(check1, intermediate, ':'); // delete useless info
    getline(check1, intermediate, ':'); // delete useless info
    getline(check1, intermediate, '}'); // get cost
    cost = stoi(intermediate);          // push cost
    getline(check1, intermediate, '('); // delete useless info
    getline(check1, intermediate, '.'); // get end_city name
    end_city = intermediate;            // push end_city name
    getline(check1, intermediate, ')'); // get end_province name
    end_province = intermediate;        // push end_province name
    return make_tuple(start_city, start_province, cost, end_city, end_province);
}

void Map::createRoad()
{

    string line;
    int city_id_start;
    int city_id_end;
    int **foreign_matrix;

    foreign_matrix = create_foreign_matrix();
    // ------------------------------------

    cout << "enter cost of your road --> ";
    getline(cin, line);
    while (line != "-1")
    {

        auto instruction = parse_CreateRoad_instruction(line);
        city_id_start = found_city_id(get<1>(instruction), get<0>(instruction));
        city_id_end = found_city_id(get<4>(instruction), get<3>(instruction));
        // cout << "city_id_end  " << city_id_end << endl;
        // cout << "city_id_start  " << city_id_start << endl;
        if (get<1>(instruction) != get<4>(instruction))
        {
            int temp1 = 0;
            int temp2 = 0;
            for (int j = 0; j < bg_count; j++)
            {
                if (foreign_matrix[0][j + 1] == city_id_start)
                {
                    temp1 = j + 1;
                    break;
                }
            }
            for (int j = 0; j < bg_count; j++)
            {
                if (foreign_matrix[j + 1][0] == city_id_end)
                {
                    temp2 = j + 1;
                    break;
                }
            }
            foreign_matrix[temp2][temp1] = get<2>(instruction);
        }
        else if (get<1>(instruction) == get<4>(instruction))
        {
            for (size_t i = 0; i < number_province; i++)
            {

                if (province[i].city[0].province_name == get<1>(instruction))
                {
                    int temp1 = 0;
                    int temp2 = 0;
                    for (int j = 0; j < SIZE_OF_CITY; j++)
                    {
                        if (province[i].local_matrix[0][j + 1] == city_id_start)
                        {
                            temp1 = j + 1;
                            break;
                        }
                    }
                    for (int j = 0; j < SIZE_OF_CITY; j++)
                    {
                        if (province[i].local_matrix[j + 1][0] == city_id_end)
                        {
                            temp2 = j + 1;
                            break;
                        }
                    }
                    province[i].local_matrix[temp2][temp1] = get<2>(instruction);
                }
            }
        }

        cout << "enter cost of your road --> ";
        getline(cin, line);
    }

    show_foreign_matrix(foreign_matrix);
    for (size_t i = 0; i < number_province; i++)
    {
        cout << endl
             << " show local matrix " << endl;

        province[i].get_local_matrix();

        cout << endl;
    }
}

int Map::found_city_id(string Province_, string City_)
{

    for (size_t i = 0; i < number_province; i++)
    {
        for (size_t j = 0; j < number_city[i]; j++)
        {
            if (province[i].city[j].city_name == City_ && province[i].city[j].province_name == Province_)
            {
                return province[i].city[j].id;
            }
        }
    }
}
void Map::set_bg_count()
{
    bg_count++;
}
int Map::get_bg_count()
{
    return bg_count;
}
int **Map::create_foreign_matrix()
{

    int **foreign_matrix = new int *[bg_count + 1];
    for (int i = 0; i < bg_count + 1; ++i)
    {
        foreign_matrix[i] = new int[bg_count + 1];
        for (int j = 0; j < bg_count + 1; ++j)
        {
            foreign_matrix[i][j] = 0;
        }
    }
    // show_foreign_matrix(foreign_matrix);

    int temp[bg_count];

    for (int i = 0; i < bg_count; i++)
    {
        temp[i] = -1;
    }
    // cout << "bg count :" << bg_count << endl;
    // cout << "number_province " << number_province << endl;
    // cout << "number_city 0, " << number_city[0] << endl;
    // cout << "number_city 1, " << number_city[1] << endl;
    // cout << "number_city 2, " << number_city[2] << endl;
    // cout << "number_city 3, " << number_city[3] << endl;

    for (int i = 0; i < number_province; i++)
    {

        for (int j = 0; j < number_city[i]; j++)
        {

            if (province[i].city[j].type == "BG")
            {

                for (int k = 0; k < bg_count; k++)
                {

                    if (temp[k] == -1)
                    {
                        temp[k] = province[i].city[j].id;
                        break;
                    }
                }
            }
        }
    }

    // cout << "id bg" << endl;
    // for (size_t i = 0; i < bg_count; i++)
    // {
    //     cout << temp[i] << " ";
    // }

    cout << endl;
    // set id bg city in matrix
    for (int j = 0; j < bg_count; j++)
    {
        foreign_matrix[0][j + 1] = temp[j];
        foreign_matrix[j + 1][0] = temp[j];
    }

    show_foreign_matrix(foreign_matrix);

    return foreign_matrix;
}
const void Map::show_foreign_matrix(int **foreign_matrix)
{
    cout << endl
         << "show foreign matrix" << endl;

    for (int i = 0; i < bg_count + 1; ++i)
    {
        for (int j = 0; j < bg_count + 1; ++j)
        {
            cout << foreign_matrix[i][j] << " ";
        }
        cout << endl;
    }
}
