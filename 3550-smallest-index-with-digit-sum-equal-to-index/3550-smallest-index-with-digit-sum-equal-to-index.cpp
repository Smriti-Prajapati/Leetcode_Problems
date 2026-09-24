class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            //take one element from arr
            int x=nums[i];
            int sum=0;
            while(x>0){
                sum+=x%10; //add last digit to sum
                x/=10; //remove last digit;
            }
            if(sum==i){
                return i;
            }
        }
        return -1;
    }
};