#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {

        int limitl = -2147483648;
        int limitr = 2147483648 - 1;

        long long num = 0;

        int sign = 1;

        if (x < 0)
        {
            sign = -1;
        }
        int og = x;
        while (x)
        {

            long long ld = x % 10;
            if (x == og && ld == 0)
            {
                x = x / 10;
                continue;
            }
            else
            {

                num = num * 10 + ld;
                x = x / 10;
            }

            if ((og > 0 && num >= limitr) || (og < 0 && num < limitl))
            {
                num = 0;
                break;
            }
        }

        return int(num);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution *obj = new Solution();
    int x;
    cin >> x;

    cout << obj->reverse(x) << endl;
}
