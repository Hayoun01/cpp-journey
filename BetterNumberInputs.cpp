#include <iostream>
using namespace std;

double inputDouble(string prompt);
double inputDouble(string prompt, double min, double max, string reprompt = "Please try again: ");
int inputInt(string prompt);
int inputInt(string prompt, int min, int max, string reprompt = "Please try again: ");

int main(void)
{
    double num;
    int i;
    num = inputDouble("Please enter a double between 0 and 1: ", 0, 1);
    cout << "You entered: " << num << endl;
    i = inputInt("Please enter an int between 0 and 10: ", 0, 10);
    cout << "You entered: " << i << endl;
    return 0;
}
double inputDouble(string prompt)
{
    double userDouble;
    cout << prompt;
    cin >> userDouble;
    return userDouble;
}
double inputDouble(string prompt, double min, double max, string reprompt)
{
    double userDouble;
    userDouble = inputDouble(prompt);
    while (userDouble <= min || userDouble >= max)
        userDouble = inputDouble(reprompt);

    return userDouble;
}
int inputInt(string prompt)
{
    int userInt;
    cout << prompt;
    cin >> userInt;
    return userInt;
}
int inputInt(string prompt, int min, int max, string reprompt)
{
    double userInt;
    userInt = inputInt(prompt);
    while (userInt <= min || userInt >= max)
        userInt = inputInt(reprompt);
    return userInt;
}
