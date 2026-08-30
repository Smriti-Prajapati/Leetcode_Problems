class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n= nums.size();
        int minInd=0;
        int maxInd=0;
        //finding the index of minimum and maximum number in the array
        for(int i=1;i<n;i++){
            if(nums[i]<nums[minInd]){
                minInd=i;
            }
            if(nums[i]> nums[maxInd]){
                maxInd=i;
            }
        }
        //putting smaller index in a and larget index in b
        int a= min(minInd, maxInd);
        int b= max(minInd, maxInd);
        int frontonly=b+1;
        int backonly=n-a;
        int bothends= (a+1)+(n-b);
        return min({frontonly, backonly, bothends});
    }
};