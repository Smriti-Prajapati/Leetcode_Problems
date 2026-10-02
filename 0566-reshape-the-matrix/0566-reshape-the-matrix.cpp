class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m= mat.size();
        int n=mat[0].size();
        if(m*n != r*c){
            return mat;
        }
        vector<vector<int>> ans(r,vector<int>(c));
        int index=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[index/c][index%c]=mat[i][j];
                index++;
            }
        }
        return ans;
    }
};