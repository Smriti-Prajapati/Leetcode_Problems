class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0; //->open - no. of ')' , this to be added
        int ans=0;   //ans-> no. of '(' to be added
        for(char c:s){
            if(c=='('){
                open++;
            }
            else{
                if(open>0){
                    open--;
                }
                else{
                    ans++;
                }
            }
        }
        return open+ans; //these are the number of insertions we need to make string valid
    }
};