// Theme: Lowest Common Ancestor

// Algorithm: Binary Lifting
// Complextiry: Preprocessing O(N * log(N)) and request O(log(N))

vector<vector<int>> g;
vector<int> d;
vector<vector<int>> dp;
vector<int> used;

void dfs(int v, int p = -1) {
  if (p == -1) {
    p = v;
    d[v] = 0;
  } else {
    d[v] = d[p] + 1;
  }

  dp[0][v] = p;
  for (int i = 1; i < dp.size(); i++) {
    dp[i][v] = dp[i - 1][dp[i - 1][v]];
  }
  for (int to : g[v]) {
    if (to != p) {
      dfs(to, v);
    }
  }
}

int lca(int a, int b) {
  if (d[a] > d[b]) {
    swap(a, b);
  }

  for (int i = dp.size() - 1; i >= 0; i--) {
    if (d[dp[i][b]] >= d[a]) {
      b = dp[i][b];
    }
  }

  if (a == b) {
    return a;
  }

  for (int i = dp.size() - 1; i >= 0; i--) {
    if (dp[i][a] != dp[i][b]) {
      a = dp[i][a];
      b = dp[i][b];
    }
  }

  return dp[0][a];
}

signed main() {
  int n = 0, m = 0; // n - vertex count, m - requests
  g.resize(n);
  d.resize(n);
  dp.resize(((int)log2(n) + 1));
  used.assign(n, 0);
  for (int i = 0; i < dp.size(); i++) {
    dp[i].resize(n);
  }

  // ...reading graph...

  dfs(0);

  // ...lca(u -1, v - 1) + 1
}