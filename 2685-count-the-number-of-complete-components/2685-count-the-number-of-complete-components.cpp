class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        int answer = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int vertexCount = 0;
                int edgeCount = 0;
                dfs(i, adj, visited, vertexCount, edgeCount);
                edgeCount /= 2;
                if (edgeCount == (long long)vertexCount * (vertexCount - 1) / 2) {
                    answer++;
                }
            }
        }
         return answer;
    }
private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited,
             int& vertexCount, int& edgeCount) {
        visited[node] = true;
        vertexCount++;
        edgeCount += adj[node].size(); 
        for (int nei : adj[node]) {
            if (!visited[nei]) {
                dfs(nei, adj, visited, vertexCount, edgeCount);
            }
        }
    }
};