#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct instruction
{
    string inst;
    int value;
    bool visited = 0;
};

void procFile(string fileName, vector<instruction> &instructions);
void run(vector<instruction> &instructions);

int main()
{
    vector<instruction> instructions;
    string file_name;
    cout << "Please enter your input file name (eg: filename.ext): ";
    cin >> file_name;
    procFile(file_name, instructions);
    run(instructions);

    return 0;
}

void procFile(string fileName, vector<instruction> &instructions)
{
    ifstream in;
    in.open(fileName);
    if (in.fail())
    {
        cout << "File Not Found!\n";
        exit(127);
    }

    while (1)
    {
        string line;
        string token;
        vector<string> inst;
        instruction item;

        getline(in, line);
        if (in.fail())
            break;
        istringstream stream(line);
        while (getline(stream, token, ' '))
            inst.push_back(token);
        item.inst = inst.at(0);
        item.value = stoi(inst.at(1));
        instructions.push_back(item);
    }
    in.close();
}

void run(vector<instruction> &instructions)
{
    for (int i = 0; 1; i++)
    {
        }
}