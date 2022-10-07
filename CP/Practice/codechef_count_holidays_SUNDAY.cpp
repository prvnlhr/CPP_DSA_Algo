#include <iostream>
#include <vector>
#include <set>
// #define ll long long
using namespace std;

set<int> s = {6, 13, 20, 27, 7, 14, 21, 28};

int main()
{

    // int t;
    // cin >> t;

    // while (t--)
    // {

    //     int n;
    //     cin >> n;

    //     vector<int> holidays;

    //     for (int i = 0; i < n; i++)
    //     {
    //         int u;
    //         cin >> u;
    //         holidays.push_back(u);
    //     }

    //     int holidayCount = 8;

    //     holidayCount = holidayCount + holidays.size();

    //     for (auto x : holidays)
    //     {
    //         if (s.find(x) != s.end())
    //         {
    //             holidayCount--;
    //         }
    //     }
    //     cout << holidayCount << endl;
    // }
}

/*
* ANOTHER SOLUTION
#include <iostream>
#include <vector>
#include <set>
#define ll long long
using namespace std;
int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        set<int> s = {6, 13, 20, 27, 7, 14, 21, 28};

        for (int i = 0; i < n; i++)
        {
            int u;
            cin >> u;
            s.insert(u);
        }
        cout << s.size() << endl;
    }
}

 */