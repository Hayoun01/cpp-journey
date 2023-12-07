#include <iostream>
#include <vector>

using namespace std;

double getAvg(vector<int> grades);
double calculate(double avg, int quarters, double desiredAvg);

int main()
{
    vector<int> grades;
    double avg, grade;

    while (1)
    {
        cout << "Please enter your quarterly grade (-1 when finished): ";
        cin >> avg;
        if (avg < 0)
            break;
        grades.push_back(avg);
    }
    avg = getAvg(grades);
    if ((grade = calculate(avg, 4 - grades.size(), 90)) < 100)
    {
        cout << "To get an A for the year, you will need to average: " << grade << endl;
        grade = calculate(avg, 4 - grades.size(), 80);
        cout << "To get an B for the year, you will need to average: " << grade << endl;
    }
    else if ((grade = calculate(avg, 4 - grades.size(), 80)) < 100)
    {
        cout << "To get an B for the year, you will need to average: " << grade << endl;
        grade = calculate(avg, 4 - grades.size(), 70);
        cout << "To get an C for the year, you will need to average: " << grade << endl;
    }
    else if ((grade = calculate(avg, 4 - grades.size(), 70)) < 100)
    {
        cout << "To get an C for the year, you will need to average: " << grade << endl;
        grade = calculate(avg, 4 - grades.size(), 60);
        cout << "To get an D for the year, you will need to average: " << grade << endl;
    }
    else if ((grade = calculate(avg, 4 - grades.size(), 60)) < 100)
    {
        cout << "To get an D for the year, you will need to average: " << grade << endl;
    }
    return 0;
}
double getAvg(vector<int> grades)
{
    double sum = 0;
    for (int i : grades)
        sum += i;
    return sum / grades.size();
}
double calculate(double avg, int quarters, double desiredAvg)
{
    return (desiredAvg * 4 - avg * (4 - quarters)) / quarters;
}