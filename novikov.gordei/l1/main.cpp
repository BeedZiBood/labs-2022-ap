#include <iostream>
#include "function.h"

using std::cin;
using std::cout;

int main()
{
    int numbOfPythagoreanTriples = 0;
    char buffer[250];
    long x, y, z, max1, max2;
    cin >> buffer;
    if (!(isNumberValid(buffer, x)))
    {
        cout << "The first element of the sequence is not a integer number\n";
        return 1;
    }
    if (x == 0)
    {
        cout << "The sequence is empty\n";
        return 1;
    }
    max1 = x;
    cin >> buffer;
    if (!isNumberValid(buffer, y))
    {
        cout << "The second element of the sequence is not a integer number\n";
        return 1;
    }
    if (y == 0)
    {
        cout << "The sequence contains less than 2 elements\n";
        return 1;
    }
    if (y >= max1)
    {
        max2 = max1;
        max1 = y;
    }
    else
        max2 = y;
    cin >> buffer;
    if (!isNumberValid(buffer, z))
    {
        cout << "The third element of the sequence is not a integer number\n";
        return 1;
    }
    if (z == 0)
    {
        cout << "The value of the second largest element is " << max2 << "\n";
        cout << "The sequence contains less than 3 elements\n";
        return 1;
    }
    while (z != 0)
    {
        if (z >= max1)
        {
            max2 = max1;
            max1 = z;
        }
        else if (z >= max2)
        {
            max2 = z;
        }
        if (isPythagoreanTriples(x, y, z)) numbOfPythagoreanTriples++;
        x = y;
        y = z;
        cin >> buffer;
        if (!isNumberValid(buffer, z))
        {
            cout << "The one of element of the sequence is not a integer number\n";
            return 1;
        }
    }
    cout << "The value of the second largest element is " << max2 << "\n";
    cout << "The number of Pythagorean triples is " << numbOfPythagoreanTriples << "\n";
    return 0;
}
