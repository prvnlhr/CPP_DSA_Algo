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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> input(n);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    sort(input.begin(), input.end());

    int groups = n / 3;

    vector<vector<int>> ans;

    for (int i = 0; i < groups; i++)
    {

        vector<int> arr;

        for (int j = 0; j < n; j++)
        {

            if (arr.size() == 0)
            {
                if (input[j] != -1)
                {

                    arr.push_back(input[j]);
                    input[j] = -1;
                }
            }

            else if (arr.size() == 1)
            {
                if (input[j] != -1 && input[j] > arr[0] && input[j] % arr[0] == 0)
                {
                    arr.push_back(input[j]);
                    input[j] = -1;
                }
            }
            else if (arr.size() == 2)
            {
                if (input[j] != -1 && input[j] > arr[1] && input[j] % arr[1] == 0)
                {
                    arr.push_back(input[j]);
                    input[j] = -1;
                }
            }

            if (arr.size() == 3)
            {
                ans.push_back(arr);
                break;
            }
        }
    }

    if (ans.size() != (n / 3))
    {
        cout << -1 << endl;
    }
    else
    {

        for (auto x : ans)
        {
            for (auto y : x)
            {
                cout << y << " ";
            }
            cout << endl;
        }
    }
}

/*

9
1 3 2 6 3 1 4 2 2

9
1 3 6 1 2 4 1 3 6

*/
