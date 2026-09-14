class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        //rec1[0]=x1, rec1[1]=y1, rec1[2]=x2, rec1[3]= y2
        //rec2[0]=x1, rec2[1]=y1, rec2[2]=x2, rec2[3]=y2
        //x2>x1
        bool xOverlap= min(rec1[2],rec2[2])> max(rec1[0], rec2[0]);
        //y2>y1
        bool yOverlap= min(rec1[3],rec2[3])> max(rec1[1],rec2[1]);
        return xOverlap && yOverlap;
    }
};