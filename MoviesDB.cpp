#include <iostream>
#include <vector>

using namespace std;

struct MovieDB
{
    string title, actor;
    int year;
    double rating;
};

void addMovies(vector<MovieDB> &movies);
void listMovies(vector<MovieDB> &movies);

int main(void)
{
    char choice;
    vector<MovieDB> movies;

    while (1)
    {
        cout << "Would you like to (a)dd a movie, (l)ist movies, or (e)xit? ";
        cin >> choice;
        choice = tolower(choice);
        cin.ignore();
        if (choice == 'a')
            addMovies(movies);
        else if (choice == 'l')
            listMovies(movies);
        else
            break;
    }
    return 0;
}

void addMovies(vector<MovieDB> &movies)
{
    MovieDB movie;
    cout << "Please enter the title: ";
    getline(cin, movie.title);
    cout << "Please enter an actor(Last, First): ";
    getline(cin, movie.actor);
    cout << "Please enter the year: ";
    cin >> movie.year;
    cout << "Please enter the rating (1-10): ";
    cin >> movie.rating;
    movies.push_back(movie);
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
}