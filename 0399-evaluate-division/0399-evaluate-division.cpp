class Solution {
public:
    double dfs(string src, string dest, unordered_map<string, vector<pair<string, double>>> &adj,unordered_map<string, bool> &vis, double product){
        if(src== dest)
            return product;
        vis[src]= true;
        for(auto it: adj[src]){
            string next= it.first;
            double value= it.second;
            if(!vis[next]){
                double ans= dfs(next,dest, adj,vis, product*value);
                if(ans!= -1.0){
                    return ans;
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        for(int i=0; i<equations.size(); i++){
            string u= equations[i][0];
            string v= equations[i][1];
            adj[u].push_back({v, values[i]});
            adj[v].push_back({u, 1.0/values[i]});
        }
        vector<double> res;
        for(auto q: queries){
            string src= q[0];
            string dest= q[1];
            if(adj.find(src)== adj.end() || adj.find(dest)== adj.end()){
                res.push_back(-1.0);
                continue;
            }
            unordered_map<string, bool> vis;
            res.push_back(dfs(src, dest, adj, vis, 1.0));
        }
        return res;
    }
};