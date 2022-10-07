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

        long long num = 0;
        int n = s.length();

        int sign = 1;

        bool alNum = false;
        bool alLetter = false;
        bool alSign = false;
        bool leadingZero = false;
        bool leadingSpace = false;

        if (s[0] == '-')
        {
            sign = -1;
        }

        for (int i = 0; i < n; i++)
        {
            if ((48 <= int(s[i]) && int(s[i]) <= 57))
            {

                if (s[i] == '0' && alNum == false)
                {
                    leadingZero = true;
                }
                else
                {
                    num = num * 10 + (s[i] - '0');
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
                    alNum = true;
                }
            }

            else if ((s[i] == '-' && !alNum && !alNum && !alSign && !leadingZero ) || (s[i] == '+' && !alNum && !alNum && !alSign && !leadingZero))
            {

                if (s[i] == '-')
                {

                    sign = -1;
                }
                else
                {
                    sign = 1;
                }

                alSign = true;
            }
            else if ((s[i] == ' ' && alNum == true) || (s[i] == ' ' && alLetter == true) || (s[i] == ' ' && leadingZero == true))
            {
                break;
            }
            else if ((65 <= int(s[i]) && int(s[i]) <= 90) || (97 <= int(s[i]) && int(s[i]) <= 122))

            {

                if (alNum || leadingZero)
                {
                    break;
                }
                alLetter = true;
            }
            else if (s[i] == '.')
            {
                break;
            }
            else if ((s[i] == '+' && alSign == true) || (s[i] == '-' && alSign == true) || (s[i] == '+' && alNum == true) || (s[i] == '-' && alNum == true))
            {
                break;
            }
            else if ((s[i] == '+' && leadingZero == true) || (s[i] == '-' && leadingZero == true))
            {
                break;
            }
        }
        num = num * sign;
        if (num >= 2147483648)
        {
            num = 2147483647;
        }
        else if (num < -2147483648)
        {
            num = -2147483648;
        }
        return int(num);
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
