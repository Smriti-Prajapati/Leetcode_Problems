class Solution {
public:
    int countCommas(int n) {
        return max(0,n-999);//as 998- 999 = -1 so max from (0, n)
    }
};