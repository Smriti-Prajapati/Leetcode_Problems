class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int freq[26]={0};
        for(char c:s){
            freq[c-'a']++;
        }
        int common=0;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                common= freq[i];
                break;
            }
        }
        for(int i=0;i<26;i++){
            if(freq[i]>0 && freq[i]!= common){
                return false;
            }
        }
        return true;
    }
};