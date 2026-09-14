class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.push_back({target,0});
        priority_queue<int> pq;
        long long fuel= startFuel;
        long long prev=0;
        int stops=0;
        for(auto station: stations){
            long long position=station[0];
            long long stationFuel=station[1];
            long long distance= position-prev;
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