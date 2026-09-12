class Solution {
public:
    vector<int> partitionLabels(string s) {
        //step 1.store the last index value of each character
        vector<int> last(26,0);
        for(int i=0;i<s.size();i++){
            last[s[i]-'a']=i;
        }
        //step 2.create answer array
        vector<int> answer;
        int start=0;
        int end=0;
        //step 3.interate
        for(int i=0;i<s.size();i++){
            end=max(end,last[s[i]-'a']);
            //step 4 . if end==i then we can from there
            if(end==i){
                answer.push_back(end-start+1); //r-l+1
                start=i+1;
            }
        }
        return answer;
    }
};