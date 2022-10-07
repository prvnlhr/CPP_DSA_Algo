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

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    map<char, int> mpp1;
    for (int i = 0; i < s1.length(); i++)
    {
        mpp1[s1[i]]++;
    }
    string ANS = "YES";

    // for (auto x : mpp1)
    // {
    //     cout << x.first << " " << x.second << endl;
    // }

    for (int i = 0; i < s2.length(); i++)
    {

        if (s2[i] == ' ')
        {
            continue;
        }

        else if (mpp1.find(s2[i]) != mpp1.end() && mpp1[s2[i]] >= 1)
        {
            mpp1[s2[i]]--;
        }
        else
        {
            ANS = "NO";
            break;
        }
    }
    cout << ANS << endl;
}
