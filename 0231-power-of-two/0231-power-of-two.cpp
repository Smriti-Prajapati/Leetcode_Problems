class Solution {
public:
    bool isPowerOfTwo(int n) {
        //bit manipulation method
        return n>0 && (n&(n-1))==0;
    }
};

/*or using loop
class Solution{
public:
    bool isPowerOfTwo(int n){
        if(n<=0){
            return false;
        }
        while(n%2==0){
            n=n/2;
        }
        return n==1;
    }
}*/