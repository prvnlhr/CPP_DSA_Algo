

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {

        ll x, y;
        cin >> x >> y;

        ll B = y;
        ll A = y;
        ll C = x * 3 - (A + B);

        cout << A << " " << B << " " << C << endl;
    }
}
