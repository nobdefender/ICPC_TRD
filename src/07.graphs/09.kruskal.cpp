#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct dsu {
    vector<int> p, size;

    dsu(int n) {
        p.assign(n, 0); size.assign(n, 0);
        for (int i = 0; i < n; i++) {
            p[i] = i;
            size[i] = 1;
        }
    }

    int get(int v) {
        if (p[v] != v) p[v] = get(p[v]);
        return p[v];
    }

    void unite(int u, int v) {
        auto x = get(u), y = get(v);
        if (x == y) return;
        if (size[x] > size[y]) swap(x, y);
        p[x] = y; size[y] += size[x];
    }
};

int sz;

struct edge {
    long long int u, v, w;
    edge(long long int uu, long long int vv, long long int ww) :u(uu), v(vv), w(ww) {};
};

vector<edge> edges;
vector<vector<int>> graph;

// Algorithm: Kruskal Algorithm
// Complexity: O(M)

vector<edge> mst;

void kruskal() {
    dsu d(sz);

    auto tedges = edges;
    sort(tedges.begin(), tedges.end(), [](edge& e1, edge& e2) { return e1.w < e2.w; });

    for (auto& e : tedges) {
        if (d.get(e.u) != d.get(e.v)) {
            mst.push_back(e);
            d.unite(e.u, e.v);
        }
    }
}

int main() {
    long long int n, m, i, j, k,a,b,c;
    cin >> n >> m;
    for (i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--; b--;
        edge e(a, b, c);
        edges.push_back(e);
    }
    sz = n;
    kruskal();
    long long int ans = 0;
    for (auto it : mst)ans += it.w;
    cout << ans;
}
