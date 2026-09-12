class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //step 1.count the tasks
        vector<int> freq(26,0);
        for(int task: tasks){
            freq[task-'A']++;
        }
        //step 2.find the maximum frequency
        int maxFreq=0;
        for(int f: freq){
            maxFreq= max(maxFreq,f);
        }
        //step 3.find how many tasks have that maximum frequency
        int numberOfMaxTasks=0;
        for(int f: freq){
            if(f==maxFreq){
                numberOfMaxTasks++;
            }
        }
        //step 4.apply the formula
        int formula= (maxFreq-1)*(n+1)+numberOfMaxTasks;
        return max((int)tasks.size(),formula);
    }
};