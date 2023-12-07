#include <iostream>
using namespace std;

void test()
{
    static int i = 0;
    i++;
    cout << i << endl;
}

int main(void)
{
    for (int i; i < 10; i++)
        test();
    return 0;
}