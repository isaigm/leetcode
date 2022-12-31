// https://leetcode.com/problems/repeated-substring-pattern

class Solution {
    public boolean repeatedSubstringPattern(String s) {
          if(s.length() == 1) return false;
        ArrayDeque<Character> dq = new ArrayDeque<Character>();
        for(int i = 0; i < s.length(); i++){
            char ch = s.charAt(i);
            if(dq.contains(ch)){
                if(dq.getFirst() != ch) return false;
                dq.removeFirst();
            }else{
                dq.add(ch);
            }
        }
        return dq.isEmpty();
    }
}