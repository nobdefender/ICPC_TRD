// Theme: Fenwick Tree
// Core operations are O(log n)

struct Fenwick {
    vector<int> data;

    explicit Fenwick(int n) {
        data.assign(n + 1, 0);
    }
    explicit Fenwick(vector<int>& arr): Fenwick(arr.size()) {
        for (int i = 1; i <= arr.size(); ++i) {
            add(i, arr[i - 1]);
        }
    }

    // Nested loops (also vector) for multi-dimensional. Also in add().
    // (x & -x) = last non-zero bit
    int sum(int right) {
        int res = 0;
        for (int i = right; i > 0; i -= (i & -i)) {
            res += data[i];
        }
        return res;
    }
    int sum(int left, int right) {
        return sum(right) - sum(left - 1); // inclusion-exclusion principle
    }

    void add(int idx, int x) {
        for (int i = idx; i < data.size(); i += (i & -i)) {
            data[i] += x;
        }
    }

    // Works if all values are non-negative.
    int lower_bound(int s) {
        int k = 0;
        int logn = (int)(log2(data.size() - 1) + 1); // rewrite this line?
        for (int b = logn; b >= 0; --b) {
            if (k + (1 << b) < data.size() && data[k + (1 << b)] < s) {
                k += (1 << b);
                s -= data[k];
            }
        }
        return k + 1;
    }
};