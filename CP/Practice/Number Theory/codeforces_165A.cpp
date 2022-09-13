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

    int n;
    cin >> n;
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++)
    {

        int a, b;
        cin >> a >> b;
        pair<int, int> p{a, b};
        vec[i] = p;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {

        set<int> st;
        auto pointXY = vec[i];
        int x = pointXY.first;
        int y = pointXY.second;
        for (int j = 0; j < n; j++)
        {
            auto pointXY_ = vec[j];
            int x_ = pointXY_.first;
            int y_ = pointXY_.second;
            if (i != j)
            {
                //>upper
                if (x == x_ && y_ > y)
                {
                    st.insert(1);
                }
                //> lower
                else if (x == x_ && y > y_)
                {
                    st.insert(2);
                }
                //>left
                else if (y_ == y && x > x_)
                {
                    st.insert(3);
                }
                //> right
                else if (y_ == y && x < x_)
                {
                    st.insert(4);
                }
            }
        }
        if (st.size() == 4)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
}
