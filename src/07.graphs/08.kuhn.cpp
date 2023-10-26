// Maximum Matching

// Algorithm: Kuhn Algorithm
// Complexity: O(|Left Part|^3)

vector<vector<int>> bigraph;
vector<int> used;

vector<int> mt;

bool kuhn(int u) {
    if (used[u]) return false;

    used[u] = 1;

    for (auto &v : bigraph[u]) {
        if (mt[v] == -1 || kuhn(mt[v])) {
            mt[v] = u;
            return true;
        }
    }

    return false;
}

int main() {
	... чтение графа ...
 
	mt.assign (k, -1);
	for (int v=0; v<n; ++v) {
		used.assign (n, false);
		try_kuhn (v);
	}
 
	for (int i=0; i<k; ++i)
		if (mt[i] != -1)
			printf ("%d %d\n", mt[i]+1, i+1);
}
