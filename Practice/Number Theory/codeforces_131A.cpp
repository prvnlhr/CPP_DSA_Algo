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
#include <cctype>
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

// cAPSlOCK
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    string res = "";
    int x;

    bool isLow = false;

    for (x = 1; x < s.length(); x++)
    {

        if (97 <= int(s[x]) && int(s[x]) <= 122)
        {

            isLow = true;
        }
    }

    if (isLow)
    {

        res = s;
    }
    else if (!isLow)
    {

        string s1 = s.substr(1, s.length() - 1);
        transform(s1.begin(), s1.end(), s1.begin(), ::tolower);

        if (97 <= int(s[0]) && int(s[0]) <= 122)
        {
            char fir = toupper(s[0]);
            string s1 = s.substr(1, s.length() - 1);
            transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
            res = fir + s1;
        }
        else
        {
            char fir = tolower(s[0]);
            string s1 = s.substr(1, s.length() - 1);
            transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
            res = fir + s1;
        }
    }

    cout << res << endl;
}