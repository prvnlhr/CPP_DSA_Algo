

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

typedef long long ll;

#define REMDUP(arr) unique(arr.begin(), arr.end())

#define SORTASC(arr) sort(arr.begin(), arr.end())
#define SORTDSC(arr) sort(arr.begin(), arr.end(), greater<>())
#define lb(arr, val) lower_bound(arr.begin(), arr.end(), val)
#define ub(arr, val) upper_bound(arr.begin(), arr.end(), val)

#define pb push_back
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> vec_pos;
        vector<ll> vec_neg;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            if (x >= 0)
                vec_pos.pb(x);
            else if (x < 0)
                vec_neg.pb(x);
        }

        //> SORT ASCENDING
        SORTASC(vec_pos);
        SORTASC(vec_neg);

        //> if no -ve, first and last elements of positive arr  gives ans

        if (vec_neg.size() == 0)
        {
            ll x, y;
            x = vec_pos[0] * vec_pos[0];
            y = vec_pos[vec_pos.size() - 1] * vec_pos[vec_pos.size() - 1];
            cout << x << " " << y << endl;
        }

        //> if no +ve, first and last elements of negitve  arr  gives ans

        else if (vec_pos.size() == 0)
        {
            ll x, y;
            x = vec_neg[vec_neg.size() - 1] * vec_neg[vec_neg.size() - 1];
            y = vec_neg[0] * vec_neg[0];
            cout << x << " " << y << endl;
        }

        //>else

        else
        {
            if (abs(vec_neg[0]) > (vec_pos[vec_pos.size() - 1]))
            {

                ll x, y;
                x = vec_pos[vec_pos.size() - 1] * vec_neg[0];
                y = vec_neg[0] * vec_neg[0];
                cout << x << " " << y << endl;
            }
            else
            {
                ll x = vec_pos[vec_pos.size() - 1] * vec_neg[0];
                ll y = vec_pos[vec_pos.size() - 1] * vec_pos[vec_pos.size() - 1];
                cout << x << " " << y << endl;
            }
        }
    }
}