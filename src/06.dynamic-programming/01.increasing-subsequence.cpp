// Theme: Longest Increasing Subsequence

// Algorithm: LIS via binary search
// Complexity: O(N*log(N))

vector<int> lis(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n + 1, INF); dp[0] = -INF;
    vector<int> pos(n + 1, -1), previous(n, -1);
    int length = 0;
    for (int i = 0; i < n; ++i) {
        int j = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        if (dp[j - 1] < arr[i] && arr[i] < dp[j]) {
            dp[j] = arr[i];
            pos[j] = i;
            previous[i] = pos[j - 1];
            length = max(length, j);
        }
    }

    vector<int> res;
    int p = pos[length];
    while (p != -1) {
        res.push_back(arr[p]);
        p = previous[p];
    }
    reverse(res.begin(), res.end());
    return res;
}
