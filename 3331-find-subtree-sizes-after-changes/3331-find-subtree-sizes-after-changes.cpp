
class Solution {
public:
    vector<vector<int>> adj, newTree;
    vector<int> ans, lastSeen;

    void dfs1(int node, vector<int>& parent, string& s) {
        int ch = s[node] - 'a';
        int prev = lastSeen[ch];

        int newParent = (prev == -1) ? parent[node] : prev;

        if (node != 0) {
            newTree[newParent].push_back(node);
        }

        lastSeen[ch] = node;

        for (int child : adj[node]) {
            dfs1(child, parent, s);
        }

        lastSeen[ch] = prev;
    }

    int dfs2(int node) {
        int size = 1;

        for (int child : newTree[node]) {
            size += dfs2(child);
        }

        ans[node] = size;
        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        adj.resize(n);
        newTree.resize(n);
        ans.resize(n);
        lastSeen.assign(26, -1);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        dfs1(0, parent, s);
        dfs2(0);

        return ans;
    }
};
