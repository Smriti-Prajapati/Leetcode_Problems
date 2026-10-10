class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> freq(100001,0);
        int maxDiff=0;
        long long totalDiff=0;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            int diff=abs(nums1[i]-nums2[i]);
            freq[diff]++;
            totalDiff+=diff;
            maxDiff=max(maxDiff,diff);
        }
        long long k=(long long)k1+k2;
        if(totalDiff<=k){
            return 0;
        }
        for(int d=maxDiff;d >=1;d--){
            if(k==0){
                break;
            }
            int reduce=min((long long)freq[d],k);
            freq[d]-=reduce;
            freq[d-1]+=reduce;
            k-=reduce;
        }
        long long ans=0;
        for(int d=1;d<=maxDiff;d++){
            ans+=1LL*d*d*freq[d];
        }
        return ans;
    }
};