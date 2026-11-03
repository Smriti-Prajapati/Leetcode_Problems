class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        //step 1 we will sort the array
        sort(nums.begin(),nums.end());
        //step 2 find the median element
        int median=nums[n/2];
        int moves=0;
        //step 3 iterate 
        for(int i=0;i<n;i++){
            moves+=abs(nums[i]-median);
        }
        return moves;
    }
};