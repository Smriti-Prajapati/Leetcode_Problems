class Solution {
public:
    //create a  dfs function
    int m;
    int n;
    bool dfs(vector<vector<int>> &grid,int r,int c){
        //boundary conditions
        if(r<0 || r>=m ||c<0 ||c>=n){
            return true;
        }
        //if water skip
        if(grid[r][c]==1){
            return true;
        }
        //mark as visited
        grid[r][c]=1;
        //now check all four directions, up, down , left and right
        bool up=dfs(grid,r-1,c);
        bool down=dfs(grid,r+1,c);
        bool left=dfs(grid,r,c-1);
        bool right=dfs(grid,r,c+1);
        bool inside = (r>0 && r<m-1 && c>0 &&c<n-1);
        return inside && up && down && left && right;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    if(dfs(grid,i,j)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};