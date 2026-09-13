class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        //step 1.sort the courses in ascending order of deadline
        sort(courses.begin(),courses.end(),
        [](const vector<int>& a, vector<int>& b){
            return a[1]<b[1];
        });
        //step 2.create a max heap
        priority_queue<int> pq;
        int time=0;
        for(auto course: courses){
            int duration=course[0];
            int deadline=course[1];
            time+=duration;
            pq.push(duration);
            if(time>deadline){
                time-=pq.top(); //remove the largest timeline task
                pq.pop();
            }
        }
        return pq.size(); //number of courses we are taken will be returned as answer
    }
};