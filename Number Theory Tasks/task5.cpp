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

int modInverse(int num1, int num2)
{
    int s, t;
    int gcd = gcdCalculation(num1, num2, s, t);
    int inverse;

    if (gcd != 1)
    {
        return 0;
    }
    else
    {
        if (((s*num1) + num2) % num2 == 1)
        {
            inverse = s;
        }
        else
        {
            inverse = t;
        }

        return inverse;
    }
}

int main()
{
    int num1, num2;

    do
    {
        cout << endl;
        cout << "Enter first positive integer: ";
        cin >> num1;
        cout << "Enter second positive integer: ";
        cin >> num2;

        if (num1 <= 0 || num2 <= 0) {
            cout << "Please enter positive integers.";
        }
    } while (num1 <= 0 || num2 <= 0);

    int inverse = modInverse(num1, num2);

    if (inverse != 0)
    {
        cout << "The modular inverse of " << num1 << " modulo " << num2 << " is: " << inverse << endl;
    }
    else if (inverse == 0)
    {
        cout << "The modular inverse does not exist." << endl;
    }

    return 0;
}
