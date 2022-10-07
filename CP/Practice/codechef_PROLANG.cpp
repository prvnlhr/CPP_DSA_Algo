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

        int ANS = 0;
        int A, B, A1, B1, A2, B2;
        cin >> A >> B >> A1 >> B1 >> A2 >> B2;

        set<int> st1{A1, B1};
        set<int> st2{A2, B2};

        if (st1.find(A) != st1.end() && st1.find(B) != st1.end())
        {
            ANS = 1;
        }
        else if (st2.find(A) != st2.end() && st2.find(B) != st2.end())
        {
            ANS = 2;
        }

        // if (A == A1 && B == B1 || A == B1 || B == B2)
        // {
        //     ANS = 1;
        // }
        // else if (A == A2 && B == B2 || A == B2 && B == A2)
        // {
        //     ANS = 2;
        // }

        cout << ANS << "\n";
    }
}