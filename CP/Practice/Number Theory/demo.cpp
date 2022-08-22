#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl '\n';
#define pb push_back
#define ppb pop_back
#define pii pair<int, int>
#define pll pair<long, long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define v(type) vector<type>
#define s(type) set<type>
#define m(type1, type2) map<type1, type2>
#define um(type1, type2) unordered_map<type1, type2>
#define p(type1, type2) pair<type1, type2>
#define mp make_pair
#define ff first
#define ss second
#define PI 3.14159
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(var, start, end) for (int var = start; var < end; ++var)
#define rloop(var, start, end) for (int var = end; var >= start; --var)
#define MAX(a, b) (a >= b ? a : b)
#define MIN(a, b) (a >= b ? b : a)
#define SWP(a, b) (a = (a + b) - (b = a));

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x)       \
	cerr << #x << " "; \
	_print(x);         \
	cerr << endl;
#else
#define debug(x)
#endif

int32_t main()
{
	// fastIO();
	ll n, m;
	string s;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> s;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += (s[i] - '0');
		}
		if (sum == 0)
		{
			cout << n * m << endl;
		}
		else if ((sum * m) % 2 == 1)
		{
			cout << 0 << endl;
		}
		else
		{
			if (m % 2 == 0)
			{
				int cnt_0_start = 0, cnt_0_end = 0;
				for (int i = 0; i < n; i++)
				{
					if (s[i] == '1')
					{
						break;
					}
					cnt_0_start++;
				}
				for (int i = n - 1; i >= 0; i--)
				{
					if (s[i] == '1')
					{
						break;
					}
					cnt_0_end++;
				}
				cout << cnt_0_start + cnt_0_end + 1 << endl;
			}
			else
			{
				int ans = 0, cur_sum = 0;
				for (int i = 0; i < n; i++)
				{
					cur_sum += (s[i] - '0');
					ans += (cur_sum == sum / 2);
					if (cur_sum > sum / 2)
					{
						break;
					}
				}
				cout << ans << endl;
			}
		}
	}
	return 0;
}