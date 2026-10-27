class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m,string(n,'#'));
        int i=0,j=0;
        while(j<n){
            grid[i][j]='.';
            j++;
        }
        i=1;
        j=n-1;
        while(i<m){
            grid[i][j]='.';
            i++;
        }
        return grid;
    }
};