// Theme: Graph Implementation

//////////////////////////////////////////////////
// Adjacency List (Unoriented)
//////////////////////////////////////////////////

int sz;

vector<vector<int>> graph;

graph.assign(n, {});

for (int i = 0; i < n; i++) {
    int u, v; cin >> u >> v; --u --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
}

//////////////////////////////////////////////////
// Adjacency List (Oriented)
//////////////////////////////////////////////////

int sz;

vector<vector<int>> graph;
vector<vector<int>> rgraph;

graph.assign(n, {});
rgraph.assign(n, {});

for (int i = 0; i < n; i++) {
    int u, v; cin >> u >> v; --u --v;
    graph[u].push_back(v);
    rgraph[v].push_back(u);
}

//////////////////////////////////////////////////
// Edges List (Unoriented)
//////////////////////////////////////////////////

int sz;

vector<pair<int, int>> edges;
vector<vector<int>> graph;

graph.assign(n, {});

for (int i = 0; i < n; i++) {
    int u, v; cin >> u >> v; --u; --v;
    edges.push_back({ u, v });
    graph[u].push_back(i);
    graph[v].push_back(i);
}

//////////////////////////////////////////////////
// Edges List + Structure (Unoriented)
//////////////////////////////////////////////////

struct edge {
    int u, v, w;
    edge(int u, int v, int w = 0) 
         : u(u), v(v), w(w) { }
};

int sz;

vector<edge> edges;
vector<vector<int>> graph;

graph.assign(n, {});

for (int i = 0; i < n; i++) {
    int u, v, w; cin >> u >> v >> w; --u; --v;
    edges.push_back({ u, v, w });
    graph[u].push_back(i);
    graph[v].push_back(i);
}

//////////////////////////////////////////////////
// Edges List + Structure + Net Flows (Oriented)
//////////////////////////////////////////////////

struct edge {
    int to, cap, flow, weight;
    edge(int to, int cap, int flow = 0, int weight = 0) 
         : to(to), cap(cap), flow(flow), weight(weight) { }
    int res() {
        return cap - flow;
    }
};

int sz;

vector<edge> edges;
vector<vector<int>> fgraph;

fgraph.assign(n, {});

void add_edge(int u, int v, int limit, int flow = 0, int weight = 0) {
    fgraph[u].push_back(edges.size());
    edges.push_back({ v, limit, flow, weight });
    fgraph[v].push_back(edges.size());
    edges.push_back({ u, 0, 0, -weight });
}

//////////////////////////////////////////////////
// Adjacency Matrix
//////////////////////////////////////////////////

vector<vector<int>> graph;

for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        cin >> graph[i][j];