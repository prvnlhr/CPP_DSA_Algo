#include <iostream>
#include <vector>
#include <set>
#define ll long long
using namespace std;
int main()
{

	int t;
	cin >> t;

	while (t--)
	{

		int n;
		cin >> n;

		set<int> s = {6, 13, 20, 27, 7, 14, 21, 28};

		for (int i = 0; i < n; i++)
		{
			int u;
			cin >> u;
			s.insert(u);
		}
		cout << s.size() << endl;
	}
}
