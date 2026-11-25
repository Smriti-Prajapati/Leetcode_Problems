class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        //number of rows
        int m=matrix.size();
        //number of columns
        int n=matrix[0].size();
        vector<int> ans; //to store the answer
        for(int i=0;i<m;i++){
            int mn=INT_MAX;
            int col=-1;
            //find minimum element in riow
            for(int j=0;j<n;j++){
                if(matrix[i][j]<mn){
                    mn=matrix[i][j];
                    col=j;
                }
            }
            //check whether that number is maximum in column
            bool isLucky=true;
            for(int k=0;k<m;k++){
                if(matrix[k][col]>mn){
                    isLucky=false;
                    break;
                }
            }
            if(isLucky){
                ans.push_back(mn);
            }
        }
        return ans;

    }
};