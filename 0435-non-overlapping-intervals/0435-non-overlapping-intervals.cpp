class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //step 1 is sort the array 
        sort(intervals.begin(), intervals.end(),
        [](const vector<int>& a,const vector<int>& b){
            return a[1]<b[1];
        });
        int removals=0;
        int lastNode=intervals[0][1];
        //now start iterating
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=lastNode){
                lastNode=intervals[i][1];
            }
            else{
                removals++;
            }
        }
        return removals;
    }
};