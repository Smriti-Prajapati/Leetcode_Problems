class Solution {
public:
    int climbStairs(int n) {
        /**vector<int> dp(n+1,0);
        dp[1]=1;
        if(n>=2){
            dp[2]=2;
        }
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-2]+dp[i-1];
        }
        return dp[n];
    }**/
    //tabulation method we do not require extra dp
    //edge case
        if(n<=2)
            return n;
        int prev2=1;
        int prev1=2;
        for(int i=3;i<=n;i++){
            int curr=prev2+prev1;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};