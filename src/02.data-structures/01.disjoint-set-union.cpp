// Theme: Disjoint Set Union

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