#include <iostream>
using namespace std;

int gcdCalculation (int num1, int num2)
{
    int x = num1, y = num2, r = 0;
    
    while (y != 0)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

main()
{
    int num1, num2;

    while (num1 <= 0 || num2 <= 0)
    {
        cout << endl;
        cout << "Enter first positive integer:";
        cin >> num1;
        cout << "Enter second positive integer:";
        cin >> num2;
    }
    cout << "The GCD of "<< num1 << " and "<< num2 << " is: " << gcdCalculation(num1, num2) << endl;
}

