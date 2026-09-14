class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int x:nums){
            freq[x]++;
        }
        vector<pair<int,int>> arr;
        for(auto it:freq){
            arr.push_back({it.first,it.second});
        }
        sort(arr.begin(), arr.end(),
        [](pair<int,int>& a, pair<int,int>& b){
            return a.second> b.second;
        });
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back({arr[i].first});
        }
        return ans;
    }
};