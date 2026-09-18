class Solution {
public:
    int hammingDistance(int x, int y) {
        int a=x^y;
        int count=0;
        while(a>0){
            count+=a&1;
            a=a>>1;
        }
        return count;
    }
};