

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> manacher_odd(string s)
{
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while (s[i - p[i]] == s[i + p[i]])
        {
            p[i]++;
        }
        if (i + p[i] > r)
        {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<string> solve(string s)
{

    vector<string> stringSet;
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
        if (i < n && s[i] == s[i + 1])
        {
            dp[i][i + 1] = 1;
        }
    }
    for (int len = 3; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            if (s[i] == s[i + (len - 1)] && dp[i + 1][i + (len - 1) - 1])
            {
                dp[i][i + (len - 1)] = true;
            }
        }
    }

    vector<int> kmp(n, 0);
    for (int i = 0; i < n; i++)
    {
        int j = 0, k = 1;
        while (k + i < n)
        {
            if (s[j + i] == s[k + i])
            {
                dp[k + i - j][k + i] = false;
                kmp[k++] = ++j;
            }
            else if (j > 0)
            {
                j = kmp[j - 1];
            }
            else
            {
                kmp[k++] = 0;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        string str;
        for (int j = i; j < n; j++)
        {
            str += s[j];
            if (dp[i][j])
            {
                count++;

                stringSet.push_back(str);
            }
        }
    }

    return stringSet;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int q;
    cin >> q;

    vector<pair<int, int>> vec(q);

    for (int i = 0; i < q; i++)
    {

        int x, y;
        cin >> x >> y;
        pair<int, int> p{x, y};
        vec[i] = p;
    }

    // vector<string> st = solve(s);
    auto ans = manacher_odd(s);

    for (auto s : ans)
    {
        cout << s << endl;
    }
    // sort(st.begin(), st.end());
    // string req;

    // for (auto x : st)
    // {
    //     req += x;
    // }

    // for (int i = 0; i < q; i++)
    // {

    //     ll start = vec[i].first - 1;
    //     ll end = vec[i].second;
    //     // cout << req.length() << endl;
    //     // cout << start << " " << end << endl;

    //     if (end <= req.length())
    //     {

    //         cout << req.substr(start, end - start) << endl;
    //     }
    //     else
    //     {
    //         cout << -1 << endl;
    //     }
}
// }
