class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted= arr;
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> mpp;
        int r=1;
        for(int x : sorted){
            if(mpp.find(x) == mpp.end()){
                mpp[x]= r++;
            }
        }
        for(int i=0; i<arr.size(); i++){
            arr[i]= mpp[arr[i]];
        }
        return arr;
    }
};