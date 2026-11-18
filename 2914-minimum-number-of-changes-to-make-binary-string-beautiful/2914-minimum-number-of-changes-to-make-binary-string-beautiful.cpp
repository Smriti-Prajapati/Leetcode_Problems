class Solution {
public:
    int minChanges(string s) {
        //initialize a changes variable
        int changes=0;
        //traverse by a gap of 2(because every substring must be even)
        for(int i=0;i<s.length();i+=2){
            if(s[i]!=s[i+1]){
                changes++;
            }
        }
        return changes;
    }
};