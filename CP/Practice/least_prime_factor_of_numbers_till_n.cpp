#include <iostream>
#include <vector>
using namespace std;

int N = 50;
vector<int> sieve(N + 1, 0);

void createSieve()
{

    sieve[0] = 0;
    sieve[1] = 1;

    for (int i = 2; i * i <= N; i++)
    {
        if (sieve[i] == 0)
        {

            sieve[i] = i;
            for (int j = i * i; j <= N; j += i)
            {
                if (sieve[j] == 0)
                {
                    sieve[j] = i;
                }
            }
        }
    }

    for (auto x : sieve)
    {
        cout << x << " ";
    }
    cout << endl;
}
int main()
{

    int t;
    cin >> t;

    createSieve();
    vector<int> ans;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            ans.push_back(sieve[i]);
            cout << "Least Prime factor of " << i << ": " << sieve[i] << endl;
        }
    }
    for (auto x : ans)
    {
        cout << x << " ";
    }
}
