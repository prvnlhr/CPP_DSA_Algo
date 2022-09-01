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

        ll k;
        cin >> k;

        set<ll> empSt;
        map<ll, set<ll>> mpp;
        vector<vector<ll>> arr(k);

        ll dept = 0;
        for (ll i = 0; i < k; i++)
        {

            ll a, b;
            cin >> a >> b;
            vector<ll> temp = {a, b};
            arr[i] = temp;
        }

        sort(arr.begin(), arr.end());
        // FOREACH(x, arr)
        // {
        //     FOREACH(y, x)
        //     {
        //         cout << y << " ";
        //     }
        //     cout << "  ";
        // }

        for (int i = 0; i < k; i++)
        {

            auto pair = arr[i];
            int p1 = pair[0];
            int p2 = pair[1];

            if (mpp.find(p1) == mpp.end())
            {

                if (mpp.find(p2) == mpp.end())
                {

                    mpp[p1].insert(p2);
                    mpp[p2].insert(p1);
                }
                else
                {
                    empSt.insert(p1);
                    empSt.insert(p2);
                }
            }
            else
            {

                if (mpp.find(p2) == mpp.end())
                {

                    mpp[p1].insert(p2);
                    mpp[p2].insert(p1);
                }
                else
                {
                    empSt.insert(p1);
                    empSt.insert(p2);
                }
            }
        }

        FOREACH(x, mpp)
        {
            cout << x.first << ": ";
            FOREACH(y, x.second)
            {
                cout << y << " ";
            }
            cout << endl;
        }
    }
}