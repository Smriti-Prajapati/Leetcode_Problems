class Solution {
public:
    int productDigit(int x){
        int prod=1;
        while(x>0){
            prod *= (x%10);
            x/=10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(productDigit(n) % t==0)
                return n;
            n++;
        }
    }
};