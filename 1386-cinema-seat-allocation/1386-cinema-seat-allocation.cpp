class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mask;
        for(auto &seat: reservedSeats){
            int row= seat[0];
            int s= seat[1];
            mask[row] |= (1<<s);
        }
        int ans= 2*n;
        int left=(1<<2)|(1<<3)|(1<<4) | (1<<5);
        int middle= (1<<4) | (1<<5) | (1<<6) | (1<<7);
        int right= (1<<6) | (1<<7) |(1<<8) |(1<<9);
        for(auto &[row, reserved] : mask){
            bool canLeft= (reserved & left)==0;
            bool canMiddle= (reserved & middle)==0;
            bool canRight= (reserved & right)==0;
            if(canLeft && canRight){
                continue;
            }
            else if(canLeft || canMiddle || canRight){
                ans-=1;
            }
            else{
                ans-=2;
            }
        }
        return ans;
    }
};