#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct MovieDB
{
    string title, actor;
    int year;
    double rating;
};

void addMovies(vector<MovieDB> &movies);
void listMovies(vector<MovieDB> &movies);
vector<string> splitStr(string str, char delimiter = ';');
void searchMovies(vector<MovieDB> &movies);
void searchEngine(
    vector<MovieDB> &movies,
    vector<MovieDB> &results,
    string by,
    string query = "",
    int first_year = 0,
    int second_year = 0);

int main(void)
{
    char choice;
    vector<MovieDB> movies;
    addMovies(movies);

    while (1)
    {
        cout << "Would you like to (s)earch, (l)ist movies, or (e)xit? ";
        cin >> choice;
        choice = tolower(choice);
        cin.ignore();
        if (choice == 'l')
            listMovies(movies);
        else if (choice == 's')
            searchMovies(movies);
        else
            break;
    }
    return 0;
}

void addMovies(vector<MovieDB> &movies)
{
    MovieDB movie;
    ifstream in;
    string line;

    in.open("movies.txt");
    if (in.fail())
    {
        cout << "Files Not Found.\n";
        exit(127);
    }
    while (1)
    {
        getline(in, line);
        if (in.fail())
            break;
        vector<string> get_movie = splitStr(line);
        movie.title = get_movie.at(0);
        movie.year = stoi(get_movie.at(1));
        movie.actor = get_movie.at(2);
        movie.rating = stod(get_movie.at(3));
        movies.push_back(movie);
    }
}

void listMovies(vector<MovieDB> &movies)
{
    for (MovieDB movie : movies)
    {
        cout << "Title: " << movie.title << endl;
        cout << "Year: " << movie.year << endl;
        cout << "Actor: " << movie.actor << endl;
        cout << "Rating: " << movie.rating << endl;
        cout << endl;
    }
    cout << "Total Count: " << movies.size() << endl;
}

vector<string> splitStr(string str, char delimiter)
{
    vector<string> output;
    istringstream stream(str);
    string tmp;

    while (getline(stream, tmp, delimiter))
        output.push_back(tmp);
    return output;
}

void searchMovies(vector<MovieDB> &movies)
{
    string choice;
    string query;
    int to;
    bool is_valid = false;
    vector<MovieDB> results;
    cout << "Search menu:\n\
1. Search by Title\n\
2. Search by Year\n\
3. Search by Actor\n\
4. Search by Rating\n";
    while (!is_valid)
    {
        cout << "Enter option: ";
        getline(cin, choice);
        try
        {
            to = stoi(choice);
            if (to < 1 || to > 4)
                throw "Please enter a number between 1 and 4.";
            is_valid = true;
            if (to == 1)
            {
                cout << "Please enter a title to search for: ";
                getline(cin, query);
                searchEngine(movies, results, "title", query);
            }
            else if (to == 2)
            {
                int first_year;
                int second_year;
                cout << "Please enter the starting year to search: ";
                cin >> first_year;
                cout << "Please enter the ending year to search: ";
                cin >> second_year;
                if (first_year < 1950 || second_year > 2016 || first_year > second_year)
                    throw "Please enter a valid years.";
                searchEngine(movies, results, "year", "", first_year, second_year);
            }
            else if (to == 3)
            {
                cout << "Please enter a rating to search for: ";
                getline(cin, query);
                searchEngine(movies, results, "actor", query);
            }
            else if (to == 4)
            {
                cout << "Please enter a rating to search for: ";
                cin >> query;
                if (stod(query) > 10 || stod(query) < 1)
                    throw "Please enter a number between 1 and 10.";
                searchEngine(movies, results, "rating", query);
            }
            listMovies(results);
        }
        catch (invalid_argument)
        {
            cout << "Not a valid number. Please try again.\n";
        }
        catch (const char *e)
        {
            cout << e << endl;
        }
    }
}

void searchEngine(vector<MovieDB> &movies, vector<MovieDB> &results, string by, string query, int first_year, int second_year)
{
    for (MovieDB movie : movies)
        if (by == "year" && movie.year >= first_year && movie.year <= second_year ||
            by == "rating" && movie.rating == stod(query) ||
            by == "title" && movie.title.find(query) != string::npos ||
            by == "actor" && movie.actor.find(query) != string::npos)
            results.push_back(movie);
}