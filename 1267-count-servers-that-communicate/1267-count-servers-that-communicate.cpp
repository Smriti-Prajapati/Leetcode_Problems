class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        //initialize how many rows and cols are there
        int m=grid.size();
        int n=grid[0].size();
        //create vector for rowCount and colCount
        vector<int>rowCount(m,0);
        vector<int>colCount(n,0);
        //traverse to count the number of rows and columns in which server is present
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        //initialize ans variable
        int ans=0;
        //count how many servers are there which can communicate
        //traverse again
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //rowCount>1 || colCount>1 means server can communicate if more than one are there
                if(grid[i][j]==1 && (rowCount[i]>1 || colCount[j]>1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};