class Solution {
public:
    bool canAliceWin(int n) {
        //initialize number of stones as 10 
        int stones=10;
        bool aliceTurn=true;
        while(n>=stones){
            n=n-stones;
            stones--;
            aliceTurn=!aliceTurn;
        }
        return !aliceTurn;
    }
};