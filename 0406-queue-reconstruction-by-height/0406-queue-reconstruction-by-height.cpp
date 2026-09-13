class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        //step 1.firstly we will sort the peoples array as required h descending and k ascending
        sort(people.begin(), people.end(),[](const vector<int>& a, vector<int>& b){
            if(a[0]==b[0])
                return a[1]<b[1]; //k ascending
            return a[0]>b[0]; //h desending
        });
        vector<vector<int>> ans;
        for(auto person: people){
            ans.insert(ans.begin()+person[1],person); //person[1] tells where to insert i.e. after how many places
        }
        return ans;
    }
};