class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right= height.size()-1;
        int maxWater=0;
        while(left<right){
            int wt= right-left;
            int ht=min(height[left], height[right]);
            int area= wt*ht;
            maxWater= max(maxWater, area);
        
            if(height[left]< height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxWater;
    }
};