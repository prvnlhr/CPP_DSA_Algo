#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int minWays(vector<int> &coins, int x, vector<int> &dp)
{

    if (x < 0)
    {
        return INF;
    }
    if (x == 0)
    {
        return 0;
    }

    if (dp[x] != -1)
    {
        return dp[x];
    }

    int minCoins = INF;
    for (int coin : coins)
    {
        minCoins = min(minCoins, minWays(coins, x - coin, dp) + 1);
    }

    dp[x] = minCoins;
    return minCoins;
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
    int result = minWays(coins, x, dp);

    if (result == INF)
    {
        cout << -1 << endl; // It's not possible to make the desired sum.
    }
    else
    {
        cout << result << endl; // Minimum number of coins required.
    }

    return 0;
}