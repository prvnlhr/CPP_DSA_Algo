#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FOR(i, start, end) for (int i = start; i < end; i++)
#define RFOR(i, start, end) for (int i = end; i >= start; i--)
#define FOREACH(x, b) for (auto x : b)

#define cout1(x) cout << x << endl;
#define cout2(x, y) cout << x << " " << y << endl;
#define cout3(x, y, z) cout << x << " " << y << " " << z << endl;

#define SUMOFN(arr) accumulate(arr.begin(), arr.end(), 0LL);
#define SORTASC(arr) sort(arr.begin(), arr.end());
#define SORTDSC(arr) sort(arr.begin(), arr.end(), greater<int>());

#define strLow(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define strUp(s) transform(s.begin(), s.end(), s.begin(), ::toupper);

#define lb(arr, ele) lower_bound(arr.begin(), arr.end(), ele);
#define ub(arr, ele) upper_bound(arr.begin(), arr.end(), ele);

typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> stint;
typedef map<int, int> mpint;
typedef pair<int, int> pi;
typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

class Solution
{
public:
    int myAtoi(string s)
    {

        //  48 57 --> numbers
        // '1' -> char - '0'

        // "-123"

        long long num = 0;
        int n = s.length();

        int sign = 1;

        int i = 0;
        while (s[i] == ' ')
        {
            i++;
        }
        if (s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (s[i] == '+')
        {
            sign = 1;
            i++;
        }

        while ((48 <= int(s[i]) && int(s[i]) <= 57))
        {

            num = num * 10 + s[i] - '0';
            if (num * sign >= 2147483648)
            {
                num = 2147483647;
                return num;
            }
            else if (num * sign < -2147483648)
            {
                num = -2147483648;
                return num;
            }
            i++;
        }

        return int(num * sign);
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution *obj = new Solution();
    string s;
    getline(cin, s);
    cout << obj->myAtoi(s) << endl;
}
