class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        //create a answer vector
        vector<int> ans;
        int depth=0;
        for(char ch:seq){
            if(ch=='('){
                depth++;
                ans.push_back(depth%2); //separating in two groups by odd and even
            }
            else{
                ans.push_back(depth%2);
                depth--;
            }
        }
        return ans;
    }
};