class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        //base case if only 1 house
        if(n==1){
            return nums[0];
        }
        //create a dp vector
        vector<int>dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int robCurrent=nums[i]+dp[i-2];
            int skipCurrent=dp[i-1];
            dp[i]=max(robCurrent,skipCurrent);
        }
        return dp[n-1];
    }
};