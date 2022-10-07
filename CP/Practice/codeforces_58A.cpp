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

    string s;
    cin >> s;

    string ANS = "";
    int ltrCnt = 1;
    string res = "NO";
    FOR(i, 0, s.length())
    {

        // cout << i << " " << s[i] << " " << ltrCnt << endl;

        if (ltrCnt == 1 && s[i] == 'h')
        {
            ANS = ANS + s[i];
            ltrCnt++;
        }
        else if (ltrCnt == 2 && s[i] == 'e')
        {
            ANS = ANS + s[i];
            ltrCnt++;
        }
        else if (ltrCnt == 3 && s[i] == 'l')
        {
            ANS = ANS + s[i];
            ltrCnt++;
        }
        else if (ltrCnt == 4 && s[i] == 'l')
        {
            ANS = ANS + s[i];
            ltrCnt++;
        }
        else if (ltrCnt == 5 && s[i] == 'o')
        {
            ANS = ANS + s[i];
        }

        if (ANS == "hello")
        {

            res = "YES";
            break;
        }
        // cout << ANS << endl;
    }
    cout << res << endl;
}
