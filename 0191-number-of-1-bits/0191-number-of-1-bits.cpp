class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n>0){
            count+=(n&1); //count last bit if 1 
            n=n>>1; //remove last bit
        }
        return count;
    }
};