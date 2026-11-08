class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        //initialize number of rows and columns
        int m=grid.size();
        int n=grid[0].size();
        //make vector for rowCount and colCount
        vector<int>rowCount(m,0);
        vector<int>colCount(n,0);
        //count how many servers are there in rows and columns
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        //count how many servers can communicate
        //initialize ans variable
        int ans=0;
        //now traverse again
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && (rowCount[i]>1 || colCount[j]>1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};