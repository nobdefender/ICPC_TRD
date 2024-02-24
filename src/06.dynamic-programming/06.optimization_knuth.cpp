for (int ki = 2; ki <= k; ki++) {
        for (int ni = n - 1; ni >= 0; ni--) {
            int from = opt[ki - 1][ni]; 
            int to = opt[ki][ni + 1]; 
            for (int i = from; i <= to; i++) {
                if (i + 1 < n && dp[ki][ni] > dp[ki - 1][i] + cost[min(i+1,ni)][max(i+1,ni)]) {
                    dp[ki][ni] = dp[ki - 1][i] + cost[min(i+1, ni)][max(i+1, ni)];
                    opt[ki][ni] = i;
                }
            }
        }
    }

//if
