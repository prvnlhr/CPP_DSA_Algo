
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

//|> ---ＳＯＬＶＥ-----------------------------------------------------------------------------------------------------------------------------------------------

int numWays(vector<int> &coins, int x, int start, vector<int> &dp)
{
    if (x < 0)
    {
        return 0;
    }

    if (x == 0)
    {
        return 1;
    }

    if (dp[x] != -1)
    {
        return dp[x];
    }

    int num_ways = 0;
    
    for (int i = start; i < coins.size(); i++)
    {
        if (coins[i] <= x)
        {
            num_ways = (num_ways + numWays(coins, x - coins[i], i + 1, dp)) % MOD;
        }
    }

    dp[x] = num_ways;
    return num_ways;
}

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, -1);

    int result = numWays(coins, x, 0, dp);
    cout << result << endl;
    return 0;
}