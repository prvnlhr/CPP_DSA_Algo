#include <iostream>
#include <vector>

using namespace std;

int n = 1000;
vector<bool> sieve(n + 1, true);

int main()
{

    // #ifndef ONLINE_JUDGE

    //     // For getting input from input.txt file
    //     freopen("input.txt", "r", stdin);

    //     // Printing the Output to output.txt file
    //     freopen("output.txt", "w", stdout);

    // #endif

    sieve[0] = sieve[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= n; j += i)
                sieve[j] = false;
        }
    }
    // for (int i = 2; i < sieve.size(); i++)
    // {
    //     if (sieve[i] == 1)
    //     {

    //         cout << i << " ";
    //     }
    // }
    // cout << endl;

    int n, k;
    cin >> n >> k;
    int cnt = 0;

    for (int i = 2; i <= n; i++)
    {

        if (sieve[i] == 1)
        {

            int a = i;

            for (int j = i + 1; j <= n; j++)
            {

                if (sieve[j] == 1)
                {

                    int b = j;
                    int x = a + b + 1;
                    if (x <= n && sieve[x] == 1)
                    {

                        cnt++;
                    }
                    break;
                }
            }
        }
    }
    // cout << cnt << endl;
    if (cnt >= k)
    {
        cout << "YES" << endl;
    }
    else if (cnt < k)

    {
        cout << "NO" << endl;
    }
}
