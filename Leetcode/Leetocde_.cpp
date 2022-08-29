#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        vector<int> res(boxes.length());

        //> O(N^2)
        for (int i = 0; i < boxes.length(); i++)
        {

            int op = 0;
            for (int j = 0; j < boxes.length(); j++)
            {

                if (i != j && boxes[j] == '1')
                {
                    op = op + abs(i - j);
                }
            }
            res[i] = op;
        }

        //> SOLUTION 2 : Two passes using prefix array technique O(N)

        /*
         * We used a prefix array from left to right and vice versa.
         * first we calculate the answer from right to left and store it in ans array
         * then we calculate it from left to right and updaate the ans array.
         * To better understand we need  to dry run a  case and see how ans is being calculate
         * in each step. We keeps on adding the previously calculate ans the current ans.
         * Conclusion : we see that ans at ith pos ==  count of balls at ith + previous cost taken.
         */

        vector<int> ans(boxes.length(), 0);
        int n = boxes.size();

        int ballCnt = 0;
        int step = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            step = step + ballCnt;

            ans[i] = ans[i] + step;
            if (boxes[i + 1] == '1')
            {
                ballCnt++;
            }
        }

        step = 0;
        ballCnt = 0;
        for (int i = 1; i < n; i++)
        {

            step = step + ballCnt;
            ans[i] = ans[i] + step;
            if (boxes[i - 1] == '1')
            {
                ballCnt++;
            }
        }

        return res;
    }
};
int main()
{

    Solution *obj = new Solution();
    string s;
    cin >> s;
    auto res = obj->minOperations(s);
    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << endl;
}