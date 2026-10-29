
class Solution {
    int LOG;
    int timer;
    vector<vector<int>> adj, up;
    vector<int> tin, tout;
    vector<int> baseMask;
    
    class Fenwick {
        int n;
        vector<int> bit;

    public:
        Fenwick(int size) {
            n = size;
            bit.assign(n + 2, 0);
        }

        void add(int idx, int val) {
            while (idx <= n) {
                bit[idx] ^= val;
                idx += idx & -idx;
            }
        }

        int query(int idx) {
            int ans = 0;
            while (idx > 0) {
                ans ^= bit[idx];
                idx -= idx & -idx;
            }
            return ans;
        }

        void rangeXor(int l, int r, int val) {
            add(l, val);
            if (r + 1 <= n)
                add(r + 1, val);
        }
    };

    int getMask(char c) {
        return 1 << (c - 'a');
    }

    void dfs(int u, int p, string &s) {
        tin[u] = ++timer;

        up[u][0] = (p == -1 ? u : p);

        for (int j = 1; j < LOG; j++) {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }

        baseMask[u] = getMask(s[u]);

        if (p != -1)
            baseMask[u] ^= baseMask[p];

        for (int v : adj[u]) {
            if (v == p)
                continue;

            dfs(v, u, s);
        }

        tout[u] = timer;
    }

    int lca(int u, int v) {
        if (up[u][0] == u && up[v][0] == v) {
            // No special handling is needed for the root.
        }

        if (u == v)
            return u;

        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j))
                u = up[u][j];
        }

        if (u == v)
            return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    vector<int> depth;

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        timer = 0;

        adj.assign(n, {});
        up.assign(n, vector<int>(LOG, 0));
        tin.assign(n, 0);
        tout.assign(n, 0);
        baseMask.assign(n, 0);
        depth.assign(n, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Build DFS order, depths and root-to-node prefix masks.
        function<void(int, int)> build = [&](int u, int p) {
            tin[u] = ++timer;

            up[u][0] = (p == -1 ? u : p);
            depth[u] = (p == -1 ? 0 : depth[p] + 1);

            for (int j = 1; j < LOG; j++)
                up[u][j] = up[up[u][j - 1]][j - 1];

            baseMask[u] = getMask(s[u]);
            if (p != -1)
                baseMask[u] ^= baseMask[p];

            for (int v : adj[u]) {
                if (v != p)
                    build(v, u);
            }

            tout[u] = timer;
        };

        build(0, -1);

        Fenwick fw(n);
        vector<bool> answer;

        for (string &q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;

                int change = getMask(s[u]) ^ getMask(c);

                // Every root-to-node path in u's subtree changes.
                fw.rangeXor(tin[u], tout[u], change);

                s[u] = c;
            } else {
                int u, v;
                ss >> u >> v;

                int w = lca(u, v);

                int pu = baseMask[u] ^ fw.query(tin[u]);
                int pv = baseMask[v] ^ fw.query(tin[v]);

                int mask = pu ^ pv ^ getMask(s[w]);

                // True if zero or one character has odd frequency.
                answer.push_back((mask & (mask - 1)) == 0);
            }
        }

        return answer;
    }
};
