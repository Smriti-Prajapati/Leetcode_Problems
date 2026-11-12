class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1;
        int dec=1;
        int ans=1;
        //traverse in the array 
        for(int i=1;i<nums.size();i++){
            //for strictly increasing, increment inc and reset dec to 1
            if(nums[i]>nums[i-1]){
                inc++;
                dec=1;
            }
            //for strictly decreasing, increment dec and reset inc to 1
            else if(nums[i]<nums[i-1]){
                dec++;
                inc=1;
            }
            //if equal element then reset both inc and dec to 1
            else{
                inc=1;
                dec=1;
            }
            //ans
            ans=max(ans,max(inc,dec));
        }
        return ans;
    }
};