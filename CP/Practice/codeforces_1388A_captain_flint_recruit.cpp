#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        if (n <= 30)
        {
            cout << "NO" << endl;
        }
        else
        {

            int a = 6;
            int b = 10;
            int c = 14;
            int d = a + b + c;
            if ((n - d) == a || (n - d) == b || (n - d) == c)
            {
                c = 15;
                d = a + b + c;
            }
            cout << "YES" << endl;
            cout << a << " " << b << " " << c << " " << n - d << endl;
        }
    }
}
