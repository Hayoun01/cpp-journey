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

int main(void)
{
    char choice;
    vector<MovieDB> movies;
    addMovies(movies);

    while (1)
    {
        cout << "Would you like to (l)ist movies, or (e)xit? ";
        cin >> choice;
        choice = tolower(choice);
        cin.ignore();
        if (choice == 'l')
            listMovies(movies);
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
    int count = 0;

    for (MovieDB movie : movies)
    {
        cout << "Title: " << movie.title << endl;
        cout << "Year: " << movie.year << endl;
        cout << "Actor: " << movie.actor << endl;
        cout << "Rating: " << movie.rating << endl;
        cout << endl;
        count++;
    }
    cout << "Total Count: " << count << endl;
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