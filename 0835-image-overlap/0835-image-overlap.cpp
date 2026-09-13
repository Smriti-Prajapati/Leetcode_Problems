class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int ans=0;
        //try all possible rows
        for(int dr=-(n-1);dr<=n-1;dr++){
            //try all possible columns
            for(int dc=-(n-1);dc<=n-1;dc++){
                //initialize overlap
                int overlap=0;
                //checking every cell of img1
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        //new row and column
                        int nr=i+dr;
                        int nc=j+dc;
                        //checking if new row and column lies within matrix
                        if(nr>=0 && nr<n && nc>=0 && nc<n){
                            if(img1[i][j]==1 && img2[nr][nc]==1){
                                overlap++;
                            }
                        }
                    }
                }
                ans=max(ans,overlap);
            }
        }
        return ans;
    }
};