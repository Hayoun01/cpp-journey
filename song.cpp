#include <iostream>
#include <vector>
using namespace std;

struct song
{
    string title, artist;
    int length;
};

int main(void)
{
    vector<song> songs;
    song one;
    one.title = "Believer";
    one.artist = "Imagine Dragons";
    one.length = 207;
    songs.push_back(one);
    song two;
    two.title = "Alexander Hamilton";
    two.artist = "Original Broadway Cast";
    two.length = 237;
    songs.push_back(two);

    for (song i : songs)
        cout << i.title + " by " + i.artist + " is " << i.length << " seconds long.\n";
    return 0;
}