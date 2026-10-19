class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //by xor method
        int n=nums.size();
        int ans=n;
        for(int i=0;i<n;i++){
            ans=ans^i^nums[i];
        }
        return ans;
    }
};