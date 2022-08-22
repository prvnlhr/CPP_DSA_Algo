

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

vector<char> firstNonRepeatingChar(string s)
{

    unordered_map<char, int> mpp;
    queue<char> q;

    vector<char> res(s.length(), '#');
    cout << res.size() << endl;
    int res_indx = 0;

    string ans = "";

    for (auto chr : s)
    {

        if (mpp.find(chr) != mpp.end())
        {
            mpp[chr]++;
        }
        else if (mpp.find(chr) == mpp.end())
        {
            mpp[chr] = 1;
            q.push(chr);
        }

        while (!q.empty() && mpp[q.front()] > 1)
        {
            q.pop();
        }

        if (!q.empty())
        {
            res[res_indx] = q.front();
            res_indx++;
        }
        else
        {
            res[res_indx] == '#';
            res_indx++;
        }
    }

    return res;
}
int main()
{

    string s = "aabccdba";
    auto ans = firstNonRepeatingChar(s);
    for (auto ele : ans)
    {
        cout << ele << " ";
    }
}
