/*


"""
READ BELOW ARTICLE FOR BETTER UNDERSTANDING
https://brilliant.org/wiki/shortest-path-algorithms/

"""
CONCLUSION:
1. unweighted or same weighted graph, src to dest shorted path -> Modified BFS







# NOTE::
>The shortest path problem is about finding a path between 2 vertices in a graph such that
> the total sum of the edges weights is minimum.

-> 1 . BFS
       This problem could be solved easily using (BFS) (see 7.1 problem) ,
       if all edge weights were (1) or UNWEIGHTED graph,

       But here weights can take any value.


Three different algorithms are discussed below depending on the use-case.

2.Bellman Ford's Algorithm:
Bellman Ford's algorithm is used to find the shortest paths
from the source vertex to all other vertices in a weighted graph.
The graph may contain NEGATIVE weight edges.

It depends on the following concept that:
Shortest path contains at most n-1 edges, because the shortest path couldn't have a cycle.

So why shortest path shouldn't have a cycle ?
There is no need to pass a vertex again, because the shortest path to all other
vertices could be found without the need for a second visit for any vertices.
Time Complexity of Bellman Ford algorithm is relatively high O(V * E), in case .
Let's discuss an optimized algorithm.

3 .Dijkstra's Algorithm

Dijkstra's algorithm has many variants but the most common one
is to find the shortest paths from the source vertex to all other vertices in the graph.

Time Complexity of Dijkstra's Algorithm is O(V^2)
but with min-priority queue , it drops to O(V + E * logV) .


However, if we have to find the shortest path between all pairs of vertices,
both of the above methods would be expensive in terms of time.

4 .Floyd Warshall's Algorithm

Floyd Warshall's Algorithm  is used to find the shortest paths  between
all pairs of vertices in a graph, where each edge in the graph has a weight
which is positive or negative.The biggest advantage of using this algorithm
is that all the shortest distances between any 2 vertices could be
calculated in O(v^3), where V is the number of vertices in a graph.

*/