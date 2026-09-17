class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        const int INF=1e9;
        vector<int> best(n,INF);
        int left=0;
        long long sum=0;
        int answer=INF;
        for(int right=0;right<n;right++){
            sum+=arr[right];
            while(sum>target && left<=right){
                sum-=arr[left];
                left++;
            }
            if(right>0){
                best[right]=best[right-1];
            }
            if(sum==target){
                int len= right-left+1;
                if(left>0 && best[left-1] != INF){
                    answer= min(answer,len+best[left-1]);
                }
                best[right]=min(best[right],len);
            }
        }
        if(answer==INF){
            return -1;
        }
        else{
            return answer;
        }
    }
};