#include <iostream>
using namespace std;

string caesarCipher(string phrase, bool encrypt, int shift);
string encryption(string phrase, int shift);
string decryption(string phrase, int shift);
void upper(string &phrase);

int main(void)
{
    string phrase;
    char choice;
    int shift;

    cout << "Enter a phrase: ";
    getline(cin, phrase);
    cout << "Would you like to (e)ncrypt or (d)ecrypt? ";
    cin >> choice;
    cout << "How much would you like to shift (1-26)? ";
    cin >> shift;
    cout << caesarCipher(phrase, choice == 'e', shift) << endl;

    return 0;
}

string caesarCipher(string phrase, bool encrypt, int shift)
{
    if (!encrypt)
        return decryption(phrase, shift);
    return encryption(phrase, shift);
}
string encryption(string phrase, int shift)
{
    upper(phrase);
    for (int i = 0; i < phrase.length(); i++)
        if (phrase[i] > 64 && phrase[i] < 91)
            phrase[i] = 65 + ((phrase[i] + shift) % 65 % 26);
    return phrase;
}
string decryption(string phrase, int shift)
{
    for (int i = 0; i < phrase.length(); i++)
        if (phrase[i] > 64 && phrase[i] < 91)
        {
            phrase[i] = 65 + ((phrase[i] - 65 - shift + 26) % 26);
        }
    return phrase;
}

void upper(string &phrase)
{
    for (int i = 0; i < phrase.length(); i++)
        phrase.at(i) = toupper(phrase.at(i));
}