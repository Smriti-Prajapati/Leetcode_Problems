class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int num:nums){
            mpp[num]++;
        }
        for(auto &p:mpp){
            if(p.second==1){
                return p.first;
            }
        }
        return -1;
    }
};