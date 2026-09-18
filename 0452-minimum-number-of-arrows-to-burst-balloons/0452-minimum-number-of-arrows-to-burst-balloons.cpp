class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        //step 1. is we will sort the array in descending order but by end points as we want the maximum balloons sto be burst at once;
        sort(points.begin(),points.end(),
        [](const vector<int>&a, const vector<int>& b){
            return a[1]< b[1];
        });
        //step 2.initialize arrrow as 1 and arrow position at first point end
        int arrows=1;
        int arrowPos= points[0][1];
        //step 3.iterate
        for(int i=1;i<points.size();i++){
            if(points[i][0]>arrowPos){
                arrows++;
                arrowPos= points[i][1];
            }
        }
        return arrows;
    }
};