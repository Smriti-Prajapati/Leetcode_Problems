class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //we will use here monotonic stack
        int n=temperatures.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                int previousDay=st.top();
                st.pop();
                ans[previousDay]=i-previousDay;
            }
            st.push(i);
        }   
        return ans;
    }
};