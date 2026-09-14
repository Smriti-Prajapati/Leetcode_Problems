class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        //step 1.add the starting in stations
        stations.push_back({target,0});
        //step 2.create priority queue
        priority_queue<int> pq;
        long long fuel=startFuel;
        long long prev=0;
        int stops=0;
        for(auto station: stations){
            int position= station[0];
            int stationFuel=station[1];
            int distance= position- prev;
            fuel-=distance;
            while(fuel<0 && !pq.empty()){
                fuel+=pq.top();
                pq.pop();
                stops++;
            }
            if(fuel<0){
                return -1;
            }
            pq.push(stationFuel);
            prev= position;
        }
        return stops;
    }
};