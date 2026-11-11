class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        //calculate common items from need 1 and need2 which will be there minimum
        int common=min(need1,need2);
        //finding remaining elements from need1 and need2
        int remaining1=need1-common;
        int remaining2=need2-common;
        //option 1 when individual cost is considered
        long long option1= 1LL*cost1*need1+ 1LL*cost2*need2;
        //option2 when costBoth is considered
        long long option2=1LL*max(need1,need2)*costBoth;
        //option 3 costBoth for similar items and individual cost for remanining
        long long option3=1LL*common*costBoth+ 1LL*remaining1*cost1+ 1LL*remaining2*cost2;
        return min({option1,option2,option3});
    }
};