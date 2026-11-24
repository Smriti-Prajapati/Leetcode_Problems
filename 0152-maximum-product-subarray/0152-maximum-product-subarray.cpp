class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        //assign first element in the array as maxProduct, minProduct and answer
        int maxProduct=nums[0];
        int minProduct=nums[0];
        int answer=nums[0];
        //iterate in array after first element till last element
        for(int i=1;i<n;i++){
            int curr=nums[i];
            //storing maxProduct in temp variable
            int temp=maxProduct;
            maxProduct=max({curr,curr*maxProduct, curr*minProduct});
            minProduct=min({curr, curr*temp,curr*minProduct});
            answer=max(answer,maxProduct);
        }
        return answer;
    }
};