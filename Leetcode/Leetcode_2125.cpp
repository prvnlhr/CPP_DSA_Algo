#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    
    int setBits(string s)
    {

        int cnt = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
            {
                cnt++;
            }
        }
        return cnt;
    }
    // 011001 000000 010100 001000 x
    //> O(N*M)
    int numberOfBeams(vector<string> &bank)
    {

        int ans = 0;
        int prevBits = setBits(bank[0]);

        for (int i = 1; i < bank.size(); i++)
        {
            int currbits = setBits(bank[i]);

            if (currbits > 0)
            {
                ans = ans + prevBits * currbits;
                prevBits = currbits;
            }
        }
        return ans;
    }

    //> Another Leetocode Solution, using count inbuilt count() func O(N*M)
    /*
    * class Solution {
    * public:
    *     int numberOfBeams(vector<string>& bank) {
    *         int ans = 0, pre = 0;
    *         for (int i = 0;i < bank.size(); i ++) {
    *             int n = count(bank[i].begin(), bank[i].end(), '1');
    *             if (n == 0) continue;
    *             ans += pre * n;;
    *             pre = n;
    *         }
    *         return ans;
    *     }
};
    */
};
int main()
{

    vector<string> arr;

    string x;
    while ((cin >> x) && x != "x")
    {
        arr.push_back(x);
    }

    Solution *obj = new Solution();
    auto ans = obj->numberOfBeams(arr);
    cout << ans << endl;
}