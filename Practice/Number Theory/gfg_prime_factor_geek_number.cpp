#include <iostream>
#include <set>

using namespace std;

int geekNumber(int N)
{
    set<int> map;

    for (long long d = 2; d * d <= N; d++)
    {
        while (N % d == 0)
        {

            if (map.find(d) != map.end())
            {
                return 0;
            }
            else
            {
                map.insert(d);
            }
            N /= d;
        }
    }
    return 1;
}

int main()
{

    int n;
    cin >> n;
    int ans = geekNumber(n);
    if (ans)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}