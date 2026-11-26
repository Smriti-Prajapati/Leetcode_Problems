class Solution {
public:
    int findLucky(vector<int>& arr) {
        //create a unordered_map and count the frequency of each element
        unordered_map<int,int> mpp;
        for(int x:arr){
            mpp[x]++;
        }
        int ans=-1;
        //check whether frequency of x is equal to its value
        for(auto it:mpp){
            if(it.first==it.second){
                ans=max(ans,it.first);
            }
        }
        return ans;
    }
};