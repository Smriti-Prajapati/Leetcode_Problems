class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        //function to convert dated from string to integers
        auto convert=[&](string date){
            int month=stoi(date.substr(0,2));
            int day=stoi(date.substr(3,2));
            int total=day;
            for(int i=0;i<month-1;i++){
                total+=days[i];
            }
            return total;
        };
        int aStart=convert(arriveAlice);
        int aEnd=convert(leaveAlice);
        int bStart=convert(arriveBob);
        int bEnd=convert(leaveBob);
        int start=max(aStart,bStart);
        int end=min(aEnd,bEnd);
        if(start>end){
            return 0;
        }
        else{
            return end-start+1;
        }
    }
};