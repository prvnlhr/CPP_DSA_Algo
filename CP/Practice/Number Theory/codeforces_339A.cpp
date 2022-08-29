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

    int ones = 0;
    int tows = 0;
    int threes = 0;

    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] == '1')
        {
            ones++;
        }
        else if (s[i] == '2')
        {
            tows++;
        }
        else if (s[i] == '3')
        {
            threes++;
        }
    }

    string s1 = "";
    while (ones)
    {
        s1 = s1 + "1+";
        ones--;
    }
    while (tows)
    {
        s1 = s1 + "2+";
        tows--;
    }
    while (threes)
    {
        s1 = s1 + "3+";
        threes--;
    }
    cout << s1.substr(0, s1.length() - 1) << endl;
}
