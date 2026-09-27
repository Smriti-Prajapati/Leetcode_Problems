class Solution {
public:
    string reverseParentheses(string s) {
        //step 1. we will create a stack
        stack<string> st;
        string curr="";
        for(char ch:s){
            if(ch=='('){
                st.push(curr);
                curr="";
            }
            else if(ch==')'){
                reverse(curr.begin(), curr.end());
                curr=st.top()+curr;
                st.pop();
            }
            else{
                curr+=ch;
            }
        }
        return curr;
    }
};