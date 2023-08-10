#include "../include/Map.hpp"

void Map::createMap()
{

    bool greaterThan2 = false;
    bool greaterThan4 = false;
    int bg_count = 0;

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

    for (int i_p = 1; i_p <= number_province; i_p++)
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
            cout << province[i_p].city[i_c].city_name << endl;
            cout << province[i_p].city[i_c].id << endl;
            cout << province[i_p].city[i_c].type << endl;
            cout << province[i_p].city[i_c].province_name << endl;

            if (get<2>(instruction) == "BG")
            {
                set_bg_count();
            }
        }
        greaterThan4 = false;
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

    cout<<"2"<<endl;
    string line;
    cout<<"3"<<endl;
    int city_id_start;
    cout<<"4"<<endl;
    int city_id_end;
    cout<<"5"<<endl;
    int **foreign_matrix;
    cout<<"6"<<endl;
    foreign_matrix = create_foreign_matrix();
    cout<<"7"<<endl;

    do
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "enter cost of your road --> " ;
        getline(cin, line);
        auto instruction = parse_CreateRoad_instruction(line);
        city_id_start = found_city_id(get<1>(instruction), get<0>(instruction));
        city_id_end = found_city_id(get<4>(instruction), get<3>(instruction));

    } while (line != "-1");

    show_foreign_matrix(foreign_matrix);
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
    cout<<"8"<<endl;
    int **foreign_matrix = new int *[bg_count + 1];
    cout<<"9"<<endl;
    int temp[bg_count] = {-1};

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
                    }
                }
            }
        }
    }

    int i = 0;
    for (int j = 0; j < bg_count; j++)
    {
        foreign_matrix[i] = new int[bg_count];
        foreign_matrix[0][j + 1] = temp[j];
        i++;
    }
    i = 0;
    for (int j = 0; j < bg_count; j++)
    {
        foreign_matrix[i] = new int[bg_count];
        foreign_matrix[j + 1][0] = temp[j];
        i++;
    }
    
    show_foreign_matrix(foreign_matrix);
    return foreign_matrix;
}
void Map::show_foreign_matrix(int **foreign_matrix)
{

    for (size_t i = 0; i < bg_count; i++)
    {
        for (size_t j = 0; j < bg_count; j++)
        {
            cout << foreign_matrix[i][j] << " ";
        }
        cout << endl;
    }
}
