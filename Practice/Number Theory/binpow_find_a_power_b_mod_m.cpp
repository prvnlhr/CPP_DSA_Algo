#include <iostream>
#define ll long long
using namespace std;

ll moduloA(ll a, ll b, ll m)
{

    // we need to find a ^ b % m
    // Step 1 : find a^b using binary expo.
    ll res = 1;

    while (b > 0)
    {

        if (b % 2 == 1)
        {
            res = res * a;
        }

        a = a * a;
        b = b / 2;
    }

    return res % m;
}

int main()
{

    ll a, b, m;
    cin >> a >> b >> m;
    cout << moduloA(a, b, m);
}
