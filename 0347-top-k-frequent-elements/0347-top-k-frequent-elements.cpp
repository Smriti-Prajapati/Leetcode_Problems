class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //step 1.count the frequency of characters
        unordered_map<int,int> freq;
        for(int x:nums){
            freq[x]++;
        }
        //step 2.put the pair in another arr
        vector<pair<int,int>> arr;
        for(auto it:freq){
            arr.push_back({it.first,it.second});
        }
        //step 3.sort the array in descending order
        sort(arr.begin(),arr.end(),
        [](pair<int,int>&a, pair<int,int>& b){
            return a.second> b.second;
        });
        //put top k elements in ans
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(arr[i].first);
        }
        return ans;
    }
};