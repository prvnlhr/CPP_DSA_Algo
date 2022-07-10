

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void dijKstraHelper(vector<vector<pair<int, int>>> &adjList, vector<int> &distArray, int src)
{

    distArray[src] = 0;

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_heap;

    min_heap.push({0, src});

    while (!min_heap.empty())
    {
        auto parent_node = min_heap.top();
        min_heap.pop();

        for (auto adjNode : adjList[parent_node[1]])
        {

            int prnt_node_wt = parent_node[0];
            int adj_node_wt = adjNode.second;
            int dist_of_adjNode = prnt_node_wt + adj_node_wt;
            int curr_distArray_adjNode_dist = distArray[adjNode.first];

            if (dist_of_adjNode < curr_distArray_adjNode_dist)
            {
                distArray[adjNode.first] = dist_of_adjNode;
                min_heap.push({dist_of_adjNode, adjNode.first});
            }
        }
    }
}

vector<int> dijkstra(vector<vector<pair<int, int>>> &adjList, int src, int V)
{

    vector<int> distArray(V, INT_MAX);
    dijKstraHelper(adjList, distArray, src);
    return distArray;
}

int main()
{

    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> adjList(V + 1);

    int u, v, w;

    for (int i = 0; i < E; i++)
    {

        cin >> u >> v >> w;

        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    int src_node;

    cout << "Enter source node" << endl;
    cin >> src_node;

    auto res = dijkstra(adjList, src_node, V);

    for (int j = 0; j < res.size(); j++)
    {
        cout << j << " " << res[j] << endl;
    }
}