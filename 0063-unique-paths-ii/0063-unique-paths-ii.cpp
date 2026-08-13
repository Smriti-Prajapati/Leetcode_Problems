class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        dp[0][0]=1;
        for(int i=1;i<m;i++){
            if(obstacleGrid[0][i]==1){
                dp[0][i]=0;
            }
            else{
                dp[0][i]= dp[0][i-1];
            }
        }
        for(int j=1;j<n;j++){
            if(obstacleGrid[j][0]==1){
                dp[j][0]=0;
            }
            else{
                dp[j][0]= dp[j-1][0];
            }
        }
        for(int j=1;j<n;j++){
            for(int i=1;i<m;i++){
                if(obstacleGrid[j][i]==1){
                    dp[j][i]= 0;
                }
                else{
                    dp[j][i]= dp[j-1][i]+dp[j][i-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};