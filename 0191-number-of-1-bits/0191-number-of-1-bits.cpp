class Solution {
public:
    int hammingWeight(int n) {
        int count;
        while(n>0){
            count+=(n&1);
            n=n>>1;
        }
        return count;
    }
};
