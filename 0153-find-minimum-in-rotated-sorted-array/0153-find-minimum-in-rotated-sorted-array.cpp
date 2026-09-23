class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]>nums[right]){
                //min is on right side
                left=mid+1;
            }
            else{
                //mid is minimum or is on left side
                right=mid;
            }
        }
        return nums[left];
    }
};