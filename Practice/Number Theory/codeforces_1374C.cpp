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
        string s;
        cin >> s;

        //> Solution 1: Using stack for couting balanced bracks.

        vector<char> st;

        // > O(N) --> overall T.C,   S.C O(N)
        for (int i = 0; i < s.length(); i++) //> O(N) -> 0 to n;
        {

            if (st.size() != 0 && st[st.size() - 1] == '(' && s[i] == ')')
            {

                // > O(1)
                st.pop_back();
            }
            else
            {
                //> O(1)
                st.push_back(s[i]);
            }
        }

        cout << st.size() / 2 << "\n";


        // >>______________________________________________________________________________________________________________

        //> Solution 2 : Maintaining Brackets bal counter and ans for unbalanced bracks.

        int ans = 0;
        int bal = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                bal++;
            }
            else
            {
                bal--;
                if (bal < 0)
                {
                    bal = 0;
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
}
