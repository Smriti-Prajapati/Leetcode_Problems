class Solution {
    public int minimizeSum(int[] nums) {
        int n=nums.length;
        if(n<=3){
            return 0;
        }
        int ans=Integer.MAX_VALUE;
        //sort the array by Arrays.sort in java
        Arrays.sort(nums);
        //case 1- remove two largest elements
        ans=Math.min(ans,nums[n-3]-nums[0]);
        //case 2 - remove two smallest elements
        ans=Math.min(ans,nums[n-1]-nums[2]);
        //case 3-remove one smallest and one largest element
        ans=Math.min(ans,nums[n-2]-nums[1]);
        return ans;
    }
}