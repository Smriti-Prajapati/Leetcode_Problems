class Solution {
public:
    bool canSplit(vector<int>& nums, int k,int maxSum){
        long long currentSum=0;
        int subarray=1;
        for(int num: nums){
            if(currentSum+num> maxSum){
                subarray++;
                currentSum=num;
            }
            else{
                currentSum+=num;
            }
        }
        return subarray<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        long long low=0;
        long long high=0;
        for(int num: nums){
            low= max(low,(long long)num);
            high+=num;
            while(low<=high){
                long long mid=low+(high-low)/2;
                if(canSplit(nums,k,mid)){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        }
        return low;
    }
};