#include <bits/stdc++.h>

#define ll long long
#define COE(x) cout << x << endl
#define CO(x) cout << x << " "

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n % 2 == 1 || n ==2)
        {
            COE(-1);
        }
        else
        {
            n = n / 2;
            if (n % 3 == 0)
                CO(n / 3);
            else
                CO(n / 3 + 1);
            COE(n / 2);
        }
    }
}
