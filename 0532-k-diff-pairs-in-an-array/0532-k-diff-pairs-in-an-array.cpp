class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        int i=0, j=1;
        int count=0;
        while(j<n){
            if(i==j){
                j++;
                continue;
            }
            int diff= nums[j]-nums[i];
            if(diff== k){
                count++;
                int x= nums[i];
                int y= nums[j];
                while(i<n && nums[i]==x) i++;
                while(j<n && nums[j]==x) j++;
            }
            else if(diff<k){
                j++;
            }
            else{
                i++;
            }
        }
        return count;
    }
};