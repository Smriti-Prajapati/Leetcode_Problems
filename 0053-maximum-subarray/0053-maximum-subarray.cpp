class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //let's apply kadane's algorithm
        int currentSum=nums[0];
        int maxSum=nums[0];
        for(int i=1;i<nums.size();i++){
            currentSum=max(nums[i],currentSum+nums[i]);
            maxSum=max(maxSum,currentSum);
        }
        return maxSum;
    }
};