#include <iostream>
#include <bitset>
using namespace std;
void generate(int empKey, int compKey, int times);

int main(void)
{
    int empKey = 686;
    int compKey = 1248;
    int times;
    cout << "Enter the number of pairs to compare: ";
    cin >> times;
    generate(empKey, compKey, times);
    return 0;
}
void generate(int empKey, int compKey, int times)
{
    int matches = 0;
    for (int i = 0; i < times; i++)
    {
        empKey = empKey * 692 % 308947;
        compKey = compKey * 483 % 308947;
        bitset<32> empBin(empKey);
        bitset<32> compBin(compKey);
        if (empBin.to_string().substr(20) == compBin.to_string().substr(20))
            matches++;
    }
    cout << "Number of matches: " << matches << endl;
}
