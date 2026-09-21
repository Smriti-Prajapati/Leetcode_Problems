class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        //dp for answer
        vector<long long> ans(k,0);
        //dp for subarrays ending at previous positions
        vector<long long> dp(k,0);
        for(int num:nums){
            //dp forsubarrays ending at current position
            vector<long long> newDp(k,0);
            //case 1.new subarray
            int rem=num%k;
            newDp[rem]++;
            //case 2. add in old subarray
            for(int r=0;r<k;r++){
                int newRem=(r*rem)%k;
                newDp[newRem]+=dp[r];
            }
            //add current subarrays to final answer
            for(int r=0;r<k;r++){
                ans[r]+=newDp[r];
            }
            dp=newDp;
        }
        return ans;
    }
};