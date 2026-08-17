class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        // Prefix sum
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }

        // dp[l][r] = maximum score obtainable from [l, r]
        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        // Length of interval
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len <= n; l++) {
                int r = l + len - 1;

                // Try every split
                for (int k = l; k < r; k++) {
                    long long leftSum = pref[k + 1] - pref[l];
                    long long rightSum = pref[r + 1] - pref[k + 1];

                    if (leftSum < rightSum) {
                        // Right part is discarded
                        dp[l][r] = max(
                            dp[l][r],
                            leftSum + dp[l][k]
                        );
                    }
                    else if (leftSum > rightSum) {
                        // Left part is discarded
                        dp[l][r] = max(
                            dp[l][r],
                            rightSum + dp[k + 1][r]
                        );
                    }
                    else {
                        // Equal: Alice chooses which side to keep
                        dp[l][r] = max(
                            dp[l][r],
                            leftSum + max(dp[l][k], dp[k + 1][r])
                        );
                    }
                }
            }
        }

        return (int)dp[0][n - 1];
    }
};