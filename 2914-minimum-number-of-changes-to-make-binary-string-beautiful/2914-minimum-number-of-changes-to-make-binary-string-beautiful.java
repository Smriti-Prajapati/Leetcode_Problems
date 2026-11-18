class Solution {
    public int minChanges(String s) {
        //intialize variable changes
        int changes=0;
        //traverse with space of 2
        for(int i=0;i<s.length();i+=2){
            if(s.charAt(i)!=s.charAt(i+1)){
                //increment changes
                changes++;
            }
        }
        return changes;
    }
}