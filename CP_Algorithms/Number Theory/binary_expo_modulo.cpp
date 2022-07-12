#include <iostream>
#define ll long long
using namespace std;

ll binpow(ll a, ll b, ll m)
{

    a = a % m;
    ll res = 1;
    while (b > 0)
    {

        if (b % 2 == 1)
        {

            res = res * a % m;
        }
        a = a * a;
        b = b / 2;
    }

    return res;
}

int main()
{

    // find a ^ b % m
    ll a, b, m;
    cin >> a >> b >> m;
    cout << binpow(a, b, m);
}
