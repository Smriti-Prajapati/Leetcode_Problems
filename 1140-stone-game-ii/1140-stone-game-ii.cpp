class Solution {
public:
    int n;
    int suffix[101];
    int dp[101][101];
    int solve(int i, int M, vector<int>& piles) {
        if (i == n)
            return 0;
        if (dp[i][M] != -1)
            return dp[i][M];
        int ans = 0;
        for (int X = 1; X <= 2 * M && i + X <= n; X++) {
            int newM = max(M, X);
            int opponent = solve(i + X, newM, piles);
            int myScore = suffix[i] - opponent;
            ans = max(ans, myScore);
        }
        return dp[i][M] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suffix[n] = 0;
        for (int i = n - 1; i >= 0; i--)
            suffix[i] = suffix[i + 1] + piles[i];
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, piles);
    }
};