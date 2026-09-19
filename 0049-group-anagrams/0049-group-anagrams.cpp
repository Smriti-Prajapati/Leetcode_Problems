class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp; //key->value pair will be stored 
        for(string s: strs){
            string key=s; //create a copy
            sort(key.begin(),key.end()); //sort the keys
            mpp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};