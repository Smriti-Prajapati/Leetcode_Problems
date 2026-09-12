class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return false;
        }
        //make a map for frequency count
        map<int,int> freq;
        for(int card: hand){
            freq[card]++;
        }
        while(!freq.empty()){
            int start=freq.begin()->first;
            for(int i=0;i<groupSize;i++){
                int card= start+i;
                if(freq[card]==0)
                    return false;   //if card not present
                freq[card]--; //reduce the number of cards
                if(freq[card]==0){   //if earlier card was present and now its count is 0 so erase it  from the map.
                    freq.erase(card);
                }
            }
        }
        return true;
    }
};