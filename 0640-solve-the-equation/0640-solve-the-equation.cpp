class Solution {
public:
    pair<int,int> parse(string s){
        int coeff=0;
        int constant=0;
        int i=0;
        int sign=1;
        while(i<s.length()){
            if(s[i]=='+'){
                sign=1;
                i++;
            }
            else if(s[i]=='-'){
                sign=-1;
                i++;
            }
            int num=0;
            bool hasNumber=false;
            while(i<s.length() && isdigit(s[i])){
                num=num*10+(s[i]-'0');
                i++;
                hasNumber=true;
            }
            if(i<s.length() && s[i]=='x'){
                if(!hasNumber){
                    num=1;
                }
                coeff+=sign*num;
                i++;
            }
            else{
                constant+=sign*num;
            }
        }
        return {coeff, constant};
    }
    string solveEquation(string equation) {
        int equalPos=equation.find('=');
        string left= equation.substr(0,equalPos);
        string right= equation.substr(equalPos+1);
        auto L=parse(left);
        auto R=parse(right);
        int leftCoeff=L.first;
        int leftConstant=L.second;
        int rightCoeff=R.first;
        int rightConstant=R.second;
        int coeff=leftCoeff- rightCoeff;
        int constant=rightConstant- leftConstant;
        if(coeff==0 && constant==0){
            return "Infinite solutions";
        }
        if(coeff==0){
            return "No solution";
        }
        int x=constant/coeff;
        return "x="+ to_string(x);
    }
};