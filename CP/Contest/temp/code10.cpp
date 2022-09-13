#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;

set<string> palindromeSubStrs(string s)
{
    map<string, int> m;
    int n = s.size();

    int R[2][n + 1];

    s = "@" + s + "#";

    for (int j = 0; j <= 1; j++)
    {
        int rp = 0;
        R[j][0] = 0;

        int i = 1;
        while (i <= n)
        {
            while (s[i - rp - 1] == s[i + j + rp])
                rp++;

            R[j][i] = rp;
            int k = 1;
            while ((R[j][i - k] != rp - k) && (k < rp))
            {
                R[j][i + k] = min(R[j][i - k], rp - k);
                k++;
            }
            rp = max(rp - k, 0);
            i += k;
        }
    }

    // set<string> st2;
    s = s.substr(1, n);

    m[string(1, s[0])] = 1;
    // st2.insert(string(1, s[0]));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 1; j++)
            for (int rp = R[j][i]; rp > 0; rp--)
            {

                m[s.substr(i - rp - 1, 2 * rp + j)] = 1;
                // st2.insert(s.substr(i - rp - 1, 2 * rp + j));
                // cout << s.substr(i - rp - 1, 2 * rp + j) << endl;
            }
        m[string(1, s[i])] = 1;
        // st2.insert(string(1, s[i]));
    }
    map<string, int>::iterator ii;
    set<string> st;
    for (ii = m.begin(); ii != m.end(); ++ii)
    {
        string x = (*ii).first;
        st.insert(x);
    }
    // cout << (*ii).first << endl;
    return st;
}

int main()
{

    int n;
    cin >> n;

    string s;
    cin >> s;

    ll q;
    cin >> q;

    vector<pair<int, int>> vec(q);

    for (int i = 0; i < q; i++)
    {

        ll a, b;
        cin >> a >> b;
        pair<int, int> p{a, b};
        vec[i] = p;
    }

    auto ans = palindromeSubStrs(s);

    vector<string> subStrArr;

    for (auto x : ans)
    {

        subStrArr.push_back(x);
    }

    sort(subStrArr.begin(), subStrArr.end());

    string req;

    for (auto x : subStrArr)
    {

        req += x;
    }

    for (int i = 0; i < q; i++)
    {

        ll start = vec[i].first;
        ll end = vec[i].second;

        if (end < req.length())
        {

            cout << req.substr(start, end - start + 1) << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}