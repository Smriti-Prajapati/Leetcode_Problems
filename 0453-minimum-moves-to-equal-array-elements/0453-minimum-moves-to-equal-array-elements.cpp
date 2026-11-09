class Solution {
public:
    int minMoves(vector<int>& nums) {
        //assign first element as smallest
        int smallest=nums[0];
        //find the smallest numbers
        for(int i=1;i<nums.size();i++){
            if(nums[i]<smallest){
                smallest=nums[i];
            }
        }
        //creating a separete variable for answer
        int moves=0;
        for(int i=0;i<nums.size();i++){
            moves+=nums[i]-smallest;
        }
        return moves;
    }
};