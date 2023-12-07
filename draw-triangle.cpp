#include <iostream>
using namespace std;

void promptUser(int *choice);
void drawTriangle(int size);
void printSpace(int times);
void printStar(int *times);

int main(void)
{
    int choice;
    promptUser(&choice);
    drawTriangle(choice);
    return 0;
}

void promptUser(int *choice)
{
    do
    {
        cout << "Please enter the size of your triangle: ";
        cin >> *choice;
    } while (*choice > 10);
}
void drawTriangle(int size)
{
    int starSize = 1;
    for (int i = 1; i <= size; i++)
    {
        printSpace(size - i);
        printStar(&starSize);
        cout << '\n';
    }
}
void printSpace(int times)
{
    for (int i = 0; i < times; i++)
        cout << " ";
}
void printStar(int *times)
{
    for (int i = 0; i < *times; i++)
        cout << "*";
    *times += 2;
}