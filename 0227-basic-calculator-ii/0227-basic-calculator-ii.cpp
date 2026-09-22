class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num=0;
        char sign='+';
        for(int i=0;i<s.length();i++){
            //build the number
            if (isdigit(s[i])){
                num=num*10+(s[i]-'0');
            }
            //if we find an operator or if we are at the last character
            if((!isdigit(s[i])&& s[i] !=' ') || i==s.length()-1){
                if(sign=='+'){
                    st.push(num);
                }
                else if(sign=='-'){
                    st.push(-num);
                }
                else if(sign=='*'){
                    int top=st.top();
                    st.pop();
                    st.push(top*num);
                }
                else if(sign=='/'){
                    int top=st.top();
                    st.pop();
                    st.push(top/num);
                }
                //reset num
                num=0;
                //current operator becomes the sign
                sign=s[i];
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};