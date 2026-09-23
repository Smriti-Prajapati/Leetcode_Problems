class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> dp(n,vector<double>(n,0));
        dp[row][column]=1.0; //placing the knight at start
        int dr[]= {2,2,-2,-2,1,1,-1,-1};
        int dc[]={1,-1,1,-1,2,-2,2,-2};
        for(int move=0;move<k;move++){
            //create next dp
            vector<vector<double>> next(n,vector<double>(n,0));
            for(int r=0;r<n;r++){
                for(int c=0;c<n;c++){
                    if(dp[r][c]==0)
                        continue;
                    for(int i=0;i<8;i++){
                        int nr=r+dr[i];
                        int nc=c+dc[i];
                        //check if the knight is inside the chessboard
                        if(nr>=0 && nr<n && nc>=0 && nc<n){
                            next[nr][nc]+=dp[r][c]/8.0; //because each move has probability 1/8
                        }
                    }
                }
            }
            dp=next;
        }
        double ans=0;
        //adding all probabilities
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                ans+=dp[r][c];
            }
        }
        return ans;
    }
};