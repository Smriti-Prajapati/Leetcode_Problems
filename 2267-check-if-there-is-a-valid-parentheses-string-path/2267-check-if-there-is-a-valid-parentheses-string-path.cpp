class Solution {
public:
    bool dfs(int r, int c, int balance,
             vector<vector<char>>& grid,
             vector<vector<vector<int>>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        // Update balance using current cell
        if (grid[r][c] == '(')
            balance++;
        else
            balance--;

        // Balance can never become negative
        if (balance < 0)
            return false;

        // Too many '(' left to close
        int remaining = (m - 1 - r) + (n - 1 - c);

        if (balance > remaining)
            return false;

        // Destination
        if (r == m - 1 && c == n - 1)
            return balance == 0;

        // Already visited this state
        if (dp[r][c][balance] != -1)
            return dp[r][c][balance];

        bool down = false;
        bool right = false;

        // Move down
        if (r + 1 < m)
            down = dfs(r + 1, c, balance, grid, dp);

        // Move right
        if (c + 1 < n)
            right = dfs(r, c + 1, balance, grid, dp);

        return dp[r][c][balance] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Path length must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        // First character must be '('
        if (grid[0][0] == ')')
            return false;

        // Last character must be ')'
        if (grid[m - 1][n - 1] == '(')
            return false;

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(
                n,
                vector<int>(m + n, -1)
            )
        );

        return dfs(0, 0, 0, grid, dp);
    }
};