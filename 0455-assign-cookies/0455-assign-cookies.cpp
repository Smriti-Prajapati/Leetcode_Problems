class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //sort both the greed and cookie array
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0; //iterator for greed
        int j=0; //iterator for size of cookie
        int count=0;
        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i]){
                count++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return count;
    }
};