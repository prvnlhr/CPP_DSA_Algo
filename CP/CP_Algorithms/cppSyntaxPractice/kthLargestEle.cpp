#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int j = k; j < arr.size(); j++)
    {
        if (arr[j] > pq.top())
        {
            pq.pop();
            pq.push(arr[j]);
        }
    }
    return pq.top();
}

int main()
{

    int n, a;
    vector<int> arr{9, 4, 8, 7, 11, 3};
    // vector<int> arr{2, 6, 10, 11, 13, 4, 1, 20};
    // cin >> n;

    // while (n--)
    // {

    //     cin >> a;
    //     arr.push_back(a);
    // }
    // cin >> k;
    int k = 2;
    // int k = 4;
    int ans = kthLargest(arr, k);
    cout << ans;
}