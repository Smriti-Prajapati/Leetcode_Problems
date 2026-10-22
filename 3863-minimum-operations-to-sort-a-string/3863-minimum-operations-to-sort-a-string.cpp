class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        //edge case 1 when already sorted
        if(is_sorted(s.begin(),s.end())){
            return 0;
        }
        //edge case 2 when length of string is 2
        if(n==2){
            return -1;
        }
        //min and max element
        char mn=*min_element(s.begin(),s.end());
        char mx=*max_element(s.begin(),s.end());
        //case when one swap is needed
        if(s[0]==mn || s[n-1]==mx){
            return 1;
        }
        //case when min and max is in middle
        for(int i=1;i<n-1;i++){
            if(s[i]==mn || s[i]==mx){
                return 2;
            }
        }
        //case when s[0]=mx and s[n-1]=mn
        return 3;
    }
};