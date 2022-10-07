#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        int start = 0;
        int maxLength = INT_MIN;
        map<char, int> mpp;

        int n = s.length();
        if (n == 0)
        {
            return 0;
        }
        if (s == " ")
        {
            return 1;
        }
        if (n == 1)
        {
            return 1;
        }

        while (start < n)
        {

            if (mpp.find(s[start]) == mpp.end())
            {

                mpp[s[start]] = start;
                maxLength = max(maxLength, (int)mpp.size());
                start++;
            }
            else if (mpp.find(s[start]) != mpp.end())
            {
                start = mpp[s[start]] + 1;
                maxLength = max(maxLength, (int)mpp.size());

                mpp.clear();
            }
        }
        return maxLength;
    }
};

int main()
{

    Solution *obj = new Solution();
    string s;
    cin >> s;
    cout << obj->lengthOfLongestSubstring(s);
}