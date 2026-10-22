class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //step 1 is sort the array
        sort(intervals.begin(),intervals.end());
        //create the result array
        vector<vector<int>> result;
        for(auto &interval :intervals){
            if(result.empty() || result.back()[1]<interval[0]){
                result.push_back(interval);
            }
            //merge the interval
            result.back()[1]=max(result.back()[1],interval[1]);
        }
        return result;
    }
};