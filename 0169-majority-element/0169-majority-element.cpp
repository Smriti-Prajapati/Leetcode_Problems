class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //by boyer-moore voting algorithm
        int candidate=0;
        int count=0;
        for(int x:nums){
            if(count==0){
                candidate=x;
            }
            if(x==candidate){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
    }
};