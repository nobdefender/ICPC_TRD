// Theme: 2-SAT

// Algorithm: Adding Edges To 2-SAT

vector<vector<int>> ts_graph;
vector<vector<int>> ts_rgraph;
vector<int>used;
vector<int>top_sort;

// Vertex By Var Number 
int to_vert(int x) {
    if (x < 0) {
        return ((abs(x) - 1) << 1) ^ 1;
    }
    else {
        return (x - 1) << 1;
    }
}

// Adding Implication
void add_impl(int a, int b) {
    ts_graph[a].insert(b);
    ts_rgraph[b].insert(a);
}

// Adding Disjunction
void add_or(int a, int b) {
    add_impl(a ^ 1, b);
    add_impl(b ^ 1, a);
}

//topsort
void dfs(int v){
    used[v] = 1;
    for(auto to:ts_graph[v]){
        if(!used[to])dfs(to);
    top_sort.push_back(v);
}

//scc
vector<vector<long long int>> scc;
void dfs_scc(long long int cur, long long int p = -1) {
    used[cur] = 1;
    scc.back().push_back(cur);
    for (auto to : rgr[cur]) {
        if (to == p || used[to]) continue;
        dfs_scc(to, cur);
    }
}

int main(){
    ...
    used.resize(n,0);
    for(i=0;i<n;i++){
        if(!used[i])dfs(i);
    }
    reverse(top_sort.begin(), top_sort.end());
    for(auto it:top_sort){
        if (!used[u]) {
            scc.push_back({});
            dfs_scc(u);
        }
    }
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
}
