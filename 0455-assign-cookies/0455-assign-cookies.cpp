class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //step 1.sort both greed and cookie array
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int happy=0;
        int child=0;
        int cookie=0;
        while(child<g.size() && cookie<s.size()){
            if(s[cookie]>=g[child]){
                happy++;
                child++;
                cookie++;
            }
            else{
                cookie++;
            }
        }
        return happy;
    }
};