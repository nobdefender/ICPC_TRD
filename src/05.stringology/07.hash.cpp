// Algorithm: String hash

#define int long long

struct Hasher {
    int n;
    int P1, MOD1;
    int P2, MOD2;
    vector<string> str;
    vector<int> p1, p2;
    vector<vector<int>> h1, h2;

    Hasher(int n, int P1, int MOD1, int P2, int MOD2): n(n), P1(P1), MOD1(MOD1), P2(P2), MOD2(MOD2), p1(n + 1, 1), p2(p1) {
        for (int i = 1; i <= n; ++i) {
            p1[i] = p1[i - 1] * P1 % MOD1;
            p2[i] = p2[i - 1] * P2 % MOD2;
        }
    }

    pair<int, int> calc(const string& s) const {
        pair<int, int> res = {0, 0};
        for (auto& c: s) {
            res.first = (res.first * P1 + (c + 1)) % MOD1;
            res.second = (res.second * P2 + (c + 1)) % MOD2;
        }
        return res;
    }

    void add(const string& s) {
        assert((int)s.size() <= n);
        int j = (int)h1.size();
        str.push_back(s);
        h1.push_back(vector<int>(n + 1, 0));
        h2.push_back(h1.back());
        for (int i = 1; i <= (int)s.size(); ++i) {
            h1[j][i] = (h1[j][i - 1] * P1 + (s[i - 1] + 1)) % MOD1;
            h2[j][i] = (h2[j][i - 1] * P2 + (s[i - 1] + 1)) % MOD2;
        }
    }

    // 0-indexation here
    [[nodiscard]] pair<int, int> get(int idx, int left, int right) const {
        return {
                (h1[idx][right + 1] - h1[idx][left] * p1[right + 1 - left] % MOD1 + MOD1) % MOD1,
                (h2[idx][right + 1] - h2[idx][left] * p2[right + 1 - left] % MOD2 + MOD2) % MOD2
        };
    }

    int max_common_prefix(int idx1, int left1, int right1, int idx2, int left2, int right2) const {
        int left = 0, right = min(right1 - left1, right2 - left2) + 2;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (get(idx1, left1, left1 + mid - 1) == get(idx2, left2, left2 + mid - 1)) left = mid;
            else right = mid;
        };
        return left;
    }

    int max_common_suffix(int idx1, int left1, int right1, int idx2, int left2, int right2) const {
        int left = 0, right = min(right1 - left1, right2 - left2) + 2;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (get(idx1, right1 - mid + 1, right1) == get(idx2, right2 - mid + 1, right2)) left = mid;
            else right = mid;
        }
        return left;
    }

    bool compare_less(int idx1, int left1, int idx2, int left2, int sz) const {
        int mx = max_common_prefix(idx1, left1, left1 + sz - 1, idx2, left2, left2 + sz - 1);
        if (mx == sz) return false;
        return str[idx1][left1 + mx] < str[idx2][left2 + mx];
    }
};
