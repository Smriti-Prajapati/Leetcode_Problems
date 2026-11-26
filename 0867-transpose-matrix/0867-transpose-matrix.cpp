class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        //in transpose rows become cols and cols become rows
        //finding number of rows and cols
        int m=matrix.size();
        int n=matrix[0].size();
        //create a vector ans for transposed matrix
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //change rows to cols in ans of matrix
                ans[j][i]=matrix[i][j];
            }
        }
        return ans;
    }
};