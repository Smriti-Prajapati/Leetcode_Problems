class Solution {
public:
    bool checkString(string s) {
        //we just need to check that there should not be any a after b
        //we will traverse in the string
        for(int i=0;i<s.length();i++){
            if(s[i]=='b' && s[i+1]=='a'){
                return false;
            }
        }
        return true;
    }
};