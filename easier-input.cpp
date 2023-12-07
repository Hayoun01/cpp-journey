#include <iostream>
using namespace std;

string inputLine(string prompt);
double inputDouble(string prompt);
double inputDouble(string prompt, double min, double max);
int inputInt(string prompt);
int inputInt(string prompt, int min, int max);

int main(void)
{
    double num;
    int i;
    cout << "You entered: " + inputLine("Please enter a string: ") << endl;
    num = inputDouble("Please enter a double: ");
    cout << "You entered: " << num << endl;
    num = inputDouble("Please enter a double between 0 and 1: ", 0, 1);
    cout << "You entered: " << num << endl;
    i = inputInt("Please enter an int: ");
    cout << "You entered: " << i << endl;
    i = inputInt("Please enter an int between 0 and 10: ", 0, 10);
    cout << "You entered: " << i << endl;
    return 0;
}
string inputLine(string prompt)
{
    cout << prompt;
    getline(cin, prompt);
    return prompt;
}
double inputDouble(string prompt)
{
    double userDouble;
    cout << prompt;
    cin >> userDouble;
    return userDouble;
}
double inputDouble(string prompt, double min, double max)
{
    double userDouble;
    do
    {
        userDouble = inputDouble(prompt);
    } while (userDouble < min || userDouble > max);
    return userDouble;
}
int inputInt(string prompt)
{
    int userInt;
    cout << prompt;
    cin >> userInt;
    return userInt;
}
int inputInt(string prompt, int min, int max)
{
    double userInt;
    do
    {
        userInt = inputInt(prompt);
    } while (userInt < min || userInt > max);
    return userInt;
}
