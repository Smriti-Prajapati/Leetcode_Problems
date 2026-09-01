class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;
        vector<pair<int, int>> litter;

        // Locate S and all L cells.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        // No litter to collect.
        if (k == 0) return 0;

        // Map each litter cell to a bit.
        vector<vector<int>> id(m, vector<int>(n, -1));
        for (int i = 0; i < k; i++) {
            id[litter[i].first][litter[i].second] = i;
        }

        /*
            State:
            (r, c, mask, e)

            mask: collected litter
            e: remaining energy
        */

        // visited[r][c][mask][energy]
        // Use a flat vector to save memory.
        int masks = 1 << k;
        int totalStates = m * n * masks * (energy + 1);

        vector<char> visited(totalStates, false);

        auto getId = [&](int r, int c, int mask, int e) {
            return (((r * n + c) * masks + mask) * (energy + 1) + e);
        };

        queue<tuple<int, int, int, int>> q;

        int startMask = 0;
        int startEnergy = energy;

        visited[getId(sr, sc, startMask, startEnergy)] = true;
        q.push({sr, sc, startMask, startEnergy});

        int moves = 0;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();

                // All litter collected.
                if (mask == masks - 1)
                    return moves;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    // Moving costs 1 energy.
                    if (e == 0)
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    // Collect litter if this cell has one.
                    if (classroom[nr][nc] == 'L') {
                        int bit = id[nr][nc];
                        nmask |= (1 << bit);
                    }

                    // Reset energy upon reaching R.
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    int stateId = getId(nr, nc, nmask, ne);

                    if (!visited[stateId]) {
                        visited[stateId] = true;
                        q.push({nr, nc, nmask, ne});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};