#include <iostream>
using namespace std;

int gcdCalculation(int num1, int num2, int &s, int &t)
{
    int x = num1, y = num2, r, q, s1 = 1, s2 = 0, t1 = 0, t2 = 1;

    while (y != 0)
    {
        q = x / y;
        r = x % y;

        s = s1 - q * s2;
        t = t1 - q * t2;

        s1 = s2;
        s2 = s;
        t1 = t2;
        t2 = t;

        x = y;
        y = r;
    }

    s = s1;
    t = t1;

    return x;
}

int main()
{
    int num1, num2, s, t;

    do
    {
        cout << endl;
        cout << "Enter first positive integer: ";
        cin >> num1;
        cout << "Enter second positive integer: ";
        cin >> num2;

        if (num1 <= 0 || num2 <= 0)
        {
            cout << "Please enter positive integers.";
        }
    } while (num1 <= 0 || num2 <= 0);

    int gcd = gcdCalculation(num1, num2, s, t);

    cout << "The GCD of " << num1 << " and " << num2 << " is: " << gcd << endl;
    cout << "Bezout coefficients: s = " << s << ", t = " << t << endl;

    return 0;
}
