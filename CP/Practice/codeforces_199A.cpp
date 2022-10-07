#include <bits/stdc++.h>
using namespace std;

#define FOR(i, start, end) for (int i = start; i < end; i++)
#define RFOR(i, start, end) for (int i = end; i >= start; i--)
#define FOREACH(x, b) for (auto x : b)

#define print1(x) cout << x << endl;
#define print2(x, y) cout << x << " " << y << endl;
#define print3(x, y, z) cout << x << " " << y << " " << z << endl;

typedef vector<int> vi;
typedef vector<int> vl;
typedef set<int> stint;
typedef map<int, int> mpint;
typedef pair<int, int> pi;

typedef long long ll;

ll previousFibonacci(int n)
{
    double a = n / ((1 + sqrt(5)) / 2.0);
    return round(a);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 0)
    {
        cout << 0 << " " << 0 << " " << 0 << endl;
    }
    else if (n == 1)
    {
        cout << 0 << " " << 0 << " " << 1 << endl;
    }
    else if (n == 2)
    {
        cout << 0 << " " << 1 << " " << 1 << endl;
    }
    else
    {

        int prev = previousFibonacci(n);
        int prev1 = previousFibonacci(prev);
        int prev2 = previousFibonacci(prev1);
        int prev3 = previousFibonacci(prev2);

        cout << prev2 << " " << prev1 << " " << prev1 << endl;
    }
}
