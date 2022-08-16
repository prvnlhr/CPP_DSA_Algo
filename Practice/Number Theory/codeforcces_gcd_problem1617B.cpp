#include <iostream>
#define ll long long
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        int a, b, c;
        c = 1;

        for (int i = 2; i <= n; i++)
        {
            a = i;
            b = n - a - 1;
            if (gcd(a, b) == 1)
            {
                cout << a << " " << b << " " << c << endl;
                break;
            }
        }
    }
}
