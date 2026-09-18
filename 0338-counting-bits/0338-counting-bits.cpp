class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=1;i<=n;i++){ //we are starting from 1 because i=0 has no bits as 1
            ans[i]=ans[i/2]+(i&1);      //i&1=0->even number
                                        //i&1=1->odd number
        }
        return ans;
    }
};