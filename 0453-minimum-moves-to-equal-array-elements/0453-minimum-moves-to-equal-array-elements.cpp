class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        //initilaize first element as smallest
        int smallest=nums[0];
        //find the smallest element
        for(int i=1;i<n;i++){
            if(nums[i]<smallest){
                smallest=nums[i];
            }
        }
        //create a variable for answer
        int moves=0;
        for(int i=0;i<n;i++){
            moves+=nums[i]-smallest;
        }
        return moves;
    }
};