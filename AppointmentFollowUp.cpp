#include <iostream>
#include <vector>
using namespace std;

string takeAppointment(vector<string> days, int selectedDay, int daysToAdd = 7);

int main(void)
{
    string appointment;
    int i = 1, day;
    vector<string> days{
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"};

    cout << "Hello world!" << endl;
    cout << "What type of appointment do you have? ";
    getline(cin, appointment);
    cout << "Which day is your appointment?\n";
    for (string day : days)
    {
        cout << i++ << ": " << day + "\n";
    }
    cout << "> ";
    cin >> day;
    cout << "Your follow up will be on a ";
    if (appointment == "Oncologist")
        cout << takeAppointment(days, day, 2) << endl;
    else if (appointment == "Orthodontist")
        cout << takeAppointment(days, day, 10) << endl;
    else
        cout << takeAppointment(days, day, 7) << endl;

    return 0;
}
string takeAppointment(vector<string> days, int selectedDay, int daysToAdd)
{
    int index = (daysToAdd + selectedDay - 1) % 7;
    return days[index];
}