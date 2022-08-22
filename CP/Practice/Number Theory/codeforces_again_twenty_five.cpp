#include <iostream>
#define ll long long
using namespace std;

ll binpow(ll a, ll b)
{

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

    return res;
}

int main()
{

    ll n;
    cin >> n;

    ll res = binpow(5, n);

    cout << 25 << endl;
}
