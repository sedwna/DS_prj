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
        for (int i_c = 0; i_c < number_city; i_c++)
        {
            string file_path = "input//input.txt"; // get input from file
            ifstream input_file(file_path);

            if (!input_file.is_open())
            {
                cerr << "Error opening the file: " << file_path << endl;
            }

            string line;
            while (getline(input_file, line))
            {
                // cout << line << endl;
                cout << i_c << " " << i_p << endl;
                parse_instruction(line, i_p, i_c);
            }

            input_file.close(); // close file
        }
    }
}

tuple<int, string, string, string> App::parse_instruction(string create, int number_province, int number_city)
{

    vector<string> tokens;

    stringstream check1(create);

    string intermediate;

    // Tokenizing input
    getline(check1, intermediate, '(');  // delete useless info
    getline(check1, intermediate, ':');  // get city name
    tokens.push_back(intermediate);      // push city name
    getline(check1, intermediate, '\''); // delete useless info
    getline(check1, intermediate, '\''); // get id
    tokens.push_back(intermediate);      // push id
    getline(check1, intermediate, '\''); // delete useless info
    getline(check1, intermediate, '\''); // get BG or  NBG
    tokens.push_back(intermediate);      // //p[ush BG or NBG]
    getline(check1, intermediate, ' ');  // delete useless info
    getline(check1, intermediate, ':');  // get province name
    tokens.push_back(intermediate);      // get province name

    for (int i = 0; i < tokens.size(); i++)
    {
        cout << tokens[i] << '\n';
    } // check parse is correct
    // myMap.province[0].city[0].city_name = "Qom";
    // return make_tuple();
    // show_info();
}

void App ::show_info()
{

    cout << "slmm" << endl;
    cout << myMap.province[0].city[0].city_name << endl;
    cout << myMap.province[0].city[0].id << endl;
    cout << myMap.province[0].city[0].type << endl;
    cout << myMap.province[0].city[0].province_name << endl;
}