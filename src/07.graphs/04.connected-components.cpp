// Theme: Connectivity Components

vector<vector<int>> graph;
vector<int> used;

// Algorithm: Connected Components
// Complexity: O(N + M)

vector<vector<int>> cc;

void dfs_cc(int cur, int p = -1) {
    used[cur] = 1;
    cc.back().push_back(cur);

    for (auto &to : graph[cur]) {
        if (to == p || used[to]) continue;
        dfs_cc(to, cur);
    }
}

for (int u = 0; u < n; i++)
    if (!used[u])
        dfs_cc(u);

// Algorithm: Strongly Connected Components
// Complexity: O(N + M)

vector<vector<int>> rgraph;

vector<vector<int>> topsort;

vector<vector<int>> scc;

void dfs_scc(int cur, int p = -1) {
    used[cur] = 1;
    scc.back().push_back(cur);

    for (auto &to : rgraph[cur]) {
        if (to == p || used[to]) continue;
        dfs_scc(to, cur);
    }
}

for (auto &u: topsort)
    if (!used[u])
        dfs_scc(u);
vector<long long int>v_scc;
    v_scc.assign(2 * n, -1);

    for (int i = 0; i < scc.size(); i++)
        for (auto& u : scc[i])
            v_scc[u] = i;

    vector<long long int> values(2 * n, -1);

    for (int i = 0; i < 2 * n; i += 2)
        if (v_scc[i] == v_scc[i ^ 1]) {
            cout << "NO\n";
            return 0;
        }
        else {
            if (v_scc[i] < v_scc[i ^ 1]) {
                values[i] = 0;
                values[i ^ 1] = 1;
            }
            else {
                values[i] = 1;
                values[i ^ 1] = 0;
            }
        }
