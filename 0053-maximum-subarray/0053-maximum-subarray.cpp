class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum=0;
        int maxSum= INT_MIN;
        for(int x: nums){
            curSum += x;
            maxSum= max(maxSum, curSum);
            if(curSum<0){
                curSum=0;
            }
        }
        return maxSum;
    }
};