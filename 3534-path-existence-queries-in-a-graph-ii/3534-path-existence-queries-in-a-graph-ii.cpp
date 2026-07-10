class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> ord;
        for(int i=0;i<n;i++) ord.push_back({nums[i],i});
        sort(ord.begin(),ord.end());

        vector<int> val(n),pos(n),comp(n);
        for(int i=0;i<n;i++){
            val[i]=ord[i].first;
            pos[ord[i].second]=i;
        }

        int cid=0;
        comp[0]=0;
        for(int i=1;i<n;i++){
            if(val[i]-val[i-1]>maxDiff) cid++;
            comp[i]=cid;
        }

        vector<int> nxt(n),prv(n);

        int r=0;
        for(int i=0;i<n;i++){
            while(r+1<n&&val[r+1]<=val[i]+maxDiff) r++;
            nxt[i]=r;
        }

        int l=0;
        for(int i=0;i<n;i++){
            while(val[i]-val[l]>maxDiff) l++;
            prv[i]=l;
        }

        int LOG=18;
        vector<vector<int>> upF(LOG,vector<int>(n)),upB(LOG,vector<int>(n));

        for(int i=0;i<n;i++){
            upF[0][i]=nxt[i];
            upB[0][i]=prv[i];
        }

        for(int k=1;k<LOG;k++){
            for(int i=0;i<n;i++){
                upF[k][i]=upF[k-1][upF[k-1][i]];
                upB[k][i]=upB[k-1][upB[k-1][i]];
            }
        }

        vector<int> ans;

        for(auto &q:queries){
            int a=pos[q[0]],b=pos[q[1]];

            if(a==b){
                ans.push_back(0);
                continue;
            }

            if(comp[a]!=comp[b]){
                ans.push_back(-1);
                continue;
            }

            if(a<b){
                int cur=a,steps=0;
                for(int k=LOG-1;k>=0;k--){
                    if(upF[k][cur]<b){
                        cur=upF[k][cur];
                        steps+=1<<k;
                    }
                }
                ans.push_back(steps+1);
            }else{
                int cur=a,steps=0;
                for(int k=LOG-1;k>=0;k--){
                    if(upB[k][cur]>b){
                        cur=upB[k][cur];
                        steps+=1<<k;
                    }
                }
                ans.push_back(steps+1);
            }
        }

        return ans;
    }
};