class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        //step 1 is sort the people is descending height and if they have same height sort by ascending k value
        sort(people.begin(), people.end(),
        [](const vector<int>& a, const vector<int>& b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            else{
                return a[0]>b[0];
            }
        });
        //step 2 is create a vector to store the answer
        vector<vector<int>> ans;
        for(auto& person:people){
            ans.insert(ans.begin()+person[1],person);
        }
        return ans;
    }
};