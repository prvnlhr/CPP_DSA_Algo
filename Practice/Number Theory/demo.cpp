#include <iostream>
#define ll long long
using namespace std;

int main()
{
	ll n;
	cin >> n;
	ll cnt = 1;

	for (ll i = 1; i <= n; i++)
	{
		if (i % 5 == 0 && i != 5 && 1 != 25)
		{
			cnt++;
		}
	}

	cout << cnt << endl;
}
