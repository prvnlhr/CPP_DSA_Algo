#include <iostream>
#define ll long long
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z;
        cin >> x >> y >> z;

        int a;

        if (x % 3 == 0)
        {
            a = x / 3 - 1;
        }
        else
        {
            a = x / 3;
        }

        int ans = x * y + z * a;
        cout << ans << endl;
    }
}
