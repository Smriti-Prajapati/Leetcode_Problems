class Solution {
public:
    int robRange(vector<int>& nums, int start, int end){
        //basically this much part is house robber |
        int prev2=0;
        int prev1=0;
        for(int i=start;i<=end;i++){
            int robCurrent=nums[i]+prev2;
            int skip=prev1;
            int current=max(robCurrent,skip);
            prev2=prev1;
            prev1=current;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        //base case
        if(n==1){
            return nums[0];
        }
        int case1=robRange(nums,0,n-2); //exclude the last house
        int case2=robRange(nums,1,n-1); //exclude the first house
        return max(case1,case2);
    }
};