class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // visited[r][c][remaining]
        vector<vector<vector<bool>>> visited(
            m,
            vector<vector<bool>>(
                n,
                vector<bool>(k + 1, false)
            )
        );

        queue<tuple<int, int, int>> q;

        // Start at (0, 0) with k eliminations available
        q.push({0, 0, k});
        visited[0][0][k] = true;

        int steps = 0;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            int size = q.size();

            // Process all states at the current distance
            while (size--) {
                auto [r, c, remaining] = q.front();
                q.pop();

                // Reached destination
                if (r == m - 1 && c == n - 1) {
                    return steps;
                }

                // Try 4 directions
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    // Outside grid
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                        continue;
                    }

                    int newRemaining = remaining;

                    // If next cell is an obstacle
                    if (grid[nr][nc] == 1) {
                        newRemaining--;
                    }

                    // Can't eliminate more obstacles
                    if (newRemaining < 0) {
                        continue;
                    }

                    // Already visited this exact state
                    if (visited[nr][nc][newRemaining]) {
                        continue;
                    }

                    visited[nr][nc][newRemaining] = true;

                    q.push({nr, nc, newRemaining});
                }
            }

            // All moves in this level cost 1
            steps++;
        }

        return -1;
    }
};