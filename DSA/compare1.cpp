void dfs(vector<int> adjList[], vector<int> &visited, stack<int> &st, int node)
{

    visited[node] = 1;

    for (auto adjNode : adjList[node])
    {
        if (!visited[adjNode])
        {
            dfs(adjList, visited, st,adjNode);
        }
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adjList[])
{
    stack<int> st;
    vector<int> visited(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            dfs(adjList, visited, st, i);
        }
    }

    vector<int> res;
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}
