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

typedef priority_queue<int> maxpq;
typedef priority_queue<int, vector<int>, greater<int>> minpq;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int p, f;
    cin >> p >> f;
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pqx;

    for (int i = 0; i < f; i++)
    {
        int a;
        cin >> a;
        pq.push(a);
        pqx.push(a);
    }

    int ans_max = 0;
    for (int i = 0; i < p; i++)
    {
        int seats = pq.top();

        ans_max += seats;
        pq.pop();
        pq.push(seats - 1);
    }

    int ans_min = 0;

    for (int i = 0; i < p; i++)
    {
        int seats = pqx.top();

        if (seats == 0)
        {
            pqx.pop();
            seats = pqx.top();
        }
        ans_min += seats;
        seats--;
        pqx.pop();
        pqx.push(seats);
    }

    cout << ans_max << " " << ans_min << endl;
}
