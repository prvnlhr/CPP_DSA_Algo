#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <climits>
using namespace std;

#define FOR(i, start, end) for (int i = start; i < end; i++)
#define RFOR(i, start, end) for (int i = end; i >= start; i--)
#define FOREACH(x, b) for (auto x : b)

#define COUT(x) cout << x << endl;
#define N << endl;

typedef vector<int> vi;
typedef vector<int> vl;
typedef set<int> stint;
typedef map<int, int> mpint;
typedef pair<int, int> pi;

/*
t = 1 --> t test cases
n = 6 --> total number of employees
k = 8 --> number of pairs

u | v
--| -
6 | 2   u knows v      (u) -> (v)
5 | 4
3 | 1
5 | 2
3 | 6
2 | 1
6 | 1
2 | 3

TASK :
1. Find no of departments.
2. print employees according to their depart.
3. Print all department heads.

> INTUITION:
* Well, we are given employees pair -> u, v , means u knows v.
* We first we represent all pairs in graph adjList.
* 1. Now, the main idea is that, in an particular department, let say d, the department head has
* max degree( no. of direct connections) because  head also know other deps heads along with its employees,
* but employess only know other empl of that dep, so employees has degree less then then d's head.
* 2. We knnow that the all heads of each departments know each other.
* 3. Let say we some how found all the heads, from adjList, then we just need to find the direct connection of that head, and all we be empl of same dept.
* So the problem boils down to find 1. All heads  2. All heads employee
* Now How to find all Heads ??
* Well while making the adjList we can find degree of every vertex.
* We then choose minDeg vertex.
* Now, for all the direct connection to this minDeg, mark all adjacent nodes visited(in visited array) except a which vertex has degree greater
* then this minDeg vertex and that is our first head(leader).
* Now, all the adjacent connections to this found leader, which are not marked visited will be leaders.
* So we found all our leaders, in leaders array.
*
* No maintain a department array and mark all leaders one by one, depArr[leader] with thier dept Number, 1,2,3 ...so on.
* For all leader one by one from adjList bring all adjacent node, and mark thier dep no in depArr same as thier leader, but only if is marked -1 previously.
* Thus we found all leader, no of  leader and all employess with their respective dept.



 */

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        int k;
        cin >> k;

        //>adjList -> graph
        vector<vector<int>> adjList(n + 1);

        //> This will store degree of every vertex
        vector<int> deg(n + 1, 0);

        for (int i = 1; i <= k; i++)
        {

            int u, v;
            cin >> u >> v;
            //> Put in adjList
            adjList[u].push_back(v);
            adjList[v].push_back(u);

            //> mark thier degree
            deg[u]++;
            deg[v]++;
        }

        int minDeg = INT_MAX;
        int minVertex = -1;

        //> This loop will find the 'minDeg' and 'minDeg vertex'
        for (int i = 1; i < n + 1; i++)
        {
            if (deg[i] < minDeg)
            {
                minDeg = deg[i];
                minVertex = i;
            }
        }

        //> Visited array to marked all nodes that are visited
        vector<bool> visited(n + 1, false);

        //> Initially mark minDeg vertex
        visited[minVertex] = true;

        //> This will store all the leaders, which we will find
        vector<int> leaders;

        //> Variable to store our first leader
        int leader = 0;

        //> for the found minDeg vertex, mark all its adjacent nodes visited -> true, except the node with higher degree

        for (auto node : adjList[minVertex])
        {

            if (deg[node] == deg[minVertex])
            {

                visited[node] = true;
            }
            else
            {
                //>this is our first leader
                leaders.push_back(node);
                leader = node;
            }
        }

        //> Edge case: if leader value still zero, means we didnt find any leader,
        //> we have only 1 department.
        if (leader == 0)
        {
            cout << 1 << endl;
            for (int i = 1; i <= n; i++)
            {
                cout << 1 << " ";
            }
            cout << endl;

            cout << adjList[1][0] << endl;
        }
        //> else we found a leader, more then one dept
        else
        {

            //> finding all the leader, adjacent to the first found leader.

            for (auto node : adjList[leader])
            {

                if (visited[node] == false)
                {
                    leaders.push_back(node);
                }
            }

            vi deparmentArr(n + 1, -1);

            // > sorting the leader array to meet the answer format, not compulsory.
            sort(leaders.begin(), leaders.end());

            //> marking all the leader in depArr with with depNo.
            int depNo = 1;
            for (auto x : leaders)
            {
                deparmentArr[x] = depNo++;
            }

            //> Marking all the employee of all leaders with dept No same as the laader

            for (auto ldr : leaders)
            {
                for (auto emp : adjList[ldr])
                {
                    if (deparmentArr[emp] == -1)
                    {
                        deparmentArr[emp] = deparmentArr[ldr];
                    }
                }
            }

            //> ANSWER Printing stuff

            cout << leaders.size() << endl; //> printing no of dept

            //> printing all the employee with thier resp. depts
            for (int i = 1; i < n + 1; i++)
            {
                cout << deparmentArr[i] << " ";
            }
            cout << endl;

            //> finally priting all leaders
            for (auto x : leaders)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
}
