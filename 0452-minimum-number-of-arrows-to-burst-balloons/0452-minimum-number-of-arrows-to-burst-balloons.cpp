class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        //step oneis sort the ballons on basis of last in ascending
        sort(points.begin(),points.end(),
        [](const vector<int>& a, const vector<int>& b){
            return a[1]<b[1];
        });
        int arrows=1; //minimum arrows needed
        long long lastArrow=points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]>lastArrow){
                arrows++;
                lastArrow=points[i][1];
            }
        }
        return arrows;
    }
};