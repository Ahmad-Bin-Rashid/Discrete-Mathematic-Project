#include <iostream>
using namespace std;

long long modInverse(long long num1, long long num2)
{
    long long x = num1, y = num2, inverse, r, q, s, t, s1 = 1, s2 = 0, t1 = 0, t2 = 1;

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

long long RSA_Decryption(long long base, long long exponent, long long mod)
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
    long long message, p, q, mod, e, phi, key;

    do
    {
        cout << endl;
        cout << "Enter the Encrypted message (positve integer): ";
        cin >> message;
        cout << "Enter the odd prime 'p': ";
        cin >> p;
        cout << "Enter the odd prime 'q': ";
        cin >> q;
        cout << "Enter the public key exponent e (relatively prime to (p-1)(q-1)) : ";
        cin >> e;

        if (message <= 0 || p <= 0 || q <= 0 || e <= 0)
        {
            cout << "Please enter positive integers.";
        }
    } while (message <= 0 || p <= 0 || q <= 0 || e <= 0);

    mod = p * q;
    phi = (p - 1) * (q - 1);
    key = modInverse(e, phi);

    cout << endl;
    cout << "The Decryption key is: "<< key << endl;
    cout << "Decrypted Message: "<< RSA_Decryption(message, key, mod) << endl;
}