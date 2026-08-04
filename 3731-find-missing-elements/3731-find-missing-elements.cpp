class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int min= nums[0];
        int max= nums[0];
        for(int x: nums){
            if(x<min)
                min=x;
            if(x>max)
                max=x;
        }
        unordered_set<int> st;
        for(int x: nums){
            st.insert(x);
        }
        vector<int> ans;
        for(int i=min; i<= max;i++){
            if(st.count(i)==0)
                ans.push_back(i);
        }
        return ans;
    }
};