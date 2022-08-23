#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries)
    {

        vector<int> res(queries.size());

        for (int i = 0; i < queries.size(); i++)
        {
            int x1 = queries[i][0];
            int y1 = queries[i][1];
            int rad = queries[i][2];

            for (int j = 0; j < points.size(); j++)
            {

                int x2 = points[j][0];
                int y2 = points[j][1];

                if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= rad * rad)
                {
                    res[i]++;
                }
            }
        }

        return res;
    }
};

int main()
{

    Solution *obj = new Solution();
    vector<vector<int>> point{{1, 3}, {3, 3}, {5, 3}, {2, 2}};
    vector<vector<int>> circles{{2, 3, 1}, {4, 3, 1}, {1, 1, 2}};

    // vector<vector<int>> point{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    // vector<vector<int>> circles{{1, 2, 2}, {2, 2, 2}, {4, 3, 2}, {4, 3, 3}};

    auto res = obj->countPoints(point, circles);
    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << "\n";
}