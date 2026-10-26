class Solution {
public:
    int m;
    int n;
    vector<vector<bool>> visited;
    long long dfs(vector<vector<int>>& grid,int r,int c){
        //boundary condition
        //grid[r][c]==0 means land so ignore it
        if(r<0 || r>=m ||c<0 ||c>=n ||grid[r][c]==0 || visited[r][c]){
            return 0;
        }
        visited[r][c]=true;
        long long sum=grid[r][c];
        //4 boundary conditions
        sum+=dfs(grid,r-1,c); //up
        sum+=dfs(grid,r+1,c); //down
        sum+=dfs(grid,r,c-1); //left
        sum+=dfs(grid,r,c+1); //right
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        visited.assign(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0 && !visited[i][j]){
                    long long sum=dfs(grid,i,j);
                    if(sum%k==0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};