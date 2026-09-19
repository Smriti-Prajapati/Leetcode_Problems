class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        //step 1.first step is sort the array
        sort(people.begin(),people.end());
        int left=0;
        int right=people.size()-1;
        int boats=0;
        while(left<=right){
            if(people[left]+people[right]<=limit){
                left++;
            }
            boats++;
            right--;
        }
        return boats;
    }
};