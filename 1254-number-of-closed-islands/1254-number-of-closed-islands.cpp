class Solution {
public:
    int m;
    int n;
    //step 1 is make a dfs function
    bool dfs(vector<vector<int>> &grid, int r, int c){
        //check boundary conditions
        if(r<0 || r>=m || c<0 ||c>=n){
            return false;
        }
        //skip water part so turn it to true
        if(grid[r][c]==1){
            return true;
        }
        grid[r][c]=1; //mark as visited
        //check all four conditions
        bool up=dfs(grid,r-1,c);
        bool down=dfs(grid,r+1,c);
        bool left=dfs(grid,r,c-1);
        bool right=dfs(grid,r,c+1);
        
        return up && down && left && right;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    //call dfs function
                    if(dfs(grid,i,j)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};