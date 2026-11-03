class Solution {
public:
    int minMoves(vector<int>& nums) {
        //step 1 is find the maximum element
        int maxi=*max_element(nums.begin(), nums.end());
        //step 2 initialize moves as 0
        int moves=0;
        //step 3 iterate in array
        for(int i=0;i<nums.size();i++){
            moves+=maxi-nums[i];
        }
        return moves;
    }
};