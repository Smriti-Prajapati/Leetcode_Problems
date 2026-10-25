class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0;
        long long maxSum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        maxSum=sum;
        for(int i=k;i<n;i++){
            sum=sum+nums[i]-nums[i-k];
            maxSum=max(maxSum,sum);
        }
        return (double)maxSum/k;
    }
};