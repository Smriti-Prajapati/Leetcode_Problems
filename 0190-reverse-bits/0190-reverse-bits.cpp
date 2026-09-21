class Solution {
public:
    int reverseBits(int n) {
        int result=0;
        for(int i=0;i<32;i++){
            //take the last bit
            int bit=n&1;
            //in result shift 1 position to left and add bit in it
            result=result<<1|bit;
            //remove the bit from n
            n=n>>1;
        }
        return result;
    }
};