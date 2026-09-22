class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        //step 1.mark the numbers that exist as negative
        for(int i=0;i<n;i++){
            int x=abs(nums[i]);
            nums[x-1]=-abs(nums[x-1]);
        }
        //step 2.find the numbers that are not marked
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};