class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1;
        for(int j=k; j<nums.size();j++){
            if(nums[j] != nums[j-1]){
                nums[k]= nums[j];
                k++;
            }

        }
        return k;
    }
};