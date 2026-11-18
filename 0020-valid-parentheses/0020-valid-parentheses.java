class Solution {
    public boolean isValid(String s) {
        //to craete a stack in java
        Stack<Character> st=new Stack<>();
        for(char ch:s.toCharArray()){
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            else{
                if(st.empty()){
                    return false;
                }
                char top=st.peek();
                if((ch==')' && top !='(')||
                (ch=='}' && top !='{')||
                (ch==']' && top!='[')){
                    return false;
                }
                st.pop();
            }
        }
        return st.isEmpty();
    }
}