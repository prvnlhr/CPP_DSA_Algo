#include <iostream>
using namespace std;

int main()
{

    int n, a, b, c;
    cin >> n;

    int ans=0;
    while (n--)
    {
        cin >> a >> b >> c;
        if (a == 1 && b == 1 && c == 1)
        {

            ans += 1;
        }
        else if (a == 1 && b == 1 && c != 1)
        {
            ans += 1;
        }
        else if (a != 1 && b == 1 && c == 1)
        {
            ans += 1;
        }
        else if (a == 1 && b != 1 && c == 1)
        {
            ans += 1;
        }
    }
    cout << ans << endl;
}