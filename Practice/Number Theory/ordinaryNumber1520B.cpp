#include <iostream>
#define ll long long
using namespace std;

int main()
{

    int t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int cnt = 0;
        for (ll i = 1; i <= 9; i++)
        {

            ll start = i;

            while (start <= n)
            {

                start = start * 10 + i;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}
