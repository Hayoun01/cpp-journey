#include <iostream>

using namespace std;

void order(string protein, string rice = "white", string beans = "Black", string salsa = "mild");

int main()
{
    order("chicken");
    order("steak", "white", "refried", "hot");
    order("steak", "white", "refried", "hot");
    order("veggie", "brown");
    return 0;
}
void order(string protein, string rice, string beans, string salsa)
{
    // Your Burrito Bowl:
    // A chicken burrito with white rice, black beans, and mild salsa.
    cout << "Your Burrito Bowl:" << endl;
    cout << "A " + protein + " burrito with " + rice + " rice, " + beans + " beans, and " + salsa + " salsa." << endl;
}