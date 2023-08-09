#include "../include/app.hpp"

// tuple<string, >
// -------------------------------------------------------
App::App()
{
    // splashScreen();
    createMap();
}
// -------------------------------------------------------
void App::splashScreen() const
{

    cout << "   |=|===================|=|      \n";
    cout << "   |=|                   |=|      \n";
    cout << "   |=|       Sapp        |=|      \n";
    cout << "   |                       |      \n";
    cout << "   |=======================|      \n";
    cout << "   |=======================|      \n";

    cout << endl;

    cout << "[<!>] "
         << "Enter <create> command to create map\n"
         << endl;
    cout << "[<!>] "
         << "Enter <help> command to guide you\n"
         << endl;
}
// -------------------------------------------------------
void App::createMap()
{

    int number_province;
    int number_city;
    bool greaterThan2 = false;
    bool greaterThan4 = false;

    while (!greaterThan2)
    {
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
            cout << "!!!your number should be greater than 4 -->  ";
            cin >> number_city;
            if (number_city > 4)
            {
                greaterThan4 = true;
            }
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i_c = 0; i_c < number_city; i_c++)
        {
            string line;
            getline(cin, line);

            auto instruction = parse_instruction(line);
            myMap.province[i_p].city[i_c].city_name = get<0>(instruction);
            myMap.province[i_p].city[i_c].id = get<1>(instruction);
            myMap.province[i_p].city[i_c].type = get<2>(instruction);
            myMap.province[i_p].city[i_c].province_name = get<3>(instruction);
            cout << myMap.province[i_p].city[i_c].city_name << endl;
            cout << myMap.province[i_p].city[i_c].id << endl;
            cout << myMap.province[i_p].city[i_c].type << endl;
            cout << myMap.province[i_p].city[i_c].province_name << endl;

            // string file_path = "input//input.txt"; // get input from file
            // ifstream input_file(file_path);

            // if (!input_file.is_open())
            // {
            //     cerr << "Error opening the file: " << file_path << endl;
            // }

            // string line;
            // while (getline(input_file, line))
            // {
            //     //cout << line << endl;
            //     cout << i_c << " " << i_p << endl;
            //     parse_instruction(line, i_p, i_c);
            // }

            // input_file.close(); // close file
        }
    }
}

tuple<string, int, string, string> App::parse_instruction(string create)
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
    cout << "complete parse" << endl;
    return make_tuple(city_name, id, type, province_name);
}