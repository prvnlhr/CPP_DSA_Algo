#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

#define FOR(i, start, end) for (int i = start; i < end; i++)
#define RFOR(i, start, end) for (int i = end; i >= start; i--)
#define FOREACH(x, b) for (auto x : b)

#define COUT(x) cout << x << endl;
#define N << endl;

typedef vector<int> vi;
typedef vector<int> vl;
typedef set<int> stint;
typedef map<int, int> mpint;
typedef pair<int, int> pi;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;

        map<string, set<int>> mpp;

        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                string s;
                cin >> s;

                mpp[s].insert(i);
            }
        }

        int scoreP1 = 0;
        int scoreP2 = 0;
        int scoreP3 = 0;

        // for (auto w : mpp)
        // {
        //     cout << w.first << " ";
        //     for (auto y : w.second)
        //     {
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }

        for (auto x : mpp)   //> O(N)
        {

            string word = x.first;

            if (mpp[word].find(1) != mpp[word].end() && mpp[word].find(2) != mpp[word].end() && mpp[word].find(3) == mpp[word].end())
            {
                scoreP1 += 1;
                scoreP2 += 1;
            }
            else if (mpp[word].find(2) != mpp[word].end() && mpp[word].find(3) != mpp[word].end() && mpp[word].find(1) == mpp[word].end())
            {
                scoreP2 += 1;
                scoreP3 += 1;
            }
            else if (mpp[word].find(1) != mpp[word].end() && mpp[word].find(3) != mpp[word].end() && mpp[word].find(2) == mpp[word].end())
            {
                scoreP1 += 1;
                scoreP3 += 1;
            }

            else if (mpp[word].size() == 1)
            {

                if (mpp[word].find(1) != mpp[word].end())
                {

                    scoreP1 += 3;
                }
                else if (mpp[word].find(2) != mpp[word].end())
                {

                    scoreP2 += 3;
                }
                else if (mpp[word].find(3) != mpp[word].end())
                {

                    scoreP3 += 3;
                }
            }
        }

        cout << scoreP1 << " " << scoreP2 << " " << scoreP3 << endl;
    }
}


/* 

*Editorial Solution
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	map<string, int> mp;
	string a[3][n];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			mp[a[i][j]]++;
		}
	}
	for (int i = 0; i < 3; i++) {
		int tot = 0;
		for (int j = 0; j < n; j++) {
			if (mp[a[i][j]] == 1) {tot += 3;}
			else if (mp[a[i][j]] == 2) {tot++;}
		}
		cout << tot << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	solve();
}
*/

/*
 *
 *while (t--)
 *    {
 *        int n;
 *        cin >> n;
 *
 *        set<string> st1;
 *        set<string> st2;
 *        set<string> st3;
 *
 *        int scorep1 = 0;
 *        int scorep2 = 0;
 *        int scorep3 = 0;
 *        for (int i = 1; i <= 3; i++)
 *        {
 *
 *            for (int j = 1; j <= n; j++)
 *            {
 *
 *                string s;
 *                cin >> s;
 *                if (i == 1)
 *                {
 *                    st1.insert(s);
 *                }
 *                else if (i == 2)
 *                {
 *                    st2.insert(s);
 *                }
 *                else if (i == 3)
 *                {
 *                    st3.insert(s);
 *                }
 *            }
 *        }
 *
 *        for (auto x : st1)
 *        {
 *
 *            if (st2.find(x) != st2.end() && st3.find(x) == st3.end())
 *            {
 *                scorep1 = scorep1 + 1;
 *                scorep2 = scorep2 + 1;
 *            }
 *            else if (st2.find(x) == st2.end() && st3.find(x) != st3.end())
 *            {
 *
 *                scorep1 = scorep1 + 1;
 *                scorep3 = scorep3 + 1;
 *            }
 *            else if (st2.find(x) != st2.end() && st3.find(x) != st3.end())
 *            {
 *                scorep1 += 0;
 *            }
 *            else
 *            {
 *                scorep1 += 3;
 *            }
 *        }
 *
 *        for (auto x : st2)
 *        {
 *            if (st3.find(x) != st3.end() && st1.find(x) == st1.end())
 *            {
 *                scorep2 = scorep2 + 1;
 *                scorep3 = scorep3 + 1;
 *            }
 *            else if (st3.find(x) == st3.end() && st1.find(x) == st1.end())
 *            {
 *                scorep2 = scorep2 + 3;
 *            }
 *        }
 *
 *
 *        for (auto x : st3)
 *        {
 *            if (st2.find(x) == st2.end() && st1.find(x) == st1.end())
 *            {
 *                scorep3 += 3;
 *            }
 *
 *
 *        }
 *        cout << scorep1 << " " << scorep2 << " " << scorep3 << endl;
 *    }
 * */