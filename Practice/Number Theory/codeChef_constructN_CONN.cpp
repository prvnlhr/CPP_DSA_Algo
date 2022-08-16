#include <iostream>
#define ll long long
using namespace std;

int main()
{

    int t;
    cin >> t;
    int a, b;
    a = 2;
    b = 7;

    // ! self solved
    // ** Time complexity O(1)
    // >> Observation : 1 ->> if a number is divisible by 2, or even then there if definitely a solution
    // >> Observation : 2 ->> if a number is odd then, following condition should satifies for a sol to exist
    // ??  2x + 7y = n
    // ??  for y = 1 ->> 2x + 7 = n
    // ?? now, if (n - 7) % 2 ==0 , sol exists else NO.
    while (t--)
    {
        int n;
        cin >> n;

        if (n % 2 == 0)
        {
            cout << "YES" << endl;
        }
        else
        {

            ll x = n - 7;
            if (x == 0)
            {
                cout << "YES" << endl;
            }

            else if (x > 0 && x % 2 == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}

/*

 * Brute force timeComplexity O(N^2) ->> TLE
 >> This solution works by finding all possible solution of x , y,
 >> and if for x, y if it satifies ax + by = n , then YES else NO
int n;
cin >> n;
bool flag = false;
for (int i = 0; i <= n; i++)
{
    for (int j = 0; j <= n; j++)
    {

        if ((2 * i + 7 * j) == n)
        {

            cout << "YES" << endl;

            flag = true;
            break;
        }
    }
}
if (flag == false)
    cout << "NO " << endl;


 */
