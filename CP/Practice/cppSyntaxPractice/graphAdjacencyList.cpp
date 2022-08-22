#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &adjList, vector<bool> &visited, vector<int> &dfsPath)
{

    dfsPath.push_back(node);

    visited[node] = true;

    for (auto adjNode : adjList[node])
    {
        if (!visited[adjNode])
        {
            dfs(adjNode, adjList, visited, dfsPath);
        }
    }
}

int main()
{

    int V, E;
    cin >> V >> E;
    // Input: V = 4, E = 6
    // 2 -> 0, 0 -> 2, 1 -> 2, 0 -> 1, 3 -> 3, 1 -> 3
    // Output: DFS from vertex 2 : 2 0 1 3

    vector<vector<int>> adjList(V + 1);

    cout << adjList.size() << endl;

    // vector<int> adjList[edges + 1];

    int u, v;
    for (int i = 0; i < E; i++)
    {
        cout << "enter edge : " << i << endl;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<bool> visited(V + 1, false);

    vector<int> dfsPath;
    int startVertex = 2;
    dfs(startVertex, adjList, visited, dfsPath);
    // for (int v = 1; v <= V; v++)
    // {
    // if (!visited[v])
    // {
    // }
    // }

    for (auto ele : dfsPath)
    {
        cout << ele << " ";
    }
}

// create a adjacency List, using arr[] which stores vector<int>
//  [{},{},{},{}]

// vector<int> adjList[n];