#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in;
    string line, file_name;
    double sum;

    cout << "Please enter a file name: ";
    getline(cin, file_name);

    in.open(file_name);
    if (in.fail())
    {
        cout << "File didn't open" << endl;
        exit(-1);
    }

    while (1)
    {
        getline(in, line);
        if (in.fail())
            break;
        sum += stod(line);
    }
    cout << "The sum is " << sum << endl;

    return 0;
}