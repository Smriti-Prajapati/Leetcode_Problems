class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x=start^goal;
        int count=0;
        while(x>0){ //till when x is greater than 0 do this
            //check whether x&1 gives 1 if yes increase the count
            count+=x&1;
            x=x>>1; //right shift x by 1 position
        }
        return count;
    }
};