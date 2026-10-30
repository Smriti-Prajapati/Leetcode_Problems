class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                string labels, int k) {

        // Step 1: Build adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        // Step 2: Initialize distance array
        const long long INF = LLONG_MAX;

        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, INF)
        );

        // Step 3: Min heap
        // {distance, node, consecutive count}
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        // Step 4: Starting state
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        // Step 5: Dijkstra
        while (!pq.empty()) {

            auto [d, u, cnt] = pq.top();
            pq.pop();

            // Ignore outdated states
            if (d != dist[u][cnt])
                continue;

            // Destination reached
            if (u == n - 1)
                return (int)d;

            // Explore adjacent nodes
            for (auto &[v, wt] : adj[u]) {

                int newCnt;

                if (labels[u] == labels[v])
                    newCnt = cnt + 1;
                else
                    newCnt = 1;

                // Check constraint
                if (newCnt > k)
                    continue;

                long long newDist = d + wt;

                // Relaxation
                if (newDist < dist[v][newCnt]) {

                    dist[v][newCnt] = newDist;

                    pq.push({
                        newDist,
                        v,
                        newCnt
                    });
                }
            }
        }

        return -1;
    }
};