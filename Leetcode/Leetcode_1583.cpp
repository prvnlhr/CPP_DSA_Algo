#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int unhappyFriends(int n, vector<vector<int>> &preferences, vector<vector<int>> &pairs)
    {

        int unhappy = 0;
        for (int i = 0; i < pairs.size(); i++)
        {

            int p1 = pairs[i][0];
            int p2 = pairs[i][1];

            int prefP1 = preferences[p1][0];
            int prefP2 = preferences[p2][0];

            if (prefP1 != p2)
            {
                unhappy++;
            }
            if (prefP2 != p1)
            {
                unhappy++;
            }
        }
        return unhappy;
    }
};

int main()
{
    int n = 4;

    // vector<vector<int>> preferences{{1, 2, 3}, {3, 2, 0}, {3, 1, 0}, {1, 2, 0}};
    // vector<vector<int>> pairs{{0, 1}, {2, 3}};

    vector<vector<int>> preferences{{1}, {0}};
    vector<vector<int>> pairs{{1, 0}};

    Solution *obj = new Solution;

    cout << obj->unhappyFriends(n, preferences, pairs) << endl;
    ;
}