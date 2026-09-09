class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
        vector<int> left(n,1); //beacuse atleast 1 candy should be there
        vector<int> right(n,1);
        left[0]=1;
        right[n-1]=1;
        //when moving from left to right
        for(int i=1;i<n;i++){
            if(ratings[i]> ratings[i-1]){
                left[i]= left[i-1]+1;
            }
        }
        //moving from right to left
        for(int i=n-2;i>=0;i--){
            if(ratings[i]> ratings[i+1]){
                right[i]= right[i+1]+1;
            }
        }
        int total=0;
        for(int i=0;i<n;i++){
            total+=max(left[i], right[i]);
        }
        return total;
    }
};