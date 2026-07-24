class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;
        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));
        dp[0][0] = true;
        for (int v : nums) {
            for (int k = 1; k <= 3; k++) {
                for (int x = 0; x < MAXX; x++) {
                    if (dp[k - 1][x])
                        dp[k][x ^ v] = true;
                }
            }
        }
        int ans = 0;
        for (bool ok : dp[3])
            ans += ok;
        return ans;
    }
};