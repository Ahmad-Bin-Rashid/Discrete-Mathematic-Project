#include <iostream>
using namespace std;

long long RSA_Encrytion(long long base, long long exponent, long long mod)
{
    long long result = 1;
    base = base % mod;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }

        exponent /= 2;
        base = (base * base) % mod;
    }

    return result;
}

main()
{
    long long message, exponent, modulus;

    do
    {
        cout << endl;
        cout << "Enter the message (as a postive number): ";
        cin >> message;
        cout << "Enter the modulus n (where n=pq): ";
        cin >> modulus;
        cout << "Enter the public key exponent e (relatively prime to (p-1)(q-1)) : ";
        cin >> exponent;

        if (message <= 0 || modulus <= 0 || exponent <= 0)
        {
            cout << "Please enter positive integers.";
        }
    } while (message <= 0 || modulus <= 0 || exponent <= 0);

    cout << "Encrypted Message: "<< RSA_Encrytion(message, exponent, modulus) << endl;
}