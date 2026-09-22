class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        //step 1.count the number of characters
        for(char c:s){
            freq[c]++;
        }
        //put the values{character,count} in arr
        vector<pair<int,int>> arr;
        for(auto &p:freq){
            arr.push_back({p.first,p.second});
        }
        //step 3.sort the arr in descending order
        sort(arr.begin(),arr.end(),
        [](pair<int,int>& a, pair<int,int>& b){
            return a.second>b.second;
        });
        //put it in ans
        string ans;
        for(auto &p:arr){
            ans+= string(p.second,p.first);
        }
        return ans;
    }
};