#include <iostream>

using namespace std;

int main()
{
    string input;
    bool is_valid = false;
    while (!is_valid)
    {
        cout << "Please enter your age: ";
        getline(cin, input);
        try
        {
            int age = stoi(input);
            if (age < 2)
            {
                throw "Age invalid. Too young.";
            }
            else if (age > 110)
            {
                throw "Age invalid. Too old";
            }
            cout << "On your next birthday, you will be " << ++age << " years old.";
            is_valid = true;
        }
        catch (invalid_argument)
        {
            cout << "Please enter a valid number." << endl;
        }
        catch (const char *e)
        {
            cout << e << endl;
        }
    }
    return 0;
}