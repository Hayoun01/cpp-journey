#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "WELCOME TO THE MYSTERIOUS MANOR!\n\n";

    int choice;

    cout << "You find yourself standing before an imposing manor, shrouded in mist and secrecy. Curiosity piqued, you decide to venture inside.\n";
    cout << "1. Ascend the grand staircase\n2. Enter the drawing room\n";
    cout << "Make a decision: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "The double doors swing open, revealing a grand entrance hall. A winding staircase leads upwards, while a doorway to the right beckons you towards the drawing room.\n";
        cout << "1. Explore the ballroom\n2. Return to the grand entrance hall\n";
        cout << "Make a decision: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "The ballroom is a vision of grandeur, with crystal chandeliers casting an ethereal glow upon the polished marble floor.\n";
            cout << "1. Venture into the secret passage\n2. Return to the ballroom\n";
            cout << "Make a decision: ";
            cin >> choice;

            if (choice == 1)
            {
                cout << "As you investigate the ballroom, you stumble upon a hidden doorway behind a tapestry. A narrow passage leads into the depths of the manor.\n";
                cout << "1. Investigate the artifacts\n2. Decipher the symbols\n";
                cout << "Make a decision: ";
                cin >> choice;

                if (choice == 1)
                {
                    cout << "As you examine the artifacts, you feel a surge of energy coursing through your veins. The symbols on the walls seem to glow with an otherworldly light.\n";
                    cout << "1. Embrace the power of the artifacts\n2. Fear the unknown energy\n";
                    cout << "Make a decision: ";
                    cin >> choice;

                    if (choice == 1)
                    {
                        cout << "You harness the power of the artifacts, becoming a master of arcane knowledge and wielding extraordinary abilities.\n";
                        cout << "Congratulations! You have reached the ending: The Rise of a Mystic.\n";
                    }
                    else
                    {
                        cout << "You fear the unknown energy, and your journey comes to an end.\n";
                    }
                }
                else
                {
                    cout << "You decipher the cryptic symbols, unlocking hidden passages and revealing the manor's true purpose.\n";
                    cout << "1. Unravel the manor's secrets\n2. Return to the hidden chamber\n";
                    cout << "Make a decision: ";
                    cin >> choice;
                    if (choice == 1)
                    {
                        cout << "You unravel the manor's secrets, but your journey comes to an end.\n";
                    }
                    else
                    {
                        cout << "You return to the hidden chamber.\n";
                    }
                }
            }
            else
            {
                cout << "You return to the opulent ballroom.\n";
            }
        }
        else
        {
            cout << "You return to the grand entrance hall.\n";
        }
    }
    else
    {
        cout << "You return to the imposing manor.\n";
    }

    return 0;
}
