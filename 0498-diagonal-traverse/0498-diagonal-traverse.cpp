class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows=mat.size();
        int cols=mat[0].size();
        vector<int> ans;
        int r=0;
        int c=0;
        bool upward=true;
        while(ans.size()<rows*cols){
            ans.push_back(mat[r][c]);
            if(upward){   //upward->true, up -right 
                if(c==cols-1){  //upward->false, down-left
                    r++;
                    upward=false;
                }
                else if(r==0){
                    c++;
                    upward=false;
                }
                else{
                    r--;
                    c++;
                }            
            }
            else{
                if(r==rows-1){
                    c++;
                    upward=true;
                }
                else if(c==0){
                    r++;
                    upward=true;
                }
                else{
                    r++;
                    c--;
                }
            }
        }
        return ans;
    }
};