class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0); //26->because only capital letters are there
        int left=0;
        int maxFreq=0;
        int longest=0;
        for(int right=0;right<s.size();right++){
            freq[s[right]-'A']++;
            maxFreq=max(maxFreq,freq[s[right]-'A']);
            while((right-left+1)-maxFreq>k){
                freq[s[left]-'A']--;
                left++;
            }
            longest=max(longest,right-left+1);
        }
        return longest;
    }
};