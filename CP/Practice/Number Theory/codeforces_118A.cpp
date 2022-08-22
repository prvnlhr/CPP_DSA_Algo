#include <bits/stdc++.h>
using namespace std;

#define FOR(i, start, end) for (int i = start; i < end; i++)
#define RFOR(i, start, end) for (int i = end; i >= start; i--)
#define FOREACH(x, b) for (auto x : b)

#define COUT(x) cout << x << endl;
#define N << endl;

typedef vector<int> vi;
typedef vector<int> vl;
typedef set<int> stint;
typedef set<char> stchar;
typedef map<int, int> mpint;
typedef pair<int, int> pi;

typedef long long ll;

stchar st{'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u', 'Y', 'y'};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;

    string ANS = "";
    FOR(i, 0, s.length())
    {

        if (st.find(s[i]) == st.end())
        {
            char x = towlower(s[i]);
            ANS = ANS + '.' + x;
        }
    }
    cout << ANS << "\n";
}
