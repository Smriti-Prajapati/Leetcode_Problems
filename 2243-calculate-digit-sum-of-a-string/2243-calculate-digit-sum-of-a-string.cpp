class Solution {
public:
    string digitSum(string s, int k) {
        //do it until length of s is greater than k
        while(s.length()>k){
            //creating a empty string temp
            string temp="";
            //iterate in the string
            for(int i=0;i<s.length();i+=k){
                int sum=0;
                for(int j=i;j<i+k && j<s.length();j++){
                    //add current element to sum and -0 because its string -0 converts it to num
                    sum+=s[j]-'0';
                }
                //add sum to temp by converting to string by to_string
                temp+=to_string(sum);
            }
            //keep temp in s
            s=temp;
        }
        //return s
        return s;
    }
};