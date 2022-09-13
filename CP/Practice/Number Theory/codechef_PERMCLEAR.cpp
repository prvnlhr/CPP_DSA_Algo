

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

        vector<int> vec(n);
        for (int i = 0; i < n; i++)
        {

            cin >> vec[i];
        }

        set<int> st;
        int cnt = 1;
        for (int i = 0; i < n; i++)
        {

            if (st.find(vec[i]) != st.end())
            {
                cnt += 1;
            }
            else

            {
                st.insert(vec[i]);
            }
        }
        cout << cnt << endl;
    }
}
