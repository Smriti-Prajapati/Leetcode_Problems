class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        //step 1. count number of rows and columns
        int rows=matrix.size();
        int cols=matrix[0].size();
        int answer=0;
        //fix top and bottom
        for(int top=0;top<rows;top++){
            vector<int> colSum(cols,0);
            for(int bottom=top;bottom<rows;bottom++){
                for(int col=0;col<cols;col++){
                    colSum[col]+=matrix[bottom][col];
                }
                //subarrays with target sum
                unordered_map<int,int> mpp;
                mpp[0]=1;
                int prefixSum=0;
                for(int col=0;col<cols;col++){
                    prefixSum+=colSum[col];
                    int required=prefixSum-target;
                    if(mpp.count(required)){
                        answer+=mpp[required];
                    }
                    mpp[prefixSum]++;
                }
            }
        }
        return answer;
    }
};