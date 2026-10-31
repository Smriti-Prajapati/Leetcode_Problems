class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> dpR(m, vector<long long>(n, 0));
        vector<vector<long long>> dpD(m, vector<long long>(n, 0));

        // Starting position
        dpR[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0) {

                    // Current cell is empty
                    long long ways = (dpR[i][j] + dpD[i][j]) % MOD;

                    // Move right
                    if (j + 1 < n) {
                        dpR[i][j + 1] =
                            (dpR[i][j + 1] + ways) % MOD;
                    }

                    // Move down
                    if (i + 1 < m) {
                        dpD[i + 1][j] =
                            (dpD[i + 1][j] + ways) % MOD;
                    }

                } else {

                    // Current cell is a mirror

                    // Entered from left: reflect downward
                    if (i + 1 < m) {
                        dpD[i + 1][j] =
                            (dpD[i + 1][j] + dpR[i][j]) % MOD;
                    }

                    // Entered from above: reflect right
                    if (j + 1 < n) {
                        dpR[i][j + 1] =
                            (dpR[i][j + 1] + dpD[i][j]) % MOD;
                    }
                }
            }
        }

        return (dpR[m - 1][n - 1] +
                dpD[m - 1][n - 1]) % MOD;
    }
};
