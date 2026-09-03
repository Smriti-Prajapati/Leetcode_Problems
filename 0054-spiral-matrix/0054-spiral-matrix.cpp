class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int top=0;
        int bottom=matrix.size()-1;//mXn
        int left=0;
        int right=matrix[0].size()-1;
        while(left<=right && top<=bottom){
            //left->right
            for(int j=left;j<=right;j++){
                ans.push_back(matrix[top][j]);
            }
            top++;
            //top->bottom
            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            //right->left
            if(top<=bottom){
                for(int j=right;j>=left;j--){
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
            if(left<=right){
                //bottom->top
                for(int i=bottom;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};