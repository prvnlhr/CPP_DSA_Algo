#include <iostream>
#define ll long long
using namespace std;
// REFER SCALAR WEBSITE : https://www.scaler.com/topics/data-structures/binary-exponentiation/


// TIME COMPLEXITY : O(logN)

// This is fast algorithm to find a^b.
ll binpow(ll a, ll b)
{

    ll res = 1;
    while (b > 0)
    {
        cout << a << " " << b << endl;

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

    ll a, b;
    cin >> a >> b;
    cout << binpow(a, b);
}
