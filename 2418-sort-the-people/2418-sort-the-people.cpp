class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        //create a pair to store the heigth and names
        vector<pair<string,int>> people;
        for(int i=0;i<names.size();i++){
            people.push_back({names[i],heights[i]}); 
        }
        //sort in descending order of height
        sort(people.begin(),people.end(),
        [](pair<string,int> a,pair<string,int> b){
            if(a.second != b.second){
                return a.second>b.second;
            }
            else{
                return a.first<b.first;
            }
        });
        vector<string> ans;
        for(int i=0;i<names.size();i++){
            ans.push_back(people[i].first);
        }
        return ans;
    }
};