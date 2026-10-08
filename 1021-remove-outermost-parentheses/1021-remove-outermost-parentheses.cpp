class Solution {
public:
    string removeOuterParentheses(string s) {
        //create a empty string
        string ans="";
        int depth=0;
        for(char c:s){
            if(c=='('){
                if(depth>0){
                    ans+=c;  //if depth greater than 0 , then add teh bracket to ans
                }
                depth++;
            }
            else{
                depth--;
                if(depth>0){
                    ans+=c;
                }
            }
        }
        return ans;
    }
};