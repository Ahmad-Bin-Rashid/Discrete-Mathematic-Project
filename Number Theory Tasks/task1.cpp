#include <iostream>
using namespace std;

void primeFactorization(int n)
{
    while (n % 2 == 0) 
    {
        cout << 2 << " ";
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) 
    {
        while (n % i == 0) 
        {
            cout << i << " ";
            n /= i;
        }
    }

    if (n > 2) 
    {
        cout << n;
    }
    cout << endl;
}

int main()
{
    int number = 0;
    
    cout << endl;
    // Get the number from the user until he enters the positive number.
    while (number <= 0) 
    {
        cout << "Please enter a positive integer:";
        cin >> number;
    }

    // Find and output the prime factorization
    cout << "Prime Factorization: ";
    primeFactorization(number);

    return 0;
}
