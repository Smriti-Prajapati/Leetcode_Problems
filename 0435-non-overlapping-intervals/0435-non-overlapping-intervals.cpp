class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //step 1.sort the array intervals by ending point
        sort(intervals.begin(), intervals.end(),
        [](vector<int>& a, vector<int>& b){
            return a[1]<b[1];
        });
        //step 2.create removed and prevEnd
        int removed=0;
        int prevEnd= intervals[0][1]; //end of 1st interval
        //step 3.start iterating
        for(int i=1;i<intervals.size();i++){
            int start= intervals[i][0];
            int end=intervals[i][1];
            if(start<prevEnd){
                removed++;
            }
            else{
                prevEnd=end;
            }
        }
        return removed;
    }
};