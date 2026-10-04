class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k=0; //k->writes, i->reads
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[k]=nums[i];
                k++;
            }
        }
        //fill remaining position with 0's
        while(k<nums.size()){
            nums[k]=0;
            k++;
        }
    }
};