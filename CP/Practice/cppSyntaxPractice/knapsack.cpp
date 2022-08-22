#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsackRec(vector<int> &weights, vector<int> &values, int maxWeight, int n)
{
    if (n == 0 || maxWeight == 0)
    {
        return 0;
    }
    if (weights[n - 1] <= maxWeight)
    {
        int a = knapsackRec(weights, values, maxWeight, n - 1);
        int b = values[n - 1] + knapsackRec(weights, values, maxWeight - weights[n - 1], n - 1);
        return max(a, b);
    }
    else
    {
        return knapsackRec(weights, values, maxWeight, n - 1);
    }
}

int knapsackIterative(vector<int> &weights, vector<int> &values, int maxWeight, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        for (int w = 1; w < maxWeight + 1; w++)
        {
            int ans;

            if (weights[i - 1] > w)
            {

                ans = dp[i - 1][w];
            }
            else
            {

                int ans1 = dp[i - 1][w];
                int ans2 = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                ans = max(ans1, ans2);
            }
            dp[i][w] = ans;
        }
    }

    return dp[n][maxWeight];
}
int main()
{

    int n = 4;
    vector<int> weights{1, 2, 4, 5};
    vector<int> values{5, 4, 8, 6};
    int wMax = 5;

    int ans1 = knapsackRec(weights, values, wMax, n);
    int ans2 = knapsackIterative(weights, values, wMax, n);

    cout << "ans1: " << ans1 << endl;
    cout << "ans2: " << ans2 << endl;
}