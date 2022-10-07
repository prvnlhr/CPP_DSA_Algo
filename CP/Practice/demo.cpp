#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{

	int t;
	cin >> t;
	while (t--)
	{

		ll n;
		cin >> n;

		string s;
		cin >> s;

		ll total = 0;

		vector<ll> arr;

		for (ll i = 0; i < n; i++)
		{
			if (s[i] == 'L')
			{

				ll now = i;
				ll after = n - 1 - i;
				ll diff = after - now;
				arr.push_back(diff);
				total += i;
			}
			else if (s[i] == 'R')
			{

				ll after = i;
				ll now = n - 1 - i;
				ll diff = after - now;
				arr.push_back(diff);
				total += now;
			}
		}
		sort(arr.begin(), arr.end(), greater<int>());

		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] > 0)
			{

				total += arr[i];
				cout << total << " ";
			}
			else
			{
				cout << total << " ";
			}
		}
		cout << endl;
	}
}