

#include <bits/stdc++.h>
using namespace std;
map<char, int> m = {
    {'a', 1},
    {'b', 2},
    {'c', 3},
    {'d', 4},
    {'e', 5},
    {'f', 6},
    {'g', 7},
    {'h', 8},
    {'i', 9},
    {'j', 10},
    {'k', 11},
    {'l', 12},
    {'m', 13},
    {'n', 14},
    {'o', 15},
    {'p', 16},
    {'q', 17},
    {'r', 18},
    {'s', 19},
    {'t', 20},
    {'u', 21},
    {'v', 22},
    {'w', 23},
    {'x', 24},
    {'y', 25},
    {'z', 26},
};

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();

        map<int, vector<int>> mpp;

        for (int i = 0; i < n; i++)
        {
            mpp[m[s[i]]].push_back(i);
        }

        vector<int> seq;

        int cost = 0;
        int prev;

        if (s[0] <= s[n - 1])
        {

            int start = m[s[0]];
            int end = m[s[n - 1]];
            prev = 0;

            for (int i = start; i <= end; i++)
            {

                for (auto x : mpp[i])
                {

                    seq.push_back(x + 1);

                    int val = m[s[x]];

                    cost = cost + (abs(prev - val));
                    prev = val;
                }
            }
            cost = abs(start - cost);
        }

        else if (s[0] > s[n - 1])
        {
            int start = m[s[0]];
            int end = m[s[n - 1]];
            prev = 0;

            for (int i = start; i >= end; i--)
            {

                for (auto x : mpp[i])
                {

                    seq.push_back(x + 1);

                    int val = m[s[x]];
                    cost = cost + (abs(prev - val));
                    prev = val;
                }
            }
            cost = abs(start - cost);
        }

        cout << cost << " " << seq.size() << endl;

        for (auto x : seq)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
