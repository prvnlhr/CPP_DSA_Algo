#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int cntWaysDP(int n, vector<int> &dp) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    int res = 0;
    for (int i = 1; i <= 6; i++) {
        if (i <= n) {
            int cnt = cntWaysDP(n - i, dp);
            res = (res + cnt) % MOD;
        }
    }
    dp[n] = res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    int ans = cntWaysDP(n, dp);
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
