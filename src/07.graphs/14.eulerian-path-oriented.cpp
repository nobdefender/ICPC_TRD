// Theme: Eulerian Path

// Algorithm: Eulerian Path
// Complexity: O(M)

// Algo doesn't validate the path to be correct.
// If the path exists, it will be found.
// Result way has to be reversed after execution.

struct Edge {
    int v, u;
    bool deleted = false;
};

vector<Edge> edges;

vector<deque<int>> graph;
vector<int> way;

void euler(int v, int last = -1) {
    while (!graph[v].empty()) {
        int idx = graph[v].front(); graph[v].pop_front();
        auto& e = edges[idx];
        if (e.deleted) continue;
        e.deleted = true; // If graph is not oriented, also delete reverse edge[v ^ 1]
        euler(e.u, idx);
    }
    if (last != -1) way.push_back(last);
}