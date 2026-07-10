class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int l=0;
        int r= n-1;
        int maxWater=0;
        while(l<r){
            int w= r-l;
            int ht= min(height[l], height[r]);
            int area= w*ht;
            maxWater= max(maxWater, area);
            height[l]<height[r] ? l++ : r--;
        }
        return maxWater;
    }
};