#include <iostream>
using namespace std;

int main()
{

    int n, a, b, c;
    cin >> n;

    int ans;
    while (n--)
    {
        cin >> a >> b >> c;
        if (a + b + c >= 2)
        {

            ans += 1;
        }
    }
    cout << ans << endl;
}