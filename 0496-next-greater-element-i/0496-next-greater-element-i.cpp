class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //crate a stack
        stack<int> st;
        unordered_map<int,int> mpp;
        for(int num:nums2){
            while(!st.empty() && num>st.top()){
                mpp[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }
        //to store the naswer
        vector<int> ans;
        for(int num:nums1){
            if(mpp.find(num)!=mpp.end()){
                ans.push_back(mpp[num]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};