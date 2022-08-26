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
    int R;
    cin >> R;
    while (R--)
    {

        int L;
        cin >> L;
        string s;
        cin >> s;

        int cntH = 0;
        string ANS = "Valid";
        int flag = false;

        for (int i = 0; i < L; i++)
        {

            if (s[i] == 'H')
            {
                cntH++;
            }
            else if (s[i] == 'T')
            {
                if (cntH == 1)
                {

                    cntH--;
                }
                else
                {

                    ANS = "Invalid";
                    flag = true;
                    break;
                }
            }
        }
        if (flag == false)
        {
            if (cntH == 0)
            {
                cout << "Valid"
                     << "\n";
            }
            else
            {
                cout << "Invalid"
                     << "\n";
            }
        }
        else
        {
            cout << ANS << "\n";
        }
    }
}
