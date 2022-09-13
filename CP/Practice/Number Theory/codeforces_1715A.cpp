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

        int n, m;
        cin >> n >> m;

        if (n == 1 && m == 1)
        {
            cout << 0 << endl;
        }
        else
        {

            if (n < m)
            {

                if (n % 2 == 0)
                {
                    int a = (n / 2) + (n - ((n / 2)) - 1) + (m - 1);
                    int b = (n / 2) + (n - ((n / 2)) - 1) + 1;
                    cout << a + b << endl;
                }
                else
                {
                    int a = 2 * (n / 2) + (m - 1);
                    int b = 2 * (n / 2) + 1;
                    cout << a + b << endl;
                }
            }
            else if (m < n)
            {
                if (m % 2 == 0)
                {
                    int a = (m / 2) + (m - ((m / 2)) - 1) + (n - 1);
                    int b = (m / 2) + (m - ((m / 2)) - 1) + 1;
                    cout << a + b << endl;
                }
                else
                {
                    int a = 2 * (m / 2) + (n - 1);
                    int b = 2 * (m / 2) + 1;
                    cout << a + b << endl;
                }
            }
            else
            {
                if (m % 2 == 0)
                {
                    int a = (m / 2) + (m - ((m / 2)) - 1) + (n - 1);
                    int b = (m / 2) + (m - ((m / 2)) - 1) + 1;
                    cout << a + b << endl;
                }
                else
                {
                    int a = 2 * (m / 2) + (n - 1);
                    int b = 2 * (m / 2) + 1;
                    cout << a + b << endl;
                }
            }
        }
    }
}
