
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--)
    {

        ll n;
        cin >> n;
        cout << (n / 3) * 2 + (n / 2) * 2 + n << endl;
    }
}
