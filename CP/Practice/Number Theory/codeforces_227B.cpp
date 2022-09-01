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

int linerSearch(vector<int> &arr, int q)
{

    int cnt = 1;
    for (int i = 1; i <= arr.size(); i++)
    {
        if (arr[i] == q)
        {
            break;
        }
        else
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{

    //> TC : O(N + M)
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    //> Making map of elements and their position(index)   O(N)
    map<ll, ll> mpp;
    for (ll i = 1; i <= n; i++)
    {
        ll a;
        cin >> a;
        mpp[a] = i;
    }

    //* Storing m queries :
    ll m;
    cin >> m;
    vector<ll> queries(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> queries[i];
    }

    //> calculating operatioins

    ll vasyaComp = 0;
    ll petyaComp = 0;

    //> O(M)
    for (ll i = 0; i < queries.size(); i++)
    {

        ll q = queries[i];

        //* we could have done linear search of every query but, this would have given us
        //* O(N*M) T.C , so we used map to do linear seacrh in O(1).
        // int comp = linerSearch(arr, q);
        ll comp = mpp[q];

        vasyaComp = vasyaComp + comp;
        petyaComp = petyaComp + ((n - comp) + 1);
    }

    cout << vasyaComp << " " << petyaComp << endl;
}
