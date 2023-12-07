#include <iostream>
#include <cmath> // Used for the pow function

using namespace std;

/* In this program notice the order of the
 * objects. Since a line uses a point, point
 * needs to be defined first. Likewise, line
 * needs to be defined before the lineLength
 * function
 */

struct point
{
    int x, y;
};

struct line
{
    point p1, p2;
};

// This function will return the length of a line
double lineLength(line l)
{
    /* Formula for length of a line:
     * sqrt [(x2 - x1)^2 - (y2 - y1)^2]
     */
    double xSq = pow(l.p2.x - l.p1.x, 2); // pow(base, exponent)
    double ySq = pow(l.p2.y - l.p1.y, 2);
    return pow(xSq + ySq, 0.5);
}

point getPoint()
{
    point p;
    cout << "Please enter an X and Y coordinate seperated by a space: ";
    cin >> p.x >> p.y;
    return p;
}

int main()
{
    line l;
    l.p1 = getPoint();
    l.p2 = getPoint();

    cout << "The length of your line is ";
    cout << lineLength(l);

    return 0;
}