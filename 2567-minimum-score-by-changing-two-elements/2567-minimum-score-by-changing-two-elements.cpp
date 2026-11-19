class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<=3){
            return 0;
        }
        int ans=INT_MAX;
        sort(nums.begin(),nums.end());
        //case 1- remove two largest elements
        ans=min(ans,nums[n-3]-nums[0]);
        //case 2- remove two smallest elements
        ans=min(ans,nums[n-1]-nums[2]);
        //case 3- remove one smallest andone largest element
        ans=min(ans,nums[n-2]-nums[1]);
        return ans;
    }
};