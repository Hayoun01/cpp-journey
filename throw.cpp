#include <iostream>

using namespace std;

int main()
{
    try
    {
        cout << "Please enter your age: ";
        int age;
        cin >> age;
        if (age >= 18)
        {
            cout << "You are old enough to vote." << endl;
        }
        else
        {
            // We can throw an int value to use in the catch
            throw age;
        }
        cout << "Are you registered to vote? (yes or no) ";
        string registered;
        cin >> registered;

        if (registered == "yes")
        {
            cout << "You can vote!" << endl;
        }
        else
        {
            cout << "You cannot vote. Please register soon!" << endl;
        }
    }
    // C++ looks for the int catch statement
    catch (int age)
    {
        cout << age << " isn't old enough to vote!" << endl;
    }

    return 0;
}