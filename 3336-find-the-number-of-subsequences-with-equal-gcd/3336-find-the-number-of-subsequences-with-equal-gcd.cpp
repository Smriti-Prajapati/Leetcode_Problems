class Solution {
public:
    static const int MOD=1000000007;
    int subsequencePairCount(vector<int>& nums) {
        const int M=200;
        int g[M+1][M+1];
        for(int i=0;i<=M;i++){
            for(int j=0;j<=M;j++){
                if(i==0)g[i][j]=j;
                else if(j==0)g[i][j]=i;
                else g[i][j]=std::gcd(i,j);
            }
        }
        vector<vector<int>> dp(M+1,vector<int>(M+1)),ndp(M+1,vector<int>(M+1));
        dp[0][0]=1;
        for(int x:nums){
            for(int i=0;i<=M;i++)fill(ndp[i].begin(),ndp[i].end(),0);
            for(int a=0;a<=M;a++){
                for(int b=0;b<=M;b++){
                    int cur=dp[a][b];
                    if(!cur)continue;
                    ndp[a][b]=(ndp[a][b]+cur)%MOD;
                    int na=g[a][x];
                    ndp[na][b]=(ndp[na][b]+cur)%MOD;
                    int nb=g[b][x];
                    ndp[a][nb]=(ndp[a][nb]+cur)%MOD;
                }
            }
            dp.swap(ndp);
        }
        long long ans=0;
        for(int i=1;i<=M;i++)ans=(ans+dp[i][i])%MOD;
        return ans;
    }
};