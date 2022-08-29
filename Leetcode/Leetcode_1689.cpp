#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string n;
    cin >> n;

    int MAX = INT_MIN;
    for (int i = 0; i < n.length(); i++)
    {

        MAX = max(MAX, n[i] - '0');
    }
    cout << MAX << endl;
}
