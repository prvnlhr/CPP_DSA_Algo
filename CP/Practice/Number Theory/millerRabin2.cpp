
// C++ program Miller-Rabin primality test
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll power(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result
    x = x % p;  // Update x if it is more than or
                // equal to p
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;

        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

bool miillerTest(ll a, ll d, ll n)
{

    ll x = power(a, d, n);

    if (x == 1 || x == n - 1)
        return true;

    while (d != n - 1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)
            return false;
        if (x == n - 1)
            return true;
    }

    return false;
}

bool isPrime(ll n, int k = 5)
{
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;

    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
    {
        ll a = 2 + rand() % (n - 4);
        if (!miillerTest(a, d, n))
        {

            return false;
        }
    }

    return true;
}

// Driver program
int main()
{
    ll n;
    cin >> n;
    cout << isPrime(n) << endl;
}