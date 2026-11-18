class Solution {
    public int lengthOfLongestSubstring(String s) {
        int [] lastSeen=new int[256];
        Arrays.fill(lastSeen,-1);
        int left=0;
        int ans=0;
        for(int right=0;right<s.length();right++){
            char ch=s.charAt(right);
            if(lastSeen[ch]>=left){
                left=lastSeen[ch]+1;
            }
            lastSeen[ch]=right;
            ans=Math.max(ans,right-left+1);
        }
        return ans;
    }
}