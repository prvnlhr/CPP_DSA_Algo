

#include <iostream>
#include <vector>
#include <set>
using namespace std;
// if (map.find(i) != map.end())
// {
//     return 0;
// }
// else
// {
//     map.insert(i);
// }
int geekNumber(int N)
{

    set<int> map;

    for (int i = 2; i * i <= N; i++)
    {

        if (N % i == 0)
        {
            cout << i << " ";
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
