class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        //initialize first element as smallest
        int smallest=nums[0];
        //find the smallest element from the array
        //traverse in the array
        for(int i=1;i<n;i++){
            if(nums[i]<smallest){
                smallest=nums[i];
            }
        }
        //create a variable to store answer
        int ans=0;
        //traverse again in array
        for(int i=0;i<n;i++){
            ans+=nums[i]-smallest;
        }
        return ans;
    }
};