class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //firstly calculate the total sum
        int totalSum=0;
        for(int x:nums){
            totalSum+=x;
        }
        int leftSum=0;
        for(int i=0;i<nums.size();i++){
            int rightSum=totalSum-leftSum-nums[i];
            if(leftSum==rightSum){
                return i;
            }
            else{
                leftSum+=nums[i];
            }
        }
        return -1; //if pivot doesn't exist
    }
};