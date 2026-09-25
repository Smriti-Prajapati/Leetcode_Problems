class Solution {
public:
    set<string> solve(string& s,int& i){
        set<string> result;
        set<string> current={""};
        while(i<s.size() && s[i]!='}'){
            if(s[i]=='{'){
                i++;  //skip }
                set<string> inside=solve(s,i);
                i++; //skip {
                set<string> temp;
                for(string a:current){
                    for(string b:inside){
                        temp.insert(a+b);
                    }
                }
                current=temp;
            }
            else if(s[i]==','){
                //comma means union 
                for(string x:current){
                    result.insert(x);
                }
                current={""};
                i++;
            }
            else{
                set<string> temp;
                for(string x:current){
                    temp.insert(x+s[i]);
                }
                current=temp;
                i++;
            }
        }
        for(string x:current){
            result.insert(x);
        }
        return result;
    }
    vector<string> braceExpansionII(string expression) {
        int i=0;
        set<string> ans=solve(expression,i);
        return vector<string>(ans.begin(), ans.end());
    }
};