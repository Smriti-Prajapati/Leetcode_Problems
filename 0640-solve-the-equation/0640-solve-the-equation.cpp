class Solution {
public:
    pair<int,int> parse(string s) {
        //step 1.initialize
        int coeff=0;
        int constant=0;
        int i=0;
        int sign=1;
        //step 2.see the sign
        while(i<s.length()){
            if(s[i]=='+'){
                sign=1;
                i++;
            }
            else if(s[i]=='-'){
                sign=-1;
                i++;
            }
            //step 3.read the number
            int num=0;
            bool hasNumber=false;
            while(i<s.length() && isdigit(s[i])){
                num=num*10+(s[i]-'0');
                hasNumber= true;
                i++;
            }
            //step 4.if next is x
            if(i<s.length() && s[i]=='x'){
                if(!hasNumber){
                    num=1;
                }
                coeff+=num*sign;
                i++;
            }
            else{
                //its a constant number
                constant+=num*sign;
            }
        }
        return {coeff, constant};
    }
    string solveEquation(string equation){
        //split at = position
        int equalPos= equation.find('=');
        string left=equation.substr(0,equalPos);
        string right=equation.substr(equalPos+1);
        auto L=parse(left);
        auto R=parse(right);
        int leftCoeff=L.first;
        int leftConst=L.second;
        int rightCoeff=R.first;
        int rightConst=R.second;
        //move x to left and constants to right
        int coeff=leftCoeff - rightCoeff;
        int constant= rightConst- leftConst;
        if(coeff==0 && constant==0)
            return "Infinite solutions";
        if(coeff==0)
            return "No solution";
        int x=constant/coeff;
        return "x=" + to_string(x);
    }
};