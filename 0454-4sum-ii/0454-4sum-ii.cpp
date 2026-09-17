class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> mpp;
        for(int a:nums1){
            for(int b:nums2){
                mpp[a+b]++;
            }
        }
        int ans=0;
        for(int c:nums3){
            for(int d:nums4){
                int sum=c+d;
                //firstsum+sum=0, firstsum=required
                int required=-sum;
                if(mpp.find(required)!= mpp.end()){
                    ans+=mpp[required];
                }
            }
        }
        return ans;
    }
};