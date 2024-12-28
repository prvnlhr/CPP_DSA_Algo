#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int count_ways_dp(int x, vector<int> &coins, vector<int> &dp)
{
    if (x == 0)
    {
        return 1;
    }

    if (dp[x] != -1)
    {
        return dp[x];
    }

    int ans = 0;

    for (int coin : coins)
    {
        if (x - coin >= 0)
        {
            ans = (ans + count_ways_dp(x - coin, coins, dp)) % MOD;
        }
    }

    return dp[x] = ans;
}

int count_ways_dp(int x, vector<int> &coins, vector<int> &dp)
{
    if (x == 0)
    {
        return 1;
    }

    if (dp[x] != -1)
    {
        return dp[x];
    }

    int ans = 0;

    for (int coin : coins)
    {
        if (x - coin >= 0)
        {
            ans = (ans + count_ways_dp(x - coin, coins, dp)) % MOD;
        }
    }

    return dp[x] = ans;
}

int count_ways_dp(int x, vector<int> &coins)
{

    vector<int> dp(x + 1, 0);

    dp[0] = 1;

    for (int coin : coins)
    {
        for (int i = coin; i <= x; i++)
        {
            dp[i] = (dp[i] + dp[i - coin]) % MOD;
        }
    }

    return dp[x];
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

    int count = count_ways_dp(x, coins, dp);

    cout << count % MOD << endl;

    return 0;
}
