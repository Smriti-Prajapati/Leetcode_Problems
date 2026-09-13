class Solution {
public:
    string removeKdigits(string num, int k) {
        //step 1.create a stack
        stack<char> st;
        for(char c:num){
            while(!st.empty() && k>0 && st.top()>c){
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int i=0;
        while(i<ans.size() && ans[i]=='0'){
            i++;
        }
        if(i==ans.size()){
            return "0";
        }
        return ans.substr(i);
    }
};