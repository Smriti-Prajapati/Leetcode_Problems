class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        //dp[0]={difference:length}
        vector<unordered_map<int,int>> dp(n);
        int ans=2; //2->because at atleast 2 elements are there
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff= nums[i]-nums[j];
                int previousLength=1;
                if(dp[j].count(diff)){
                    previousLength= dp[j][diff];
                }
                dp[i][diff]= previousLength+1;
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};