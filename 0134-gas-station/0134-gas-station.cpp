class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0;
        int curGas=0;
        int totalGas=0;
        int totalCost=0;
        for(int i=0; i< gas.size(); i++){
            totalGas+= gas[i];
            totalCost+= cost[i];
            curGas += (gas[i]- cost[i]);
            if(curGas< 0){
                start=i+1;
                curGas=0;
            }
        }
        if(totalGas< totalCost){
            return -1;
        }
        return start;
    }
};