class Solution {
public:
    int firstUniqChar(string s) {
        //step 1.create map for keeping count
        unordered_map<char,int> freq;
        //step 2.count the characters
        for(char c:s){
            freq[c]++;
        }
        //step 3.find the first character whose count is 1
        for(int i=0;i<s.length();i++){
            if(freq[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};