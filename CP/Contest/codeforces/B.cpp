

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
map<string, string> m = {
    {"1", "a"},
    {"2", "b"},
    {"3", "c"},
    {"4", "d"},
    {"5", "e"},
    {"6", "f"},
    {"7", "g"},
    {"8", "h"},
    {"9", "i"},
    {"10", "j"},
    {"11", "k"},
    {"12", "l"},
    {"13", "m"},
    {"14", "n"},
    {"15", "o"},
    {"16", "p"},
    {"17", "q"},
    {"18", "r"},
    {"19", "s"},
    {"20", "t"},
    {"21", "u"},
    {"22", "v"},
    {"23", "w"},
    {"24", "x"},
    {"25", "y"},
    {"26", "z"},
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int i = 0;

        string ans = "";
        while (i < n)
        {
            // cout << i << endl;
            // && s.substr(i + 1, 2) != "10"

            if (i + 2 < n && s[i + 2] == '0')
            {

                if (i + 3 < n && s[i + 3] == '0')
                {
                    string x = s.substr(i, 1);
                    // cout << x << " " << m[x] << endl;
                    ans = ans + m[x];
                    // cout << m[x];
                    i++;
                }
                else
                {
                    string x = s.substr(i, 2);
                    // cout << x << " " << m[x] << endl;
                    // cout << m[s];
                    ans = ans + m[x];
                    i += 3;
                }
            }
            else
            {
                string x = s.substr(i, 1);
                // cout << x << " " << m[x] << endl;
                ans = ans + m[x];
                // cout << m[x];
                i++;
            }
        }
        cout << ans << endl;
    }
}
