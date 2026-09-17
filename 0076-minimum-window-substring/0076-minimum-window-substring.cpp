class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128,0);
        vector<int> window(128,0);
        for(char c:t){
            need[c]++;
        }
        int required=0;
        for(int i=0;i<128;i++){
            if(need[i]>0){
                required++;
            }
        }
        int formed=0;
        int left=0;
        int bestStart=0;
        int bestLength=INT_MAX;
        for(int right=0;right<s.size();right++){
            char c=s[right];
            window[c]++;
            if(need[c]>0  && window[c]==need[c]){
                formed++;
            }
            while(formed==required){
                if(right-left+1<bestLength){
                    bestLength=right-left+1;
                    bestStart=left;
                }
                char remove=s[left];
                window[remove]--;
                if(need[remove]>0 && window[remove]<need[remove]){
                    formed--;
                }
                left++;
            }
        }
        if(bestLength==INT_MAX){
            return "";
        }
        return s.substr(bestStart,bestLength);
    }
};