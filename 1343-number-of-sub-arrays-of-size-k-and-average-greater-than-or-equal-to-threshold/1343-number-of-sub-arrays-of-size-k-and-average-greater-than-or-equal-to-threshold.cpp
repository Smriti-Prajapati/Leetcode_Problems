class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        int sum=0;
        int count=0;
        //calculate sum of first k terms
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        int target=k*threshold;
        if(sum>=target){
            count++;
        }
        //slide the window
        for(int i=k;i<n;i++){
            sum=sum+arr[i]-arr[i-k];
            if(sum>=target){
                count++;
            }
        }
        return count;
    }
};