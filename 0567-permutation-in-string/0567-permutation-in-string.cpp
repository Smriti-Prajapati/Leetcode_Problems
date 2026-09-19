class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){//if s1 is greater then it can never exist in s2
            return false;
        }
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(char c:s1){
            freq1[c-'a']++;
        }
        int windowSize=s1.size();
        for(int i=0;i<windowSize;i++){
            freq2[s2[i]-'a']++;
        }
        if(freq1==freq2){
            return true;
        }
        //expand the window
        for(int right=windowSize;right<s2.size();right++){
            freq2[s2[right]-'a']++;
            int left=right-windowSize;
            freq2[s2[left]-'a']--;
            if(freq1== freq2){
                return true;
            }
        }
        return false;
    }
};